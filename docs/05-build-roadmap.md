# Build roadmap

Keep the sensor and enclosure work as parallel tracks. The sensor track proves the electronics and readings; the enclosure track develops a wooden two-compartment mock-up. Join them for fit and airflow checks before cutting final wood. Each phase should leave the house in a usable state if the project stops there.

## Current progress

- The old PC has been converted to a Proxmox VE 9.2.2 host.
- Home Assistant OS 18.3 is running in VM 100 and initial onboarding is complete. Its current LAN address is `192.168.2.202`.
- The host is reachable at `192.168.2.50:8006`.
- The server provides the local Home Assistant foundation. About 460 GB of internal storage is reported. The exact free space is not yet checked. A NAS and camera-recording capacity are not yet in place. The near-term target is one 2 TB drive after motherboard and connector compatibility is checked; larger storage is deferred while pricing and supply are monitored.
- Current hardware status (1 November 2026): the ESP32-S3 Dev Kit (N16R8) and SHT41 are working reliably over Wi-Fi with Home Assistant. The SHT41 has been very accurate in the user's comparison so far. The SPS30 is not working and may have been damaged in the previous smoke incident; reorder one and a 4-channel I2C level shifter with clearly marked GND, LV, and HV connections.
- Bench hardware is now connected: the ESP32-S3 Dev Kit packaging identifies the board as N16R8, and the SHT41 breakout is powered from 3.3 V, with SDA on GPIO 8 and SCL on GPIO 9. I2C detection is confirmed at address `0x44`, and serial temperature/humidity readings work. ESPHome is installed on the board, and Home Assistant now shows the Bench Room Temperature and Bench Room Humidity entities. A steady serial comparison showed the SHT41 at about 21.63–21.67 °C and 50.03–50.43% RH while a household reader showed 21.5 °C and 50% RH; the reader's own tolerance is unknown.
- The PlatformIO bench firmware is in [firmware/sht41_i2c_scan](../firmware/sht41_i2c_scan/README.md). It scans for the SHT4x, then reads and prints temperature and humidity every three seconds. The Home Assistant device uses ESPHome firmware.
- See [the server setup record](09-server-setup.md) for hardware, VM configuration, and troubleshooting notes.
- The front-door panel, kitchen screen, and cameras have not started. The doorbell has not started and is deferred until the new door is installed. The outdoor weather-station track can start now.
- The next electronics build is a two-AA battery prototype. The cells are HiQuick NiMH AA, marked 1.2 V / 2800 mAh; two in series give 2.4 V nominal and 6.72 Wh nominal by label. The working SHT41 board is recorded as an ESP32-S3 Dev Kit N16R8, but the exact cheap ESP32 board with the faulty 5 V rail still needs confirmation before selecting its regulator/input connection. The design target is a separate 3.3 V rail and switched 5 V rail; the faulty board 5 V pin is excluded.

### Active next work

1. Identify the motherboard, M.2 type/size, and free SATA connections; choose one compatible 2 TB drive and compare its Black Friday price with today's baseline.
2. Decide whether one exposed weather station plus separate temperature/humidity nodes at the front, rear, and greenhouse meets the need. Survey power, network, mounting, and exposure at each location.
3. Choose between the easy local Ecowitt path (solar/AA outdoor array, separately powered Ethernet gateway) and a wired PoE station (check its exact PoE type and Home Assistant setup before purchase).
4. Check the boiler/heating-controller make and model. Treat a Home Assistant outdoor-temperature entity and the boiler's own weather-compensation sensor/interface as separate compatibility questions.
5. Reorder the SPS30 and a level shifter with GND pins for the indoor air-quality prototype.
6. Build the two-AA power tree: identify the faulty-rail ESP32 board, then choose a 3.3 V regulator sized for ESP32 Wi-Fi bursts and a separate enabled 5 V converter for the SPS30. Measure current and runtime with the actual device and sampling schedule.

## Phase 0 — Survey and requirements

- Fill in the room, remote, alarm, PC, network, display, camera, and outdoor-station surveys.
- Collect manuals and model numbers.
- Decide which first-room location is convenient and representative.
- Mark unknowns instead of filling gaps with guesses.

**Ready to move on when:** the first prototype has a clear purpose, the PC's existing data is protected, and the first remote-controlled appliance has been identified or explicitly deferred.

## Phase 1 — Desk prototype

- The bench sensor track is underway with the ESP32-S3 Dev Kit N16R8 and SHT41 already reporting to Home Assistant. These are the selected parts; the earlier shopping-list models are alternatives, not requirements.
- Add one mini PIR motion sensor to the working ESPHome node as a trial, using a free GPIO; check whether pets trigger it. Radar is a later alternative only if detecting still occupancy is needed.
- Reorder the SPS30 and a 3.3 V / 5 V I2C level converter with accessible common GND connections; the previous SPS30 is not working and may have been damaged.
- Build and power the sensor node from two removable rechargeable AA cells using the separate regulated rails described in [the system architecture](02-system-architecture.md). Use a bench supply only to set up and characterize the power modules, not as the final supply path.
- Connect it to a local Home Assistant instance, initially using a suitable existing machine or virtual machine if available.
- Record the bill of materials, configuration, readings, reboots, and network behavior.

**Ready to move on when:** the sensor reports consistently, the chosen software path is maintainable, and the device recovers cleanly after a normal restart or network interruption.

## Phase 2 — First room node

