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

- The active battery prototype uses two removable HiQuick NiMH AA cells in series (marked 1.2 V / 2800 mAh). Treat capacity as a label estimate until runtime is measured.
- Hold the pair securely in a correctly wired holder; use same chemistry, model, age, and charge state. Include a power switch, short/reverse-polarity protection, and a conservative low-battery cutoff appropriate to the confirmed cell chemistry.
- Use separate regulated 3.3 V and 5 V rails. Do not use the faulty board 5 V pin, power loads through GPIO, or assume the dev board's 3.3 V output is a distribution supply.
- Remove the AA cells and charge them in a charger designed for that chemistry. Do not charge them inside the enclosure. Do not use a TP4056 or lithium-ion charging module for NiMH cells; lithium-ion is a separate later redesign.
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
