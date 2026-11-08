# Home Automation

A personal, modular home-automation project built around small room devices, a local home server, and gradual additions that can be understood and maintained.

**Current status (8 November 2026):** Proxmox and Home Assistant are running on the former PC. The ESP32-S3 N16R8 and SHT41 work over USB/Wi-Fi. The SPS30 returns readings while powered by a fused 5 V booster from a two-AA test pack; the ESP32 is still on USB. Four AA cells and the ambient-light sensors are on hand. The user is considering a Li-ion prototype using two 18650 cells and the Pi Hut/DFRobot 2-way holder, which provides charging/protection and 5 V and 3.3 V outputs; order/purchase is not confirmed. Small converter boards are for prototyping; the final product should use an integrated power solution. A wooden enclosure mock-up is the next purchase; keep 180 × 150 mm face size provisional and compare 40 and 50 mm depths against the 80 mm concept. Motion sensors are noted for 21 November. RF hardware is deferred. About 460 GB of server storage is reported; check compatibility and free space before the planned 2 TB expansion. The doorbell remains deferred until the new door.

**Status:** the first desk prototype is reporting to Home Assistant. The ESP32-S3 Dev Kit packaging identifies the board as N16R8; it and the SHT41 breakout are connected on the bench. ESPHome is running on the board, and Home Assistant shows the Bench Room Temperature and Bench Room Humidity entities. I2C communication is confirmed at `0x44`. A steady serial comparison showed the SHT41 at about 21.63–21.67 °C and 50.03–50.43% RH while a household reader showed 21.5 °C and 50% RH; the reader's own tolerance is unknown. PlatformIO remains available for the bench reader firmware.

## Project documents

- [Project brief](docs/01-project-brief.md) — goals, requested features, boundaries, and success criteria.
- [System architecture](docs/02-system-architecture.md) — how room devices, the server, and displays fit together.
- [Device and hardware plan](docs/03-device-and-hardware-plan.md) — candidate device types and selection notes.
- [House and device survey](docs/04-house-and-device-survey.md) — inventory for rooms, remotes, wiring, network, and the old PC.
- [Build roadmap](docs/05-build-roadmap.md) — staged path from a desk prototype to later installations.
- [Safety and privacy](docs/06-safety-and-privacy.md) — boundaries for power, batteries, alarm wiring, cameras, and motors.
- [Decisions and questions](docs/07-decisions-and-open-questions.md) — current decisions and unresolved choices.
- [First-prototype shopping list](docs/08-first-prototype-shopping-list.md) — one no-display room prototype, current UK parts links, and box layout.

## Starting direction

Use separate devices for separate jobs instead of trying to fit the entire house onto one board. A home server can coordinate sensors and dashboards, while room devices handle local sensing and simple actions.

The server and SHT41-to-Home-Assistant path are working. The SPS30 returns readings on a fused 5 V booster, while the ESP32 remains USB-powered. Next, build and measure a battery-powered prototype, then mock up the enclosure at more than one depth. Li-ion power is a candidate direction; the final power board is expected to integrate charging, protection, and both voltage rails, while discrete modules remain useful on the bench.

The ceiling-fan remotes, alarm wiring, exact ESP32 board with the faulty 5 V rail, and battery runtime remain open. Keep the AA and Li-ion prototype supplies separate and use chemistry-matched chargers; the Li-ion power architecture remains a candidate pending prototype measurements.

## Design principles

1. **Build in stages.** Begin with observation and sensing; defer motors and alarm changes.
2. **Keep devices modular.** A failure in one room should not take down the rest of the system.
3. **Prefer local operation.** Basic functions should continue when internet access is unavailable.
4. **Measure the complete device before predicting runtime.** Displays, radios, and particle sensors can use much more power than simple temperature sensors.
5. **Keep the existing alarm working** until any replacement is fully designed, installed, and commissioned.
6. **Keep house wiring out of the prototype.** Use the removable AA pack and independent low-voltage regulator rails on the desk.
