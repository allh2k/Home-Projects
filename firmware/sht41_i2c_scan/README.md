# ESP32-S3 SHT41 + SPS30 reader

PlatformIO project for reading an SHT41 temperature/humidity sensor and an SPS30 particulate-matter sensor on the same I2C bus. Readings are printed every three seconds.

## Wiring

Both sensors share the ESP32 I2C pins:

- SDA to ESP32 GPIO 8
- SCL to ESP32 GPIO 9
- Grounds connected together

SHT41:

- VIN to ESP32 3V3
- GND to ESP32 GND

SPS30:

- VDD (red) to ESP32 5V
- SDA (green) to ESP32 GPIO 8
- SCL (yellow) to ESP32 GPIO 9
- SEL (blue) to GND to select I2C mode
- GND (black) to ESP32 GND

The SPS30 requires a 5V supply. The I2C address is `0x69`; the SHT4x address is normally `0x44` (some breakouts use `0x45`).

## Run in VS Code

1. Open this folder as the PlatformIO project.
2. Connect the ESP32-S3 by USB-C.
3. Use **PlatformIO: Build** and then **PlatformIO: Upload**.
4. Open **PlatformIO: Monitor** at 115200 baud.

The project uses Arduino `Wire` for both sensors, so no extra PlatformIO library dependency is needed. SPS30 CRCs are checked before displaying PM1.0, PM2.5, PM4.0, and PM10 concentrations in ug/m3.
