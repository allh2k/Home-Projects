# Home Automation

A personal, modular home-automation project built around small room devices, a local home server, and gradual additions that can be understood and maintained.

**Current status (1 November 2026):** Proxmox and Home Assistant are running on the former PC, and an ESP32-S3 N16R8 with an SHT41 is reporting reliably over Wi-Fi. A two-AA NiMH power prototype is now planned using HiQuick cells marked 1.2 V / 2800 mAh, with separate regulated 3.3 V and switched 5 V rails; the exact cheap ESP32 board with the faulty 5 V rail still needs identification. About 460 GB of internal storage is reported; one compatible 2 TB expansion is the near-term target, with larger NAS/camera storage deferred. The SPS30 is not working and may have been damaged; replacement and a level shifter with GND pins are planned. Weather station planning can start now. The front-door panel, kitchen screen, and cameras have not started; the doorbell is waiting for the new door.

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

The server and first SHT41-to-Home-Assistant path are now working. The next power build is a two-AA NiMH prototype with separate 3.3 V and switched 5 V rails; identify the exact faulty-rail ESP32 board before selecting its regulator. Then measure runtime with the actual Wi-Fi and SPS30 schedule, while continuing the weather-station and outdoor sensor plan.

The ceiling-fan remotes, alarm wiring, exact ESP32 board with the faulty 5 V rail, and battery runtime remain open. AA cells will be charged externally in a NiMH charger; lithium-ion is deferred.

## Design principles

1. **Build in stages.** Begin with observation and sensing; defer motors and alarm changes.
2. **Keep devices modular.** A failure in one room should not take down the rest of the system.
3. **Prefer local operation.** Basic functions should continue when internet access is unavailable.
4. **Measure the complete device before predicting runtime.** Displays, radios, and particle sensors can use much more power than simple temperature sensors.
5. **Keep the existing alarm working** until any replacement is fully designed, installed, and commissioned.
6. **Keep house wiring out of the prototype.** Use the removable AA pack and independent low-voltage regulator rails on the desk.
