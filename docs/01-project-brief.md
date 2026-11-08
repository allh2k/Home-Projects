# Project brief

## Purpose

Plan a home-made automation system that can grow one device at a time. Home Assistant is now running locally on the former PC, and the first ESP32/SHT41 sensor is working over Wi-Fi. Continue with safe, low-voltage, reversible additions while documenting existing equipment and wiring before installation.

## Requested outcomes

### Room devices

The target is one room box in each of 11 indoor rooms, with one or two additional nodes for outbuildings such as a greenhouse or shed. Use a repeatable indoor box design with a wooden exterior; determine the exact sensor population room by room. Features under consideration:

- Temperature and humidity.
- Motion or presence sensing, with the ability to learn how pets affect readings.
- Indoor particle readings for PM2.5 and PM10 where worthwhile.
- Possible control of six ceiling fan/LED-light combinations, the fireplace, and televisions after each device's remote method and safe control options are identified.
- The current desk power test uses two AA cells for the fused 5 V SPS30 supply; the ESP32 remains on USB. The next power prototype may use two 18650 Li-ion cells in the Pi Hut/DFRobot 2-way holder to evaluate charging, protection, and 5 V/3.3 V rails. This is a prototype direction, not a confirmed final battery/PCB design. Measure real runtime before setting a service interval.
- Investigation of whether existing alarm wiring can provide power, only after the system and wiring are identified.

The 11 indoor boxes are the intended deployment, rolled out after one prototype is proven. Not every box needs every sensor: particle sensors, screens, and actuators remain optional. Greenhouse and shed nodes are separate outdoor or outbuilding projects, with enclosures and sensors chosen for their local conditions.

### Shared home equipment

- The former old PC is now a Proxmox server with a working Home Assistant VM. It has about 460 GB of internal storage; a 2 TB drive is the near-term expansion target. A NAS or camera storage needs substantially more capacity and is deferred while storage pricing and supply are watched.
- A small information or greeting panel near the front door (not started).
- A kitchen screen for a household to-do list and useful status (not started).
- Cameras, with indoor and outdoor locations and privacy needs to be decided (not started; requires a separate storage plan).
- A dedicated outdoor weather station is the next project track. The target is local Home Assistant data, a useful outdoor temperature entity for heating/weather-compensation planning, and suitable measurements at the front, rear, and greenhouse. Prefer wired/PoE power for fixed high locations, while comparing it against simpler solar/battery station options.
- A doorbell integration is deferred until the new front door is installed. Plan its cable route while the door/frame/wall work is accessible.

Treat the weather station, greenhouse/shed nodes, and cameras as distinct devices with different mounting, power, enclosure, and network needs. Add cameras and other Home Assistant integrations in later phases after the room sensors are established.

### Later automation ideas

- Replacing or integrating with the current alarm panel.
- Automatic window opening.
- Automatic curtain opening.

These are later-stage ideas. They need separate power, safety, manual-control, and failure-mode designs.

## Project requirements

| ID | Requirement |
| --- | --- |
| R-01 | Use a modular design that can be built and repaired in small pieces. |
| R-02 | Begin without altering mains wiring, alarm circuits, windows, or curtains. |
| R-03 | Support room-level temperature and humidity monitoring as the first useful feature. |
| R-04 | Survey each existing remote-controlled device before choosing a control method. |
| R-05 | Compare practical rechargeable battery options on the complete prototype; measure runtime before setting a service interval or fixing the final chemistry. |
| R-06 | Keep camera and microphone use, storage, and access under the homeowner's control. |
| R-07 | Keep the existing alarm operational unless a separate replacement project is properly planned and commissioned. |
| R-08 | Allow a room device or the server to fail without disabling unrelated basic functions. |
| R-09 | Use a local dashboard for household status and the kitchen to-do list. |
| R-10 | Keep a record of selected parts, wiring, firmware, and maintenance instructions as the design develops. |
| R-11 | Outdoor measurements must be available locally in Home Assistant; confirm heating-controller compatibility before relying on them for weather compensation. |
| R-12 | Prefer PoE or wired power for fixed outdoor nodes where practical; record any battery/solar exception and maintenance plan. |

## Out of scope for the first build

- Opening, modifying, or replacing the alarm system.
- Connecting to alarm wires or using them as a power source.
- Mains-voltage switching or work inside mains-powered equipment.
- Installing cameras, window motors, curtain motors, or a permanent doorbell controller.
- Buying enough parts for every room before one prototype is understood.
- Depending on cloud services for essential home functions.

## First project milestone

The server and first SHT41-to-Home-Assistant path are working. The SPS30 is returning readings on a fused 5 V booster; no replacement is currently indicated. The next active tracks are a complete battery-powered bench prototype and a full-size wooden enclosure mock-up. The 180 × 150 mm face is a starting point; test 40 and 50 mm depths against the 80 mm concept. Keep the doorbell on hold until the new door work, and defer camera deployment until storage is expanded and a recording/retention plan is chosen.
