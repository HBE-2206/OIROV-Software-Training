# OIROV Software Track — Instructor Guide & Answer Key

**Trainer:** Hazem Elshafey — CTO, OIROV Robotics  
**Program:** 3 weeks · 2 sessions/week · 2 hours/session  
**Platforms:** Arduino Uno and ESP32  
**Final project:** Firefighting Robot

## Teaching approach

Each session follows an outcomes-first, project-based structure:
1. **Retrieval/recap** — retrieve knowledge from the previous session.
2. **Explicit instruction** — explain a small concept and model the code.
3. **Worked example** — instructor demonstrates and explains decisions.
4. **Guided practice** — learners modify code with instructor feedback.
5. **Practical challenge** — learners test the concept against acceptance criteria.
6. **Formative assessment** — exit ticket, observed behavior, or code review.
7. **Reflection/documentation** — record what worked, failures, and next steps.

This structure is informed by widely used instructional practices (clear learning outcomes, worked examples, formative assessment, deliberate practice, and project-based learning). It is a practical teaching design, not a claim of formal accreditation.

## Session-to-hardware alignment

| Software session | Related Hardware session | Practical artifact |
|---|---|---|
| 01 Programming fundamentals | HW01 board/components overview | `Session01_Blink.ino` |
| 02 Digital I/O and electrical logic | HW02 voltage/current/polarity/multimeter | `Session02_SensorSerialMonitor.ino` |
| 03 DC motor, H-Bridge, PWM | HW03 DC motor/L298N | `Session03_L298N_SerialMotorControl.ino` |
| 04 Sensors and actuators | HW04 IR/flame sensor, servo, relay/pump | `Session04_SensorServoRelayDemo.ino` |
| 05 Safe startup and fault handling | HW05 power distribution, buck, ground, protection | `Session05_SafeStartupAndTimeout.ino` |
| 06 Integration and troubleshooting | HW06 assembly, continuity, integration | `Session06_FirefightingRobot_Demo.ino` |

## Answer key — Session 01

1. **Program vs algorithm:** a program is executable instructions; an algorithm is an ordered method for solving a problem.
2. **Variable vs data type:** a variable names a stored value; the data type determines the kind/representation of value.
3. **`if (x > 5)`:** checks whether x is strictly greater than 5.
4. **Loop count:** `for (int i=0; i<4; i++)` runs four times: i = 0, 1, 2, 3.
5. **setup vs loop:** setup runs once at startup/reset; loop repeats continuously.
6. **Why not drive motors from GPIO:** GPIO cannot supply motor current safely; use a correctly rated driver and supply.
7. **Blink change:** modify the interval constant, e.g. 250 ms on and 750 ms off requires separate ON/OFF durations.

## Answer key — Session 02

1. `pinMode(pin, INPUT)` configures a pin to read a digital logic level.
2. Active-low means the active state is LOW; the module datasheet and observed behavior determine interpretation.
3. Serial Monitor displays raw values and helps isolate wiring/polarity problems before decision logic.
4. Uno and ESP32 voltage limits differ; ESP32 GPIO is generally 3.3 V logic and not 5 V tolerant.
5. Common-ground requirements depend on the interface/power design; follow the approved wiring plan.

## Answer key — Session 03

1. An H-Bridge/driver switches current through a motor; a GPIO pin cannot safely supply the motor's current.
2. PWM varies the switching duty cycle to control average drive. It does not guarantee exact RPM.
3. Test direction with the actual motor and mapping because wiring/polarity changes physical direction.
4. Zero PWM, coast, brake, and emergency-stop behavior are not universally identical; verify the driver truth table.
5. Test one motor at a time with wheels lifted and a physical power disconnect available.

## Answer key — Session 04

1. Separate raw readings from decisions so polarity, thresholds, and sensor faults can be tested independently.
2. Relay modules can be active-high or active-low; verify ON/OFF behavior before connecting a load.
3. Pumps require a suitable power circuit and driver/relay rated for voltage/current and inductive load.
4. On invalid input or timeout, return to the defined safe state, stop motion, disable the actuator request, and report the fault.
5. Servo power must meet the servo's current requirements; do not assume the board's power pin is adequate.

## Answer key — Session 05

1. Common ground provides a shared reference for logic signals where the approved design requires it.
2. Measure a buck converter output before connecting the load to avoid applying an incorrect voltage.
3. Software cannot replace suitable fuses/wiring/driver ratings, physical disconnect, or proper protection.
4. On timeout or invalid command, stop motion and enter a documented safe/fault state.
5. Software does not itself measure rail voltage unless suitable measurement hardware is installed and calibrated.

## Answer key — Session 06

1. **Unit test** checks a small function; **integration test** checks modules/interfaces working together.
2. Fault paths must be tested because failure cases can leave hardware active unexpectedly.
3. Final documentation includes source, README, pinout/wiring, test records, troubleshooting log, and demonstration evidence.
4. Compilation confirms syntax/build, not wiring correctness, sensor behavior, mechanical safety, or system-level behavior.
5. Suggested test cases: startup-safe, sensor inactive, sensor active, motor forward/reverse/stop, timeout, invalid sensor, pump simulation, operator stop.

## Practical projects and code

- [Session 01 — Blink](projects/session-01-blink/Session01_Blink.ino)
- [Session 02 — Sensor + Serial Monitor](projects/session-02-digital-io/Session02_SensorSerialMonitor.ino)
- [Session 03 — L298N motor control](projects/session-03-l298n-motor/Session03_L298N_SerialMotorControl.ino)
- [Session 04 — Sensor, servo, relay/pump interface](projects/session-04-sensors-servo-pump/Session04_SensorServoRelayDemo.ino)
- [Session 05 — Safe startup and timeout](projects/session-05-safe-startup/Session05_SafeStartupAndTimeout.ino)
- [Session 06 — Firefighting Robot integration demo](projects/session-06-firefighting-integration/Session06_FirefightingRobot_Demo.ino)

## Assessment rubric

The previously agreed weights are preserved:
- **20%** Technical knowledge
- **30%** Practical implementation
- **35%** Final project
- **15%** Teamwork and documentation

Suggested observable criteria:
- Knowledge: explains signals, functions, PWM, sensor polarity, driver role, and safe states.
- Practical: code compiles, outputs match expected behavior, testing is incremental, and wiring assumptions are checked.
- Final project: movement, sensor-driven decision, bounded actuator request, safe stop/fault path, and repeatable test evidence.
- Teamwork/documentation: clear pinout, code comments, task ownership, test logs, and concise handover.

## Important hardware safety

All example pin numbers are placeholders until checked against the team's actual wiring diagram. Verify exact board model, logic voltage, sensor output, driver truth table, motor/pump ratings, relay polarity, servo power, common-ground/interface requirements, and physical power disconnect. Test the pump in simulation first. The integrated example is a training skeleton and requires review before real hardware operation.
