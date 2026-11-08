# First-prototype shopping list

**Scope:** one no-display indoor room-node prototype and removable enclosure mock-up. Prices in the original component table are a UK snapshot checked on 4 October 2026; retailer stock and prices can change. The user's current Pi Hut cart is a proposed prototype purchase, not confirmed as ordered or received. This is not a bulk order list for the 11 indoor rooms or outbuildings.

**Selected substitutions:** the parts already bought are an ESP32-S3 Dev Kit marked N16R8 and an SHT41 breakout. The linked ESP32-S3-DevKitC-1 and SHT40 SEN0428 below are example options from the original basket, not required models or the actual purchased parts. Their listed prices are not the spend for the selected hardware; record exact seller/model and actual price when available.

## Current status and remaining purchases (8 November 2026)

- **Working on the bench:** the ESP32-S3 Dev Kit N16R8 and SHT41 work over USB, with the readings reaching Home Assistant over Wi-Fi.
- **SPS30 power and readings confirmed:** a 5 V boost converter and fuse are powering the SPS30, and it is returning readings. Four AA cells are on hand; the SPS30 test used a two-cell supply. The ESP32 is still powered by USB, so the complete node has not yet been proven on batteries.
- **Power direction:** the user is considering two 18650 cells with the Pi Hut/DFRobot 2-way holder for a Li-ion bench prototype. The holder advertises USB charging, overcharge/over-discharge and reverse-cell-polarity protection, plus 5 V/2 A and 3.3 V/1 A outputs; cells are separate and listed as unprotected. Verify short-circuit/overcurrent behavior rather than assuming all BMS protections. The user wants an integrated charging/protection/dual-rail board in the final product. Small converters such as the Pololu S7V8F3 remain prototype modules; they are not confirmed final-product parts. Do not connect two 3.3 V sources to the same ESP32 rail.
- **Earlier AA prototype parts:** an order record dated 1 November lists an AA holder assortment, two MT3608 5 V boost modules, five small 3.3 V modules, three I²C level shifters, a USB-C bench supply/cable, and inline fuse holders/fuses. The fused 5 V booster is now powering the SPS30 successfully. Keep these as bench/prototype inventory; exact module used for the successful test and remaining quantities should be checked before ordering duplicates.
- **Motion sensors:** noted for 21 November 2026. Check the order/arrival then; no duplicate purchase is needed if these are already on the way.
- **Ambient-light sensors:** now bought, per the latest update. Confirm the exact model and quantity before wiring; BH1750 is the recommended choice if that is what was purchased.
- **Check before ordering:** confirm the exact quantities in the cart and whether the Pi Hut holder, two matching cells, Pololu regulator(s), and level shifter are all needed for the prototype. The holder already provides 3.3 V and 5 V, so the Pololu regulator is not required when using those outputs; keep it only if you want a separate converter test. Confirm the AA holder, external NiMH charger, fuse holder/lead rating, SPS30 cable, and I²C level shifter are already in hand before buying duplicates. The NiMH charger cannot charge Li-ion cells.
- **Battery cell note:** the Pi Hut 2500 mAh 18650 listing labels the cells unprotected and restricts shipping to England/Wales. The DFRobot holder advertises overcharge/over-discharge and reverse-polarity protection, but check its documentation for the protection features and limits you need. Use two identical cells from the same source/model.
- **Before unattended battery use:** for the AA converter setup, add suitable reverse-polarity protection and a conservative low-voltage cutoff, and confirm a safe way to switch the 5 V converter/SPS30 between measurements. A fuse does not provide those functions. Charge NiMH cells in a compatible external charger, never in the node. For Li-ion, verify the holder's stated protection and operating limits; do not assume it provides every required fault protection.
- **Airflow:** use the SPS30's internal fan for its particle-sampling path while testing the enclosure vents. It is not a general enclosure-circulation fan; keep its outlet from recirculating into its inlet and keep the SHT41 in a separate passive-air nook. No extra fan is needed for this test.
- **RF:** no receiver/transmitter is needed yet; identify the actual remotes before buying radio hardware.
- **AA runtime scale:** the two-cell AA pack uses cells marked 2800 mAh at 2.4 V nominal (about 6.72 Wh by label). The SPS30 alone uses about 0.275 W while measuring; continuous operation would consume that nominal energy in about 24 hours before converter losses and ESP32 load. Measure actual runtime with the chosen schedule.
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

**Original USB-bench parts subtotal:** about **£83.08**, including the cable line. This is the 4 October sensor-prototype snapshot; it excludes the later battery-power prototype parts and is not the final power design. The listed USB supply is optional for bench debugging only.

### Recommended ambient-light sensor

The BH1750 is the recommended ambient-light sensor for the indoor prototype.

### Motion-sensor trial (date noted: 21 November 2026)

