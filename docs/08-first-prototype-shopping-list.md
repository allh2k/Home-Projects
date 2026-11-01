# First-prototype shopping list

**Scope:** one no-display indoor room-node prototype for the bench. Prices are a UK snapshot checked on 4 October 2026, include VAT where the retailer states that, and exclude delivery. Stock and prices can change. This is a one-off prototype list, not a bulk order list for the 11 indoor rooms or outbuildings.

**Selected substitutions:** the parts already bought are an ESP32-S3 Dev Kit marked N16R8 and an SHT41 breakout. The linked ESP32-S3-DevKitC-1 and SHT40 SEN0428 below are example options from the original basket, not required models or the actual purchased parts. Their listed prices are not the spend for the selected hardware; record exact seller/model and actual price when available.

## Current status and order queue (1 November 2026)

- **Already owned and working:** ESP32-S3 Dev Kit N16R8 and SHT41. The sensor reports over Wi-Fi to Home Assistant and has been very accurate in the user's checks.
- **Battery cells on hand:** HiQuick NiMH AA cells marked 1.2 V / 2800 mAh. Use two matched cells in series for about 2.4 V nominal and 6.72 Wh nominal by label; measure actual runtime/capacity under the node load.
- **Order next:** one replacement Sensirion SPS30. The first unit is not working and may have been damaged in the smoke incident.
- **Order with it:** one I2C level-shifter board with clearly exposed `GND`, `LV`, and `HV` pins (and the signal channels). Use one common ground between ESP32, level shifter, and SPS30; keep the SHT41 on the 3.3 V side. Confirm the board's pin labels and wiring before powering it.
- **Battery power parts to specify:** a 2-cell AA series holder with switch, polarity protection, and short-circuit protection sized for converter peaks; a low-quiescent-current 3.3 V boost regulator with input range covering the two-cell NiMH pack and at least 500 mA output plus transient margin; and a separate 5 V boost regulator for the SPS30, with enable/load switching and at least 200 mA output headroom. Power 3.3 V peripherals directly from the regulated 3.3 V bus, in parallel with the ESP32, not through its 3V3 output. Use a conservative pack cutoff and common ground.
- The working sensor board is recorded as an ESP32-S3 Dev Kit N16R8, but the user has not confirmed whether the cheap board with the faulty 5 V rail is the same model. Confirm that board's allowed external input pin and all 5 V loads before selecting or ordering regulator modules. Do not charge cells in the node; charge them in a NiMH charger matched to the cells.
- **Runtime scale:** the two-cell pack is marked 2800 mAh at 2.4 V nominal (about 6.72 Wh on the label). The SPS30 alone uses about 0.275 W while measuring; continuous operation would consume the label's nominal energy in about 24 hours before converter losses and ESP32 load. Duty-cycle the sensor if the measured runtime target requires it.
- **Storage watch:** the server has about 460 GB total internal storage; check the actual free space. First check the motherboard and spare connectors. Amazon UK's live price index listed a Crucial BX500 2 TB 2.5-inch SATA SSD at about **£100 on 1 November**. Treat this as a snapshot, confirm seller/condition/price, and buy only if the server has a spare SATA data/power connection and drive bay. If using M.2 instead, confirm the exact slot protocol and size first. Since Black Friday is 27 November, wait for a sale if the current drive has enough headroom; buy one sooner only if storage is already blocking work. One 2 TB drive is a bridge, not the future NAS/camera-storage array.
- **Defer bulk NAS disks** until the storage layout and backup plan are designed and market pricing/availability is revisited. Do not buy several drives for an unplanned array.

