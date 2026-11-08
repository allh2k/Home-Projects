# Safety and privacy

This is a planning document, not an electrical wiring guide. Stop and get qualified help whenever a device involves unknown house wiring, mains voltage, a security alarm, or a motorized window.

## Electrical boundaries

- Keep the two-AA power prototype low voltage and on a desk while its regulator, wiring, thermal behavior, and low-battery cutoff are being established.
- Do not connect a development board directly to mains voltage.
- Do not modify mains-powered lights, fans, sockets, or fixed wiring as part of the initial project.
- Do not open powered equipment to inspect its control electronics.
- Use appropriately rated, enclosed power supplies and keep exposed conductors inaccessible.

## Alarm wiring and existing security

- Do not assume alarm wiring carries 12 V, has spare conductors, or can supply charging current.
- Alarm zones may be monitored or supervised. Connecting a charger, converter, sensor, or load can cause faults or impair the alarm.
- Do not connect an alarm conductor to a TP4056 board, battery, ESP board, or buck converter based on the brainstorm.
- Ask the alarm installer or a qualified alarm professional to identify the panel and wiring before considering any reuse.
- Do not replace or disable the existing alarm until a suitable replacement is installed and commissioned. Home Assistant, DIY sensors, and internet-dependent automations are not substitutes for a properly maintained security or life-safety system.

## Batteries

- The current bench test uses two AA cells to power the fused 5 V SPS30 booster; the ESP32 remains on USB. A separate two-18650 Li-ion power prototype is being considered using a holder that advertises integrated charging, overcharge/over-discharge protection, and 5 V/3.3 V outputs. This prototype choice is not a final battery/PCB selection.
- For any lithium-ion prototype, use two identical, matched cells in the holder and follow its charging instructions. The holder listing specifies overcharge/over-discharge and reverse-cell-polarity protection; it does not clearly specify every overcurrent/short-circuit behavior required of a final product. Do not charge cells outside the compatible charger/holder, mix cell types or states, or use damaged/wrapped cells. Confirm the board's protection and current limits before leaving it unattended.
- The final product is intended to use an integrated power board with charging, cell protection, and regulated 5 V and 3.3 V rails. Verify short-circuit/reverse-polarity protection, low-voltage cutoff, charge behavior, and thermal performance for the actual chosen design; do not infer every protection feature from a generic “BMS” claim.
- Do not use the faulty development-board 5 V pin, power loads through GPIO, or assume the dev board's 3.3 V output is a distribution supply. Do not connect two regulated sources to the same input rail simultaneously.
- The existing AA cells remain a separate test supply; charge them only in a NiMH charger designed for their chemistry. Never use a Li-ion charger for NiMH cells or vice versa.
- Do not improvise battery wiring or use cells with damaged wrappers, leakage, corrosion, or mismatched charge state.
- Keep cells away from sensor heat and ensure they are protected from shorts and physical damage.

## Sensors and enclosures

- Keep temperature and humidity sensors exposed to room air and away from heat from the ESP board, display, regulators, direct sun, and airflow from heating vents.
- Give particle sensors the airflow and clearances their manufacturer requires; do not seal their inlet or exhaust inside a decorative box.
- A wooden exterior may be used only after airflow, heat, battery placement, and access for service are designed. The appearance should not conceal a hot or damaged component.
- Secure wall-mounted devices and keep them away from children or pets where small parts, wires, or batteries could be reached.

## Remotes, lights, and motors

- Keep the original remote and a manual control path.
- A transmitted command is not proof that a fan, light, window, or curtain changed state.
- Never automate an actuator until its limits, obstruction response, manual override, loss-of-power behavior, and emergency stopping method are understood.
- Windows can create crush, fall, rain, wind, and security risks. Do not use automatic window movement as an early experiment.
- Do not control a mains-powered actuator with an unverified relay board.

## Cameras, displays, and network

- Decide camera locations, who can view them, whether audio is needed, how long recordings are kept, and how recordings are deleted.
- Do not place cameras in bedrooms, bathrooms, or other private spaces.
- Aim outdoor cameras to avoid capturing neighbours or public areas where possible.
- Use unique passwords, keep devices updated, and avoid exposing the home server directly to the public internet.
- Do not write passwords, alarm codes, or camera credentials in project notes.
- Make front-door or kitchen screens show only information appropriate for their location.

## Operational reliability

- Keep essential manual operation available.
- Avoid automations that lock doors, move windows, or impair the alarm based only on one sensor or a server connection.
- Decide what happens when Wi-Fi, the server, a sensor, or power is unavailable before enabling each automation.
- Label prototype power sources and keep notes of every connection before expanding the build.
