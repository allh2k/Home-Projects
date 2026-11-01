# House and device survey

Fill this in before selecting hardware. Record only what is useful for the design. Do not put Wi-Fi passwords, camera passwords, alarm codes, or other credentials in these notes.

## Status update (1 November 2026)

- Proxmox and Home Assistant are installed and working on the former PC; about 460 GB internal storage is reported. Check exact free space and disk details.
- ESP32-S3 N16R8 + SHT41 is working over Wi-Fi with Home Assistant; SHT41 readings have been very accurate.
- SPS30 is not working; replacement and a level shifter with GND pins are planned.
- Small front-door panel, kitchen screen, and cameras: not started. Doorbell: deferred until the new door is installed. Weather station: ready to plan.

## Room inventory

Make one copy of this section for each of the 11 indoor rooms. Add one or two separate entries for outbuildings such as the greenhouse or shed.

### Room: ____________________

- Intended device location:
- Desired functions: temperature / humidity / motion / presence / PM2.5 / PM10 / light-fan control / display / other
- USB or mains-powered socket nearby:
- Wi-Fi signal quality at intended location:
- Heat sources, direct sun, drafts, or vents nearby:
- Pet activity or other likely motion-sensor interference:
- Desired enclosure size, finish, and colour:
- Existing remote-controlled equipment:
- Notes:

## Remote-controlled equipment inventory

Known scope: six ceiling fan/LED-light combinations, one fireplace, and one or more televisions. Fill a row for each appliance once its room and model are identified. These may use different control methods.

| Appliance location | Appliance brand/model | Remote brand/model | Markings or frequency shown | Suspected method | Manual/link found | What must be controlled? |
| --- | --- | --- | --- | --- | --- | --- |
| Ceiling fan/LED combo 1 — room TBD | NIORSUN 50 cm, 6-speed; Amazon ASIN B0DP66BB5Y | | | Likely IR; verify handset | Product listing removed; current NIORSUN page describes IR remote | Fan and light functions TBD |
| Ceiling fan/LED combo 2 — room TBD | NIORSUN 50 cm, 6-speed; Amazon ASIN B0DP66BB5Y | | | Likely IR; verify handset | Product listing removed; current NIORSUN page describes IR remote | Fan and light functions TBD |
| Ceiling fan/LED combo 3 — room TBD | NIORSUN 50 cm, 6-speed; Amazon ASIN B0DP66BB5Y | | | Likely IR; verify handset | Product listing removed; current NIORSUN page describes IR remote | Fan and light functions TBD |
| Ceiling fan/LED combo 4 — room TBD | NIORSUN 50 cm, 6-speed; Amazon ASIN B0DP66BB5Y | | | Likely IR; verify handset | Product listing removed; current NIORSUN page describes IR remote | Fan and light functions TBD |
| Ceiling fan/LED combo 5 — room TBD | NIORSUN 50 cm, 6-speed; Amazon ASIN B0DP66BB5Y | | | Likely IR; verify handset | Product listing removed; current NIORSUN page describes IR remote | Fan and light functions TBD |
| Ceiling fan/LED combo 6 — room TBD | NIORSUN 50 cm, 6-speed; Amazon ASIN B0DP66BB5Y | | | Likely IR; verify handset | Product listing removed; current NIORSUN page describes IR remote | Fan and light functions TBD |
| Fireplace — room TBD | | | | Unknown | Desired commands and safe remote functions TBD |
| Television(s) — count/rooms TBD | | | | Unknown | | Power off |

Identify each remote from its exterior markings and documentation. Do not open an appliance or touch wiring to identify it. Note whether commands are separate on/off buttons or toggle buttons, and whether the appliance visibly confirms its state. Keep each original remote available. Do not select a transmitter or assume 433 MHz until the exact devices are surveyed.

Treat the fireplace as a separate safety-sensitive integration. Read its exact manufacturer's manual and use only a supported external remote interface; do not bypass the receiver, ignition controls, or built-in safety functions.

## Existing alarm system

This is an identification survey only. Do not disconnect the panel, open energized equipment, or use an alarm conductor as a power source.

- Panel make and model:
- Panel manual available:
- Alarm installer or monitoring company:
- Battery model/date if visible without opening equipment:
- Which rooms have alarm cables:
- Are those cables already connected to sensors?
- Is the alarm monitored or used for emergency response?
- Any installer documentation about spare conductors or auxiliary power:
- Questions for a qualified alarm professional:

Keep the existing alarm intact and operational. Do not assume its wires are 12 V, spare, or suitable for powering a charger.

