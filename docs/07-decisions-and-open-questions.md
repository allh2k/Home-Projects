# Decisions and open questions

## Current decisions

| ID | Decision | Status |
| --- | --- | --- |
| D-01 | Build a modular system rather than one board for the entire house. | Agreed direction |
| D-02 | The first working SHT41 bench node uses USB power; a two-AA test pack and fused 5 V booster power the SPS30 test. | Implemented separately; full-node battery power still unresolved |
| D-03 | Use Home Assistant for local coordination, dashboards, and the first ESPHome prototype. | Agreed; installed and running |
| D-04 | ESPHome is the leading candidate for the first ESP-based room prototype. | Provisional; verify board and component support |
| D-05 | Do not assume fan remotes are 433 MHz. Identify each remote first. | Required |
| D-06 | Do not assume alarm wiring is suitable for power until its panel, cable, topology, condition, and load capacity are identified. Battery charging requires a separate, correctly matched charger. | Required |
| D-07 | Build and measure a battery-powered prototype before selecting final chemistry or runtime schedule. | Agreed; two-18650 Li-ion prototype with the Pi Hut/DFRobot 2-way holder is being considered; four AA cells also on hand; no purchase or final battery configuration confirmed |
| D-08 | Defer alarm replacement, cameras, and window/curtain motors to later, separately scoped phases. | Agreed direction |
| D-09 | Do not buy hardware for every room before one room pattern is understood. | Agreed direction |
| D-10 | Use the ESP32-S3 Dev Kit N16R8 and SHT41 breakout for the working bench sensor. | Implemented; reporting over Wi-Fi to Home Assistant |
| D-11 | Use Proxmox VE on the old PC as the host, with Home Assistant OS in a VM. | Implemented; setup record in [docs/09-server-setup.md](09-server-setup.md) |
| D-12 | Target one repeatable indoor room box for each of 11 rooms, plus one or two separate outbuilding nodes. | Agreed direction; roll out after one indoor prototype is proven; sensor population and outbuilding design remain open |
| D-13 | Evaluate whether identified legacy alarm cable can provide low-voltage power to selected room nodes. | Proposed; no wiring or power supply selected until survey and load/voltage-drop checks |
| D-14 | Use the SPS30 for particle measurements with an I²C level shifter where required by the selected interface. | SPS30 is returning readings on the fused 5 V booster; verify level-shifter stock/wiring; no replacement sensor currently needed |
| D-15 | Start the outdoor weather station track; compare local HA support against the preference for wired/PoE high-mount sensors. | Active; choose one exposed wind/rain station plus optional front/rear/greenhouse temperature-humidity nodes |
| D-16 | Defer the doorbell until the new front door is installed; plan its cables before the frame/wall work is closed. | Planned; Cat6 home run and separate two-core low-voltage bell cable are the prewire target |
| D-17 | Add one compatible 2 TB drive as near-term server expansion; defer NAS/camera bulk storage pending capacity and market review. | Planned; check motherboard slots, SATA ports, free bay, and current free space before purchase |
| D-18 | Prototype with discrete power modules as needed; final product should use an integrated Li-ion charging/protection board with regulated 5 V and 3.3 V rails. Do not rely on the faulty ESP32 development-board 5 V rail. | Direction agreed; candidate two-cell holder provides charging, overcharge/over-discharge and reverse-cell-polarity protection plus both rails; verify complete protection, cell arrangement, ESP32 input, and final power-board design |
| D-19 | Build a removable wooden enclosure mock-up before choosing final dimensions or buying finished wood. | Face starts at 150 mm wide × 180 mm high; compare 40 mm and 50 mm depths with the 80 mm concept; all dimensions provisional |

## Open questions

### House and equipment

- What are the actual room names and count?
- Which rooms need sensors, and which need only a simple display or control?
- Which sensors should be standard in all 11 indoor boxes, and which should be limited to selected rooms?
- Should the greenhouse, shed, or both get an environmental node, and what measurements are useful there?
- Where should a dedicated weather station go, and should it measure rainfall or anything beyond temperature, humidity, and wind speed/direction?
- What outdoor conditions are needed at the front, rear, and greenhouse, and which positions already have Ethernet/PoE or reliable Wi-Fi/power?
- What are the boiler/heat-pump and weather-compensation controller make/models, and what outside-sensor input do they support?
- What motherboard and storage connections are available for a compatible 2 TB drive?
- What exact NIORSUN model/remote number appears on the six fan/light units or their handsets, and does the handset confirm infrared?
- What are the make/model and approved remote-control method for the fireplace?
- What are the makes/models of the televisions, and do their power-off commands use infrared, Bluetooth, Wi-Fi, or another method?
- Which of the six fan/LED combinations share the same remote model and protocol?
- What is the alarm panel make/model, and is it monitored?
- Is each alarm sensor cable a separate run to the panel, what conductors/gauge does it use, and is it disconnected from all alarm equipment?
- Which room nodes would be wired, and what total load must each cable carry (including any SPS30)?
- For rooms without a suitable wired run, is a removable rechargeable battery acceptable, and what charging interval is practical?
- What is the old PC's motherboard model, M.2 health, and measured idle power? Was any Windows data that needed preserving backed up before replacement?
- Are `192.168.2.50` and `192.168.2.202` reserved in the router, or are they still DHCP leases?
- How good is Wi-Fi coverage in each room and outdoors?
- Is there reliable power at the greenhouse/shed locations, or would those nodes need a different power/network design?

### Desired features

- What should the front-door panel say or show?
- What should the kitchen to-do list connect to, and who edits it?
- Which cameras are wanted, and where must recording be avoided?
- Is CO2 measurement desired in addition to PM2.5/PM10 and humidity?
- Should the outdoor weather station measure rain and wind direction as well as speed?
- Is solar/AA acceptable for a high-mounted Ecowitt WS90, or is wired power a firm requirement?
- If wired weather station power is required, is 12 V passive PoE acceptable with its dedicated injector and non-native HA setup, or must it be IEEE 802.3af/at?
- For the replacement doorbell, is a proprietary plug-in chime acceptable, or must it keep/use a wired mechanical chime?
- Is the goal to monitor the alarm, replace it, or both?
- Are window and curtain motors still long-term ideas after the sensor system is stable?

### Engineering choices

- Does the provisional ESP32-S3-DevKitC-1 fit the first prototype after its sensor wiring, antenna clearance, and enclosure layout are checked?
- Should the first room device use Wi-Fi, or is a different network needed for coverage or battery life?
- What external or network backup destination should hold Proxmox and Home Assistant backups?
- What screen size, brightness, power, and mounting are acceptable for each panel?
- What battery service interval is acceptable after power has been measured?
- What exact ESP32 board model is printed on the boards, and which 5 V loads besides the SPS30 must be supported?
- Which exact cells, two-cell configuration, charger/protection circuit, and integrated dual-rail power board should the final product use?
- Does the actual battery holder and power assembly fit within a 40 mm or 50 mm enclosure depth with safe wiring and service clearance?
- What is the minimum acceptable runtime, and how often must the SHT41 and SPS30 update?
- Should the SPS30 run continuously, or can it be switched on for periodic measurements?
- What data retention and backup approach is wanted for sensor history and any camera recordings?
- What additional storage will be used if camera recording is added?

## Decision record template

For each major choice, record:

- Decision:
- Date:
- Options considered:
- Reason:
- Safety or maintenance effects:
- Parts/software affected:
- What would cause the decision to be revisited:
