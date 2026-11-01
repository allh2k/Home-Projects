#include <Arduino.h>
#include <Wire.h>
#include <cstring>

constexpr int SDA_PIN = 8;
constexpr int SCL_PIN = 9;
constexpr uint8_t SHT4X_ADDRESS_1 = 0x44;
constexpr uint8_t SHT4X_ADDRESS_2 = 0x45;
constexpr uint8_t SPS30_ADDRESS = 0x69;
constexpr size_t SPS30_FLOAT_DATA_LENGTH = 60;

uint8_t sensorAddress = 0;
bool sps30Started = false;

void printBoth(const char *message) {
  Serial.println(message);  // Native USB CDC
  Serial0.println(message); // UART0 / USB-to-UART bridge
}

uint8_t findSht4x() {
  uint8_t foundAddress = 0;

  printBoth("Scanning I2C addresses...");
  for (uint8_t address = 1; address < 127; ++address) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      char message[48];
      snprintf(message, sizeof(message), "Found I2C device at 0x%02X", address);
      printBoth(message);

      if (address == SHT4X_ADDRESS_1 || address == SHT4X_ADDRESS_2) {
        foundAddress = address;
      }
    }
  }

  if (foundAddress == 0) {
    printBoth("No SHT4x address found yet.");
  } else {
    char message[48];
    snprintf(message, sizeof(message), "SHT4x detected at 0x%02X", foundAddress);
    printBoth(message);
  }

  return foundAddress;
}

uint8_t crc8(const uint8_t *data, size_t length) {
  uint8_t crc = 0xFF;
  for (size_t i = 0; i < length; ++i) {
    crc ^= data[i];
    for (uint8_t bit = 0; bit < 8; ++bit) {
      crc = (crc & 0x80) ? static_cast<uint8_t>((crc << 1) ^ 0x31)
                         : static_cast<uint8_t>(crc << 1);
    }
  }
  return crc;
}

bool i2cDevicePresent(uint8_t address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission() == 0;
}

bool startSps30Measurement() {
  // Pointer 0x0010, float output format, dummy byte, then CRC of the data pair.
  const uint8_t formatData[2] = {0x03, 0x00};
  const uint8_t commandData[3] = {formatData[0], formatData[1],
                                  crc8(formatData, sizeof(formatData))};
  Wire.beginTransmission(SPS30_ADDRESS);
  Wire.write(0x00);
  Wire.write(0x10);
  Wire.write(commandData, sizeof(commandData));
  if (Wire.endTransmission() != 0) {
    printBoth("SPS30 start-measurement command failed.");
    return false;
  }

  printBoth("SPS30 measurement started.");
  return true;
}

bool readSps30(float (&measurements)[10]) {
  uint8_t data[SPS30_FLOAT_DATA_LENGTH];

  Wire.beginTransmission(SPS30_ADDRESS);
  Wire.write(0x03); // Read Measured Values pointer, 0x0300
  Wire.write(0x00);
  if (Wire.endTransmission(false) != 0) {
    printBoth("SPS30 could not set the measurement-data pointer.");
    return false;
  }

  const size_t received = Wire.requestFrom(
      SPS30_ADDRESS, SPS30_FLOAT_DATA_LENGTH, true);
  if (received != SPS30_FLOAT_DATA_LENGTH) {
    char message[64];
    snprintf(message, sizeof(message), "SPS30 returned %u of 60 bytes.",
             static_cast<unsigned>(received));
    printBoth(message);
    while (Wire.available()) {
      Wire.read();
    }
    return false;
  }

  for (size_t i = 0; i < SPS30_FLOAT_DATA_LENGTH; ++i) {
    data[i] = static_cast<uint8_t>(Wire.read());
  }

  // SPS30 inserts a CRC byte after each pair of measurement bytes.
  for (size_t value = 0; value < 10; ++value) {
    const size_t offset = value * 6;
    if (crc8(data + offset, 2) != data[offset + 2] ||
        crc8(data + offset + 3, 2) != data[offset + 5]) {
      printBoth("SPS30 data CRC check failed.");
      return false;
    }

    const uint32_t raw = (static_cast<uint32_t>(data[offset]) << 24) |
                         (static_cast<uint32_t>(data[offset + 1]) << 16) |
                         (static_cast<uint32_t>(data[offset + 3]) << 8) |
                         static_cast<uint32_t>(data[offset + 4]);
    std::memcpy(&measurements[value], &raw, sizeof(raw));
  }

  return true;
}

bool readSht4x(float &temperatureC, float &relativeHumidity) {
  Wire.beginTransmission(sensorAddress);
  Wire.write(0xFD); // High precision temperature and humidity measurement
  if (Wire.endTransmission() != 0) {
    printBoth("SHT4x did not acknowledge the measurement command.");
    return false;
  }

  delay(10);
  if (Wire.requestFrom(sensorAddress, static_cast<uint8_t>(6)) != 6) {
    printBoth("SHT4x returned fewer than 6 data bytes.");
    while (Wire.available()) {
      Wire.read();
    }
    return false;
  }

  uint8_t data[6];
  for (uint8_t i = 0; i < 6; ++i) {
    data[i] = static_cast<uint8_t>(Wire.read());
  }

  if (crc8(data, 2) != data[2] || crc8(data + 3, 2) != data[5]) {
    printBoth("SHT4x data CRC check failed.");
    return false;
  }

  const uint16_t rawTemperature = (static_cast<uint16_t>(data[0]) << 8) | data[1];
  const uint16_t rawHumidity = (static_cast<uint16_t>(data[3]) << 8) | data[4];

  temperatureC = -45.0f + (175.0f * rawTemperature / 65535.0f);
  relativeHumidity = -6.0f + (125.0f * rawHumidity / 65535.0f);
  relativeHumidity = constrain(relativeHumidity, 0.0f, 100.0f);
  return true;
}

void setup() {
  Serial.begin(115200);
  Serial0.begin(115200);
  delay(1000);

  printBoth("");
  printBoth("ESP32-S3 SHT41 + SPS30 reader");
  char pinMessage[48];
  snprintf(pinMessage, sizeof(pinMessage), "SDA: GPIO %d, SCL: GPIO %d", SDA_PIN, SCL_PIN);
  printBoth(pinMessage);

  if (!Wire.begin(SDA_PIN, SCL_PIN, 100000)) {
    printBoth("Could not start I2C. Check the selected GPIO pins.");
    while (true) {
      delay(1000);
    }
  }

  sensorAddress = findSht4x();

  if (i2cDevicePresent(SPS30_ADDRESS)) {
    printBoth("SPS30 detected at 0x69.");
    sps30Started = startSps30Measurement();
    if (sps30Started) {
      delay(1000); // The SPS30 produces a new measurement about once per second.
    }
  } else {
    printBoth("SPS30 not detected at 0x69. Check its power, SEL, SDA and SCL.");
  }
}

void loop() {
  if (sensorAddress == 0) {
    sensorAddress = findSht4x();
  }

  if (sensorAddress != 0) {
    float temperatureC = 0.0f;
    float relativeHumidity = 0.0f;
    if (readSht4x(temperatureC, relativeHumidity)) {
      char message[80];
      snprintf(message, sizeof(message), "Temperature: %.2f C, humidity: %.2f %%",
               temperatureC, relativeHumidity);
      printBoth(message);
    }
  }

  if (!sps30Started && i2cDevicePresent(SPS30_ADDRESS)) {
    printBoth("SPS30 detected at 0x69.");
    sps30Started = startSps30Measurement();
  }

  if (sps30Started) {
    float measurements[10] = {};
    if (readSps30(measurements)) {
      char message[128];
      snprintf(message, sizeof(message),
               "SPS30 PM1.0: %.2f, PM2.5: %.2f, PM4.0: %.2f, PM10: %.2f ug/m3",
               measurements[0], measurements[1], measurements[2], measurements[3]);
      printBoth(message);
    }
  }

  delay(3000);
}
