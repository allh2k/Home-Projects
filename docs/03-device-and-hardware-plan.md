# Device and hardware plan

This is a shortlist of device types and questions, not a shopping list. Confirm the house survey, software support, exact board revision, dimensions, power, and sensor placement before purchasing parts in quantity.

## Room device options

| Device type | Possible functions | Selection notes |
| --- | --- | --- |
| Basic room sensor | Temperature, humidity, motion/presence | Best first installed device after the desk prototype. One board may serve more than one sensor if its pins and enclosure allow it. |
| Indoor air-quality sensor | PM2.5 and PM10; optionally a separate CO2 or VOC sensor | Particle measurement needs an inlet/outlet and airflow. Check fan noise, warm-up, duty cycle, dimensions, and current draw. |
| Remote-control node | Receive or transmit a known remote protocol | Identify make/model and radio type first. Check whether the protocol is supported and whether device state can be confirmed. |
| Front-door panel | Greeting, doorbell status, household information | Decide screen size, mounting, power, and whether a camera or intercom is really needed. |
| Kitchen panel | Shared to-do list, timers, weather, household status | A browser-capable display may fit better than a tiny microcontroller display. |
| Camera | Video capture and recording | Prefer a purpose-built, appropriately rated network camera. Decide location, power, retention, and access before installation. |
| Outdoor station | Temperature, humidity, wind, rain, possibly air quality | Needs weather-rated enclosure, suitable exposure, mounting, and maintenance access. |
| Future motor controller | Window or curtain motor, limits, position, manual override | Requires a separate safety and power design before parts are selected. |

## Outdoor weather station and distributed readings

Keep the full weather station and the three local temperature/humidity points as separate requirements. A wind/rain station belongs in one suitable open-sky position; it cannot measure front, rear, and greenhouse microclimates from one point. If those microclimates matter, add separate ESPHome nodes at each position, preferably wired/PoE where cable access makes that practical. The existing SHT41 is a good sensor candidate, but the breakout is not weatherproof: outdoor nodes need a ventilated radiation shield and a moisture/condensation-safe enclosure.

| Candidate | Home Assistant path | Power/network | Fit and caveats |
| --- | --- | --- | --- |
| **Ecowitt WS90 + GW2000 (GW2001 bundle)** | Official Home Assistant Ecowitt integration; local custom upload from the gateway to HA. WS90 and GW2000 are supported. | WS90 communicates by radio (buy the UK/EU 868 MHz version); it can use solar with AA backup or an optional 12 V/1 A external supply and weatherproof extension cable that can power the whole sensor. The gateway can use Ethernet or Wi-Fi but needs separate power. | Easiest local HA route for wind/rain/UV/light and outdoor temperature/humidity. It has no Ethernet/PoE data port at the array, but the documented 12 V cable offers a way to avoid high-up battery changes. Confirm the exact extension cable and installation route. Current UK price checks put the bundle around £209. |
| **IQtronic IQWS-4000** | Local web/XML/HTTP data can be read by Home Assistant REST sensors; this requires custom entity configuration rather than the built-in Ecowitt flow. | Ethernet and 12 V **passive** PoE; it is not IEEE 802.3af/at PoE. Use only its specified injector/splitter. | Closest match to a permanently wired high mount. Manufacturer lists IP66, but the Ethernet junction must be sealed and exposed/elevated installations require surge protection. Do not connect it to a standard IEEE PoE switch; use the specified passive-power equipment. Manufacturer lists €190; confirm current UK availability and price before considering it. |

The first short list is therefore: choose Ecowitt if simple, well-supported local HA data is the priority; its optional 12 V cable can avoid relying on the AA cells, but the station still sends data to its gateway by radio. Choose a wired LAN station only if its exact supply standard, local data interface, weatherproofing, surge protection, price, and maintenance are acceptable. Do not assume the term “PoE” means IEEE-standard PoE.

For the front, rear, and greenhouse, survey the desired measurements and whether network cable/power already reaches each point. Start with temperature/humidity nodes (SHT41 + ESPHome), then add soil/moisture or other sensors only where there is a use. Place outdoor temperature sensors in a radiation shield away from walls, direct sun, exhausts, and window/door heat. A greenhouse needs a sensor/enclosure rated for its actual humidity and summer heat.

### Heating weather compensation

An outdoor temperature value in Home Assistant is useful for monitoring and automation, but does not automatically replace the external probe or controller used by a boiler/heat-pump weather-compensation system. Record the heating appliance and controller make/model, then check the manufacturer's supported sensor/interface. Keep the native compensation controls in service unless the equipment manufacturer explicitly supports another input path.

### Doorbell and new-door prewire

Doorbell model is still undecided, and installation waits for the new door. A current PoE candidate is the Reolink Video Doorbell PoE: it has an Ethernet/PoE connection and a Home Assistant Reolink integration. Reolink uses its own chime ecosystem; verify whether that fits the desired audible chime before buying. The exact model/manual remains the authority for power and chime wiring.

Before the frame/wall is closed, plan the route to the doorbell position on the fixed wall or frame beside the door (not through the moving door leaf):

