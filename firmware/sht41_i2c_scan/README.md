# ESP32-S3 SHT41 + BH1750 + SPS30 reader

PlatformIO project for reading an SHT41 temperature/humidity sensor, a BH1750 light sensor, and an SPS30 particulate-matter sensor on the same I2C bus. Readings are printed every 30 seconds.

## Wiring

All three sensors share the ESP32 I2C pins:

- SDA to ESP32 GPIO 8
- SCL to ESP32 GPIO 9
- Grounds connected together

BH1750:

- VCC (red) to ESP32 3V3
- GND to ESP32 GND
- SCL (brown) to ESP32 GPIO 9
- SDA (white) to ESP32 GPIO 8
- ADDR to GND for I2C address `0x23`

SHT41:

- VIN to ESP32 3V3
- GND to ESP32 GND

SPS30:

- VDD (red) to ESP32 5V
- SDA (green) to ESP32 GPIO 8
- SCL (yellow) to ESP32 GPIO 9
- SEL (blue) to GND to select I2C mode
- GND (black) to ESP32 GND

The SPS30 requires a 5V supply.

## Build, upload, and monitor

Open a terminal in this project folder, connect the ESP32-S3 by USB-C, then run:

```sh
pio run
pio run --target upload
pio device monitor
```

The monitor runs at 115200 baud, as configured in `platformio.ini`. In VS Code, the equivalent actions are **PlatformIO: Build**, **PlatformIO: Upload**, and **PlatformIO: Monitor**.

The project uses Arduino `Wire`, so no extra PlatformIO library dependency is needed. The BH1750 is read at address `0x23`; the SHT4x address is normally `0x44` (some breakouts use `0x45`); and the SPS30 address is `0x69`. SPS30 CRCs are checked before displaying PM1.0, PM2.5, PM4.0, and PM10 concentrations in ug/m3.