Amazon UK price reference: [daily 2 TB Amazon UK drive index](https://www.disks.co.uk/2tb). The index's prices are a point-in-time comparison, not a promise that a listing is an appropriate Proxmox drive. Black Friday 2026 falls on 27 November; Amazon UK's exact sale window should be checked when announced.

**Weather station watch (not yet selected):** the Ecowitt GW2001/Wittboy bundle with UK/EU 868 MHz radio is the simplest local-HA candidate; recent UK price checks put it around **£209** ([PriceSpy listing](https://pricespy.co.uk/product.php?p=15443077)). Its WS90 sensor has an optional 12 V/1 A waterproof extension cable that can power the whole array, avoiding reliance on high-up AA cells; confirm that cable is available and included or add it separately. The IQtronic IQWS-4000 is a wired-LAN/12 V passive-PoE alternative listed at **€190** by the manufacturer, but requires the correct non-standard passive-power adapter and custom Home Assistant REST sensors. Choose after surveying the mounting and cable routes; do not bulk-buy outdoor nodes before deciding the locations and power design.

## One-prototype parts

| Part | Qty | Snapshot price | Source and notes |
| --- | ---: | ---: | --- |
| Espressif ESP32-S3-DevKitC-1 | 1 | £28.90 | [The Pi Hut](https://thepihut.com/collections/espressif/products/esp32-s3-devkitc-1-development-board). Listing showed in stock. The listed revision uses Micro-USB; check the exact item before choosing a cable. |
| DFRobot Fermion SHT40 breakout, SEN0428 | 1 | £6.74 | [DigiKey UK](https://www.digikey.co.uk/en/products/detail/dfrobot/SEN0428/15848087). Listing showed 15 available. It has 3.3–5 V input; power it from the ESP32 3.3 V rail for the first prototype. |
| Sensirion SPS30 PM sensor | 1 | £32.30 | [RS UK](https://uk.rs-online.com/web/p/environmental-sensor-ics/1862540). Measures PM1, PM2.5, PM4 and PM10; 41 × 41 × 12 mm; 4.5–5.5 V; typical measurement current 55 mA, with a short fan-start peak up to 80 mA. |
| Matching 5-pin JST-ZH 1.5 mm cable | 1 | £0.80 reference | Already owned. Check that it mates with the SPS30 connector and verify pin order against the datasheet; wire colours can vary. [Backup source](https://thepihut.com/products/jst-zh-cable-5-pin-1-5mm-pitch). |
| 4-channel BSS138 bidirectional I2C level converter | 1 | £3.84 | [SK Pang](https://www.skpang.co.uk/products/4-channel-i2c-safe-bi-directional-logic-level-converter-bss138). Keeps the SPS30's 5 V side separate from the ESP32's 3.3 V GPIO side. Header pins may need soldering. |
| Half-size breadboard | 1 | £3.00 | [The Pi Hut](https://thepihut.com/products/half-size-breadboard-white). |
| Dupont jumper-wire set | 1 | £6.00 | [The Pi Hut, 120-piece set](https://thepihut.com/products/thepihuts-jumper-bumper-pack-120pcs-dupont-wire). |
| Micro-USB data cable | 1 | £1.50 | [The Pi Hut](https://thepihut.com/products/usb-to-micro-usb-cable-0-5m), only if you do not already have one. Make sure it supports data as well as power. |

**Original USB-bench parts subtotal:** about **£83.08**, including the cable line. This is the 4 October sensor-prototype snapshot; it excludes the newly selected AA power system and is not the final power design. The listed USB supply is optional for bench debugging only.

### Optional motion-sensor trial

| Part | Qty | Snapshot price | Source and notes |
| --- | ---: | ---: | --- |
| Mini PIR motion sensor | 1 | £3.50 | [The Pi Hut](https://thepihut.com/products/breadboard-friendly-mini-pir-motion-sensor-with-3-pin-header). First motion trial: it fits a breadboard, accepts 3–12 V, and has a 3.3 V signal output. Test whether pets trigger it. It detects changes/movement, not someone sitting still. |

Use one spare ESP32 GPIO for its output and expose it in ESPHome as a GPIO binary sensor with the `motion` device class. A PIR needs a room-facing lens opening; wood in front of the lens will block its view. For detecting a person who remains still, consider a radar presence module instead, such as the LD2410C or LD2420, but do not buy both for the first trial. The LD2410C exposes separate moving and still targets over UART; the LD2420 is a 3.3 V UART option with its own ESPHome integration.

## Electrical compatibility notes

The ESP32-S3 GPIO is a 3.3 V interface. The ESPHome SPS30 instructions show I2C pull-ups on the sensor's 5 V supply side, so do not connect the SPS30 I2C lines directly to ESP32 pins. Use the listed bidirectional I2C converter: ESP side at 3.3 V, sensor side at 5 V, with a common ground. Keep the SHT41 on the 3.3 V side. Check module markings and the latest wiring documentation before powering anything.

The SPS30 connector is a 5-pin JST-ZHR/ZH, 1.5 mm pitch. Its SEL pin must be grounded to select I2C. Follow the sensor pinout rather than relying on wire colours. Keep its metal shield electrically floating unless the manufacturer’s potential-equalization guidance is followed.

Use a suitable short cable between the SPS30 and ESP32 for I2C. If the sensor must be more than 20 cm away, review the manufacturer’s UART recommendation and the current ESPHome support before purchasing or routing a longer cable.

## Enclosure mock-up

Do not order or cut the finished wood box yet. First make a removable mock-up at about **180 × 150 × 80 mm external**. With 6 mm panels, the approximate clear interior is **168 × 138 × 68 mm** before the divider and mounting pieces. Leave about 50 mm clear height in the lower bay for the 41 mm square SPS30 and airflow clearance; the upper bay must fit the ESP32, removable two-AA holder, and both regulator modules with service access.

Use separate openings for:

1. The SPS30's own two air inlets and outlet. Keep its outlet from recirculating into an inlet.
2. Passive left-to-right room-air vents for the SHT40 nook.
3. A room-facing aperture for any presence sensor.

Do not install an extra little fan in the temperature/humidity nook. The SPS30 contains its own sampling fan. Keep that sampling airflow out of the SHT40 path.

## Defer these purchases

- Lithium-ion cells or charger modules, or any alarm-wire charging parts.
- Extra 5 V fan.
- 433 MHz receiver or transmitter: survey the actual remotes first.
- Relays, window/curtain motors, displays, cameras, or parts for all rooms.
- Permanent wood, mounting hardware, or a finished vent grille: decide their dimensions after the component mock-up.

The next prototype uses two removable AA NiMH cells with separate regulated 3.3 V and switched 5 V rails. Measure the complete device before setting a runtime target. Cells are removed for charging in a compatible external NiMH charger.

## Technical references

- [Espressif ESP32-S3-DevKitC-1 guide and dimension files](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/user_guide_v1.0.html)
- [ESPHome SPS30 integration and idle sampling behavior](https://esphome.io/components/sensor/sps30/)
- [Sensirion SPS30 datasheet](https://sensirion.com/file/datasheet_sps30)
- [Sensirion SPS30 mechanical design guide](https://sensirion.com/en/media/documents/7990F04A/616544B0/Sensirion_Particulate_Matter_AppNotes_SPS30_Mechanical_Design_and_As.pdf)
- [Espressif ESP32-S3 electrical characteristics](https://documentation.espressif.com/esp32_s3_datasheet_en.pdf)
- [ESPHome LD2410 integration](https://esphome.io/components/sensor/ld2410/)
- [Sensirion SHT40 specifications](https://sensirion.com/products/catalog/SHT40)