- The door leaf does not need a special thickness for doorbell wiring. Leave a flat, protected mounting spot beside the door and bring the cables through the fixed jamb/wall; keep the route clear of hinges, locks, and weather seals.
- One solid-copper Cat6 home run (all four pairs/eight conductors, standard termination) back to the network switch/NVR area. Use a cable suitable for its installed route; use UV/weather-rated cable or protected conduit where exposed. Avoid CCA cable. A second Cat6 as a spare is inexpensive during door work.
- One separate two-core low-voltage bell cable to the intended indoor chime/transformer position for future options. A provisional 0.75–1.0 mm² copper pair is a sensible prewire allowance, but final size and voltage depend on the chosen doorbell, chime, supply voltage, and cable length. Keep it disconnected until the model and supply are confirmed.
- Provide a short protected entry/exit route, slack for terminating the device, and a conduit/pull string or accessible spare path. Do not put mains voltage on Ethernet or bell cable.

For a PoE video doorbell, Ethernet has eight conductors and carries network and supported PoE power; the separate pair is for chime/transformer flexibility, not required for PoE. Standard Cat6 Ethernet is far more reliable than relying on Wi-Fi at the entrance.

Official references: [Home Assistant Ecowitt integration](https://www.home-assistant.io/integrations/ecowitt/), [Ecowitt WS90 manual](https://oss.ecowitt.net/uploads/20251226/WS90%20Manual.pdf), [IQtronic IQWS-4000 product](https://www.iqtronic.com/products-category/weather/), [IQWS-4000 manual](https://www.iqtronic.com/wp-content/uploads/2023/03/IQWS4000_manual_en.pdf), [Teco's IQWS passive PoE adapter specification](https://catalog.tecomat.cz/en/product/iqws4000-weather-station), [Reolink PoE doorbell UK specifications](https://reolink.com/gb/product/reolink-video-doorbell-poe/), and [Home Assistant Reolink integration](https://www.home-assistant.io/integrations/reolink/).

## Sensor candidates to investigate

- **Temperature and humidity:** The SHT41 is selected for the bench and working well. Reuse this sensor family for room nodes; outdoor use requires a suitable enclosure and exposure design. SHT31/SHT40 and BME280 remain alternatives for later comparisons.
- **Motion:** PIR detects movement and can be affected by placement, heat sources, and pets.
- **Presence:** mmWave sensors can detect some stationary presence but need room-specific positioning and threshold tuning. Neither PIR nor mmWave should be assumed to reliably identify a human versus an animal.
- **Particles:** SDS011 is one documented PM2.5/PM10 candidate. Similar sensors may differ in interface, dimensions, duty cycle, readings, and power.
- **CO2 and VOC:** decide whether these measurements are actually needed. Select a dedicated CO2 sensor for CO2; VOC sensors report other compounds or indices.

Use sensor readings as household guidance unless the chosen product and installation are suitable for a more demanding purpose. Compare candidate sensors against a known reference during the prototype stage.

## Existing remote-controlled devices

The known target list is six ceiling fan/LED combinations, the fireplace, and televisions to turn off. Do not assume these all use RF or the same frequency: a TV may use infrared or a network integration, while fans and fireplaces may use different RF systems. For each device, record the brand/model, remote markings, button behavior, and manual before selecting any receiver or transmitter.

The six ceiling fans have been identified as NIORSUN 50 cm, 6-speed fan/light units (Amazon ASIN B0DP66BB5Y; the listing is now removed). NIORSUN's current page for a matching 50 cm/6-speed product describes an infrared remote and app control, so infrared is the leading hypothesis for these remotes. The exact model-to-remote mapping and app connection method still need confirmation from the supplied handsets/manuals; do not order a 433 MHz transmitter for these fans based on the old assumption.

Possible approaches depend on what is found:

- Infrared: the transmitter needs line of sight or a correctly placed emitter.
- RF: frequency, modulation, coding, range, and any pairing or security mechanism must match.
- Bluetooth or Wi-Fi: pairing, network access, and the manufacturer's protocol may matter.
- Wired control: only consider it after its circuit and electrical requirements are professionally understood.
- A combined bridge may handle several common IR and RF protocols, but only after those protocols are identified; coverage may require more than one bridge.

ESPHome can receive and transmit supported IR and RF signals, including common 433 MHz signals; support depends on the exact protocol and the required transmitter/receiver hardware. See its [remote receiver](https://esphome.io/components/remote_receiver/) and [remote transmitter](https://esphome.io/components/remote_transmitter/) documentation.

Some commands may be one-way toggles. If the appliance cannot report its state, keep a physical remote and avoid automations that rely on an assumed state. Treat fireplace control separately: follow the appliance manufacturer's instructions, retain its approved controls and safety functions, and do not automate ignition or modify appliance wiring.

## Power and enclosure

- **Current power prototype:** two matched removable HiQuick NiMH AA cells in series (marked 1.2 V / 2800 mAh). The exact ESP32 board with the faulty 5 V rail still needs to be identified before selecting its regulator/input connection.
- Build two independent rails from the pack: a regulated 3.3 V rail for the ESP32's verified power input and 3.3 V sensors, and a separate enabled/switched 5 V boost rail for the SPS30 and other 5 V loads. Both rails share ground. The 5 V rail must not depend on the faulty dev-board 5 V pin.
- Feed 3.3 V sensors directly from the regulated 3.3 V distribution rail, not through GPIO or the dev board's 3.3 V output. Size the regulator for the ESP32's Wi-Fi bursts plus all simultaneous loads; Espressif recommends at least 500 mA for an ESP32-S3 supply.
- Use a separate 5 V converter with enough peak headroom for the SPS30's fan start. Turn it off when the sensor is not sampling, and prevent I2C/level-shifter signal lines from back-powering an unpowered sensor.
- Do not estimate battery runtime from the ESP chip's advertised sleep current. Measure the complete device at the battery pack, including the board regulator/LEDs, both DC/DC converters, sensors, Wi-Fi, and sampling schedule. A screen, Wi-Fi connection, or particle-sensor fan may make frequent recharging necessary.
- Charge the removable AA cells in a charger designed for their chemistry; do not charge them inside the device. Keep the pair matched and define a conservative low-battery cutoff before room deployment. Lithium-ion cells are a separate later redesign.
- A wooden outer case can be a finish, but it must not block airflow or trap heat. Design sensor openings and safe separation from warm components and any battery.
- Keep each device easy to open for service without exposed conductors during normal use.

## Official technical references

- [Espressif ESP32-S3 overview](https://www.espressif.com/en/products/socs/esp32-s3)
- [Espressif ESP32-C6 datasheet](https://documentation.espressif.com/esp32-c6_datasheet_en.html)
- [ESPHome remote receiver](https://esphome.io/components/remote_receiver/)
- [ESPHome BME280 sensor](https://esphome.io/components/sensor/bme280/)
- [ESPHome SDS011 particle sensor](https://esphome.io/components/sensor/sds011/)
- [ESPHome LD2410 presence sensor](https://esphome.io/components/sensor/ld2410/)
- [ESPHome deep-sleep behavior](https://esphome.io/components/deep_sleep/)
- [Espressif ESP32-S3 hardware power-supply guidance](https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32s3/schematic-checklist.html)
- [Sensirion SHT4x datasheet](https://sensirion.com/media/documents/33FD6951/662A593A/HT_DS_Datasheet_SHT4x.pdf)
- [Sensirion SPS30 datasheet](https://sensirion.com/file/datasheet_sps30)

## No-display two-zone room box

This is the first indoor physical layout to mock up and may become the repeatable design for the 11 room boxes. Prove one unit before making the others. Keep a common enclosure and mounting pattern, but fit optional sensors only in rooms that need them. Outbuilding nodes need a separate weather-appropriate enclosure. This replaces the earlier brainstorm estimate of 160 × 110 × 70 mm external size: that estimate left too little usable space after wall thickness and a sensor bay were included.

**Preliminary outside target:** 180 mm wide × 150 mm high × 80 mm deep. With 6 mm panels this leaves about 168 × 138 × 68 mm inside before adding a divider, mounts, and vent grilles. Reserve roughly 50 mm of clear internal height for the lower sensor bay; the upper electronics bay gets the remaining height. These are mock-up dimensions, not final cut dimensions.

| Zone | Proposed contents and layout |
| --- | --- |
| Upper compartment | The selected ESP32 board, the two-AA holder, and separate 3.3 V and switched 5 V regulator modules. Keep the cells protected and removable for charging; provide an accessible power switch and service access. |
| Divider | A physical shelf separates the ESP board, removable AA cells, and regulator modules from the lower sensor area. Use small, protected cable pass-throughs. |
| Lower air-quality bay | Sensirion SPS30 mounted close to its own case openings, with its two inlets and outlet unobstructed. Keep its outlet from blowing back into its inlets or toward the temperature/humidity sensor. |
| Lower room-sensor nook | SHT41 breakout on short leads near its own passive vents. Keep it away from the ESP board, AA cell holder, and SPS30 outlet. Do not force SPS30 exhaust through this nook. |
| Front face | Mount any future presence sensor facing the room, with a clear non-metallic aperture. Confirm its sensing works through the chosen face material before cutting a production enclosure. |

The SPS30 has its own sampling fan. It does not need a second tiny fan to pull air through the box. Leave the SPS30's own inlet and outlet paths open to room air and separate them from the SHT41 vent path. Its idle mode can reduce power between samples, but the sensor needs a warm-up before each reading. A separate fan near the SHT41 could add heat and distort both temperature and relative-humidity readings, so do not include one unless later measurements demonstrate a benefit.

The SHT41 should sample room air, not the enclosure's local temperature. Use a removable mock-up first and compare it beside a reference thermometer/hygrometer with the ESP board and particle sensor on and off. Fix placement and airflow before considering software offsets.

The complete first mock-up is expected to be larger than the initial estimate. Cut no final wood until the actual board variant, SPS30 cable, divider, vents, and sensor orientation have been laid out together.