- In parallel with sensor testing, sketch and mock up the intended wooden enclosure as two compartments: ESP32 and protected removable AA holder above, sensor chamber below, with protected wire pass-throughs between them. Keep the cells removable and charge them externally.
- Make a removable cardboard or scrap-wood mock-up before cutting final wood. Keep the SHT41 in a passive, room-vented nook separate from the SPS30 outlet and ESP board.
- Use the SPS30 fan and air ports for PM sampling; do not add a separate fan beside the SHT41 unless measurements show it helps without biasing readings.
- Fit-check the actual board, SPS30 cable, divider, vents, and sensor orientation, then test readings with the electronics running before making final cuts.
- Check temperature readings against a separate reference instrument.
- Keep the PIR only if motion detection is useful in the chosen room; confirm its wooden enclosure opening leaves the lens exposed to the room.
- Observe pet and room-layout effects for several days before writing automations.
- Keep the existing remote and manual controls available.

**Ready to move on when:** the enclosure does not distort the readings, the sensor placement is useful, and the node remains reliable in the room.

## Phase 3 — Repeat the basic room node

- Roll out the proven indoor box design to the target 11 rooms, one node at a time. Use the same basic build where practical and add optional sensors only where useful.
- Keep a record of serial numbers, room names, firmware, sensor locations, and any room-specific differences.
- Check Wi-Fi coverage and router capacity as the number of devices increases.
- Keep room sensors simple; add particle monitoring only where desired.

**Ready to move on when:** the chosen pattern can be serviced and maintained without treating every room as a custom one-off.

## Phase 4 — Existing remote control

- Identify each appliance and remote.
- Test receiving or controlling commands on a bench with the appliance safely accessible and the original remote available.
- Confirm the command type, repeat behavior, and whether device state can be verified.
- Use a separate control node if that makes radio placement or maintenance easier.

**Ready to move on when:** commands are reliable enough for the intended use and a failed command does not create a misleading state in the dashboard.

## Phase 5 — Household panels and doorbell

- **Not started:** select front-door and kitchen display hardware based on screen size, readability, power, mounting, and software support.
- Agree what each screen should show before designing the dashboard.
- **Doorbell deferred until the new door is installed.** Before the door/frame work is closed up, plan a Cat6 home run to the outside doorbell position, a separate two-core low-voltage cable for a conventional chime or future transformer-powered unit, and conduit/pull string or a spare route. Choose the actual doorbell first; its power, cable gauge, and chime requirements vary by model.
- Keep cameras and audio/intercom features as separate decisions.

## Phase 6 — Air quality and outdoor weather

- Evaluate the power, airflow, noise, warm-up, and maintenance needs of particle sensors.
- Decide separately whether CO2 or VOC measurement is useful.
- **Weather track is now active.** Design a dedicated exposed station for temperature, humidity, wind speed and direction; decide whether rainfall or other measurements are wanted. Compare the two leading paths in [the device plan](03-device-and-hardware-plan.md): Ecowitt for its straightforward local HA integration, or a wired Ethernet/PoE product if its power and custom-integration trade-offs are acceptable.
- Treat the main weather station as one open-sky location, not one full wind station at each side of the house. Add separate SHT41/ESPHome temperature and humidity nodes at the front, rear, and greenhouse only if those local readings are useful. Outdoor SHT41 boards need ventilated weather shields/enclosures; the indoor room-node case is unsuitable.
- Confirm whether heating weather compensation reads an outside temperature entity from Home Assistant or requires the boiler manufacturer's own sensor. Do not assume a weather station can replace a proprietary boiler sensor.
- Decide whether one or two additional nodes are wanted in the greenhouse, shed, or another outbuilding, and what each should measure. Survey Wi-Fi coverage and power at each location.
- Treat outbuilding nodes as separate from the weather station. Design a suitable enclosure and mounting for each before installation; do not reuse the indoor wooden enclosure without checking moisture, condensation, heat, and sensor ventilation.
- Compare readings with suitable reference instruments and document known limits.

## Phase 7 — Cameras and recording

- Decide camera locations, privacy boundaries, access controls, storage, and retention.
- **Not started.** Select cameras and recording hardware together, after checking network and PC capacity and adding storage substantially beyond the current 460 GB. A 2 TB drive is an interim expansion, not the final NAS/camera-retention solution.
- Keep cameras off private spaces and avoid collecting audio unless there is a specific, lawful need.
- Confirm how recordings are protected and deleted.

## Later Home Assistant integrations

- Add other appliances and services as separate projects once their requirements and supported integrations are known. Cameras remain in the camera phase above.

## Phase 8 — Alarm and motorized windows or curtains

These are separate, higher-consequence projects. Do not bundle them into a room sensor rollout.

- Ask a qualified alarm professional to identify the existing panel, cable functions, and replacement implications.
- As a separate evaluation, map the old sensor cables (route, topology, conductor gauge, condition, and existing connections) to see whether selected runs could safely carry low-voltage power to room nodes. Design any central supply, per-branch protection, and local 5 V conversion from measured cable drop and node loads; do not connect an unverified supply to the old wiring.
- Treat battery charging as a separate circuit and design. Do not connect a battery directly to the room supply wiring; use a compatible charger and protection, or remove the rechargeable battery and charge it in a matching external charger.
- Keep the original alarm working until any replacement is fully commissioned.
- For window or curtain motors, define limits, obstruction response, manual override, power loss behavior, and safe operation first.
- Use appropriate rated controllers and professional help for any mains or fixed wiring.

Do not proceed to this phase merely because a sensor prototype works.