## Old PC inventory

- Make/model: Motherboard/system model not yet recorded
- Processor: AMD Ryzen 7 3700X
- 64-bit or 32-bit operating system: 64-bit x86-64
- Current operating system and whether it must remain: Proxmox VE 9.2.2; previous Windows installation was replaced
- Memory: 32 GB DDR4
- Disk type, size, and known condition: about 460 GB internal capacity reported; earlier server setup notes describe a 450 GB M.2 drive. Exact capacity, health, interface, and remaining free space need checking.
- Ethernet port and network connection: Connected to the home LAN through Proxmox bridge `vmbr0`; NIC model not recorded
- Approximate idle power if known: Not measured
- Important files to preserve or back up: Whether Windows files were backed up before replacement is not recorded
- Other hardware: GTX 1080 graphics card; hybrid AIO cooler
- Selected approach: Proxmox VE host with Home Assistant OS in a VM; see [server setup record](09-server-setup.md)

Before any future OS reinstall or repartition, confirm that data to preserve has a separate backup.

The server is now installed and running. Proxmox is reachable at `192.168.2.50:8006`; the Home Assistant VM currently has `192.168.2.202`. Check whether either address has a DHCP reservation in the router. Do not record network or account passwords here.

## Network and home layout

- Router make/model:
- Wi-Fi access-point locations:
- Areas with weak or no coverage:
- Existing guest or IoT network:
- Ethernet locations:
- Internet outage expectations:
- Notes:

Do not record network credentials here.

## Displays, cameras, and doorbell

- Front-door panel: size, mounting, power, and information to show:
- Kitchen screen: size, mounting, power, and to-do-list source:
- Doorbell: deferred until the replacement front door is installed. Before installation, record existing chime and transformer locations, cable routes, desired camera/intercom/chime features, network-switch location, and where a Cat6 run can enter beside the fixed frame.
- New-door/door-frame work: confirm a protected cable route for one home-run Cat6 Ethernet cable (prefer a spare second Cat6) plus a separate two-core low-voltage bell cable; keep cables out of the moving door leaf. Confirm final bell-cable gauge after doorbell/chime selection. Provide conduit/pull string or an accessible spare route.
- Doorbell make/model and existing chime/wiring details (once selected):
- Camera locations under consideration:
- Private spaces where cameras must never be installed:
- Who should be allowed to view recordings:
- Desired retention period:
- Any neighbours, public paths, or shared spaces in view:
- Notes:

## Dedicated outdoor weather station

This is a separate device from any greenhouse or shed node. The initial goal is outdoor temperature and humidity plus wind speed and direction; decide whether rainfall or other measurements are useful. Survey mounting and exposure before choosing sensors or an enclosure.

- Proposed mounting point and height:
- Is this the single open-sky wind/rain station location, or a temperature/humidity-only point:
- Exposure to rain, wind, sun, and nearby heat:
- Cable or wireless preference: wired power/PoE preferred for fixed high locations; Ecowitt WS90 also has an optional 12 V/1 A external-power extension; solar/AA only if its maintenance trade-off is acceptable:
- Maintenance access:
- Desired measurements: outdoor temperature / humidity / wind speed / wind direction / rainfall / other:
- Notes:

## Distributed temperature/humidity points

Survey these separately from the main wind/rain station. A single station cannot report local conditions at all three positions.

| Location | Measurements wanted | Existing Ethernet/PoE | Wi-Fi quality | Sun/rain/condensation exposure | Mounting/access notes |
| --- | --- | --- | --- | --- | --- |
| Front | | | | | |
| Rear | | | | | |
| Greenhouse | | | | | |

For any heating/weather-compensation use, record the boiler/heat-pump and controller make/model, whether a manufacturer's outside sensor is installed, and its documented supported input. Home Assistant sensor compatibility does not by itself confirm compatibility with the heating controller.

## Greenhouse and shed nodes

Plan one or two separate nodes for the greenhouse, shed, or both. Their measurements should suit each location (for example, temperature and humidity, with other needs decided after surveying). They are not automatically the weather station and should not use the indoor wooden enclosure without checking moisture, condensation, temperature range, and sensor ventilation.

- Location and desired measurements for each node:
- Exposure and enclosure needs:
- Power and Wi-Fi coverage:
- Maintenance access:
- Notes:

## Cameras and other Home Assistant devices

Keep cameras and audio/intercom features as separate decisions. Add these and other Home Assistant integrations as later, separately scoped projects.