| Part | Qty | Snapshot price | Source and notes |
| --- | ---: | ---: | --- |
| Mini PIR motion sensor | 1 | £3.50 | Example option only: [The Pi Hut](https://thepihut.com/products/breadboard-friendly-mini-pir-motion-sensor-with-3-pin-header). Motion sensors are noted for 21 November; check the arriving model before buying this example. It accepts 3–12 V and has a 3.3 V signal output; test whether pets trigger it. A PIR detects movement, not someone sitting still. |

Use one spare ESP32 GPIO for its output and expose it in ESPHome as a GPIO binary sensor with the `motion` device class. A PIR needs a room-facing lens opening; wood in front of the lens will block its view. For detecting a person who remains still, consider a radar presence module instead, such as the LD2410C or LD2420, but do not buy both for the first trial. The LD2410C exposes separate moving and still targets over UART; the LD2420 is a 3.3 V UART option with its own ESPHome integration.

## Electrical compatibility notes

The ESP32-S3 GPIO is a 3.3 V interface. The ESPHome SPS30 instructions show I2C pull-ups on the sensor's 5 V supply side, so do not connect the SPS30 I2C lines directly to ESP32 pins. Use the listed bidirectional I2C converter: ESP side at 3.3 V, sensor side at 5 V, with a common ground. Keep the SHT41 on the 3.3 V side. Check module markings and the latest wiring documentation before powering anything.

The SPS30 connector is a 5-pin JST-ZHR/ZH, 1.5 mm pitch. Its SEL pin must be grounded to select I2C. Follow the sensor pinout rather than relying on wire colours. Keep its metal shield electrically floating unless the manufacturer’s potential-equalization guidance is followed.

Use a suitable short cable between the SPS30 and ESP32 for I2C. If the sensor must be more than 20 cm away, review the manufacturer’s UART recommendation and the current ESPHome support before purchasing or routing a longer cable.

## Enclosure mock-up

The next purchase is sheet wood/material for a removable mock-up, not finished production wood. User-supplied Gemini concept photos show a light-wood case, two white front sensor domes, a right-side battery/service hatch, three status LEDs, and a perforated lower-front vent section. The images are visual references, not verified mechanical drawings.

Start with a **150 mm wide × 180 mm high front face**, and compare **40 mm and 50 mm external depth** with the **80 mm** depth shown in the concept image. These are alternatives to test, not a decided size. With 6 mm walls, the clear depth is only about 28 mm at 40 mm external and 38 mm at 50 mm, before back panel, hatch, mounting, cables, and clearances. The 40 mm option may not fit the actual 18650 holder and battery assembly; lay out the real parts first. A 50 mm mock-up is the more informative initial build, with a second slimmer depth if parts allow. Keep the full-size mock-up easy to modify.

The concept image suggests sensor domes about 40 mm below the top, three side LEDs near the top and away from the light sensor, a side hatch near the top, and lower-front vents starting about 20 mm above the base and extending about 40 mm high, with roughly 10 mm side margins. Treat those positions as provisional and check the vent area against SPS30 inlet/outlet placement. The image labels are not dimensionally consistent enough to cut production parts from.

Before cutting, lay out the actual cells/holder, ESP32 board, integrated or prototype power electronics, SPS30 and its cable, divider, vents, hatch, and wire bends. Preserve airflow around the SPS30 and keep its exhaust from recirculating into its inlet or into the SHT41 nook.

Use separate openings for:

1. The SPS30's own two air inlets and outlet. Keep its outlet from recirculating into an inlet.
2. Passive left-to-right room-air vents for the SHT40 nook.
3. A room-facing aperture for any presence sensor.

Do not install an extra little fan in the temperature/humidity nook. The SPS30 contains its own sampling fan; use it to test the SPS30's inlet/outlet path, but do not assume it circulates air through the whole enclosure. Keep the sampling airflow out of the SHT41 path.

## Defer these purchases

- Additional lithium-ion cells or charger modules beyond the prototype setup, and any alarm-wire charging parts.
- Extra 5 V fan.
- 433 MHz receiver or transmitter: survey the actual remotes first.
- Relays, window/curtain motors, displays, cameras, or parts for all rooms.
- Finished wood, permanent mounting hardware, and a finished vent grille: decide dimensions after the component mock-up. The mock-up sheet material is the next purchase.

Prototype power remains open between the existing AA test setup and a two-18650 Li-ion holder. Measure the complete device before setting a runtime target. Keep chemistries and chargers separate. The final product direction is an integrated board with appropriate Li-ion charging/protection and regulated 5 V and 3.3 V rails; validate it after the bench prototype and enclosure fit checks.

## Technical references

- [Espressif ESP32-S3-DevKitC-1 guide and dimension files](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/user_guide_v1.0.html)
- [ESPHome SPS30 integration and idle sampling behavior](https://esphome.io/components/sensor/sps30/)
- [ESPHome BH1750 ambient-light sensor](https://esphome.io/components/sensor/bh1750/)
- [Sensirion SPS30 datasheet](https://sensirion.com/file/datasheet_sps30)
- [Sensirion SPS30 mechanical design guide](https://sensirion.com/en/media/documents/7990F04A/616544B0/Sensirion_Particulate_Matter_AppNotes_SPS30_Mechanical_Design_and_As.pdf)
- [Espressif ESP32-S3 electrical characteristics](https://documentation.espressif.com/esp32_s3_datasheet_en.pdf)
- [ESPHome LD2410 integration](https://esphome.io/components/sensor/ld2410/)
- [Sensirion SHT40 specifications](https://sensirion.com/products/catalog/SHT40)
