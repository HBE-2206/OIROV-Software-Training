# OIROV Software Training

Complete practical learning package for the **OIROV Robotics Training Program — Software Track**, aligned with the agreed Hardware Track. The program runs for **3 weeks, 2 sessions per week, 2 hours per session**. Platforms: **Arduino Uno and ESP32**. Final project: **Firefighting Robot**.

## Trainer

- **Name:** Hazem Elshafey
- **Role:** Chief Technology Officer (CTO), OIROV Robotics
- **GitHub:** [@HBE-2206](https://github.com/HBE-2206)

## Course roadmap — Software ↔ Hardware

| Week | Session | Software content | Hardware counterpart |
|---|---|---|---|
| 1 | 01 | Programming fundamentals, C/C++ basics, Arduino IDE, Blink | HW01 — Robotics architecture and components, Uno/ESP32 overview |
| 1 | 02 | Digital I/O, logic levels, sensor output, Serial Monitor | HW02 — Voltage/current/resistance, polarity, VCC/GND, multimeter |
| 2 | 03 | DC motor direction, PWM, stop command, driver control | HW03 — DC motors, H-Bridge/L298N, PWM |
| 2 | 04 | IR/flame sensor, servo, relay/pump software interfaces | HW04 — Sensors and actuators |
| 3 | 05 | Safe startup, timeouts, fault states, power-aware software | HW05 — Power distribution, buck converter, common ground, protection |
| 3 | 06 | Integration, testing, debugging, troubleshooting, final demo | HW06 — Assembly, continuity checks, integration, troubleshooting |

## Session notebooks

Each session includes learning outcomes, explanations, practical tasks, review questions, project links, expected results, and an answer key section.

1. [Session 01 — Programming Fundamentals](./OIROV_Software_Session_01_Introduction_C_CPP.ipynb)
2. [Session 02 — Digital I/O & Electrical Logic](./sessions/Session-02_Digital-IO-and-Electrical-Logic.ipynb)
3. [Session 03 — DC Motors, H-Bridge & PWM](./sessions/Session-03_DC-Motors-HBridge-PWM.ipynb)
4. [Session 04 — Sensors & Actuators: IR/Flame, Servo, Relay/Pump](./sessions/Session-04_Sensors-Actuators-Relay-Pump-Servo.ipynb)
5. [Session 05 — Power Distribution, Ground & Protection](./sessions/Session-05_Power-Distribution-Ground-Protection.ipynb)
6. [Session 06 — Assembly, Integration & Troubleshooting](./sessions/Session-06_Assembly-Integration-Troubleshooting.ipynb)


## Quick answer key (README reference)

### Session 01 — Programming Fundamentals
- A program is executable instructions; an algorithm is an ordered problem-solving method.
- A variable stores a value under a name; a data type describes the value representation.
- `x > 5` is true only when x is strictly greater than 5.
- `for (int i = 0; i < 4; i++)` repeats four times.
- `setup()` runs once after startup/reset; `loop()` repeats.
- Motors and pumps require suitable driver hardware and power; do not connect them directly to GPIO.

### Session 02 — Digital I/O
- `pinMode(pin, INPUT)` configures a digital input.
- Active-low means the active state is LOW; verify module behavior.
- Serial Monitor helps inspect raw values before adding decision logic.
- ESP32 GPIO is generally 3.3 V logic and is not 5 V tolerant.

### Session 03 — DC Motor / H-Bridge / PWM
- An H-Bridge/driver switches motor current direction.
- PWM varies the switching duty cycle; it does not guarantee exact RPM.
- Verify motor direction and stop behavior against the actual driver truth table.
- Test with wheels lifted and a physical disconnect accessible.

### Session 04 — Sensors / Servo / Relay / Pump
- Keep raw sensor reading separate from decision logic.
- Verify sensor polarity and relay active level before connecting a load.
- A pump needs a properly rated driver/relay and power circuit.
- Invalid input or timeout should return the system to a defined safe state.

### Session 05 — Power / Startup / Fault Handling
- Common ground provides a shared signal reference where the approved interface requires it.
- Measure buck-converter output before connecting loads.
- Software cannot replace proper wiring, protection, component ratings, or a physical disconnect.
- A timeout or invalid command should trigger the documented safe/fault state.

### Session 06 — Integration / Troubleshooting
- Unit tests check a function; integration tests check modules and interfaces working together.
- A successful compile does not prove correct wiring or safe system behavior.
- Test startup, inactive/active sensor, motor direction/stop, timeout, invalid input, pump simulation, and operator stop.
- Final handover includes source code, README, approved pinout/wiring, test results, troubleshooting notes, and demonstration evidence.

For full worked explanations, grading criteria, and session-by-session test ideas, see [INSTRUCTOR_GUIDE_AND_ANSWER_KEY.md](./INSTRUCTOR_GUIDE_AND_ANSWER_KEY.md).

## Practical Arduino code — ready to review and adapt

1. [Project 01 — Blink](./projects/session-01-blink/Session01_Blink.ino)
2. [Project 02 — Sensor + Serial Monitor](./projects/session-02-digital-io/Session02_SensorSerialMonitor.ino)
3. [Project 03 — L298N motor control](./projects/session-03-l298n-motor/Session03_L298N_SerialMotorControl.ino)
4. [Project 04 — Sensor, servo, relay/pump interface](./projects/session-04-sensors-servo-pump/Session04_SensorServoRelayDemo.ino)
5. [Project 05 — Safe startup and timeout](./projects/session-05-safe-startup/Session05_SafeStartupAndTimeout.ino)
6. [Project 06 — Firefighting Robot integration demo](./projects/session-06-firefighting-integration/Session06_FirefightingRobot_Demo.ino)

## Instructor guide, solved questions and rubric

See [INSTRUCTOR_GUIDE_AND_ANSWER_KEY.md](./INSTRUCTOR_GUIDE_AND_ANSWER_KEY.md) for:
- Answer key for all six sessions.
- Practical project links and expected behaviors.
- Suggested test cases and acceptance criteria.
- Teaching sequence based on learning outcomes, worked examples, guided practice, formative assessment, reflection, and project-based learning.
- Assessment rubric and hardware safety reminders.

## Final project — Firefighting Robot

The software sequence builds from Blink and digital inputs to motor control, sensor/servo/relay interfaces, safe startup/fault handling, and a staged integration demo.

### Assessment weights (agreed)

- **20%** Technical knowledge
- **30%** Practical implementation
- **35%** Final project
- **15%** Teamwork and documentation

### Expected final deliverables

- Readable source code and README.
- Approved pinout/wiring diagram and interface notes.
- Test cases with expected and actual results.
- Troubleshooting log.
- Final project documentation and demonstration evidence.

## Important safety and compatibility notes

- Pin numbers in examples are placeholders until checked against the team's approved wiring diagram.
- Verify exact board model, logic voltage, sensor output level, driver truth table, motor/pump ratings, relay polarity, servo power, and interface/ground requirements.
- Arduino Uno and ESP32 differ; ESP32 GPIO is generally 3.3 V logic and is not 5 V tolerant.
- Do not power motors or pumps directly from microcontroller GPIO pins.
- Measure buck converter outputs before connecting loads.
- Test the pump request in simulation first. Real pump operation requires hardware review and trainer supervision.
- Test motors with wheels lifted, begin at a conservative command, and keep a physical power disconnect accessible.
- The integrated sketch is a teaching skeleton, not a certified safety controller. It must be reviewed against the real hardware before use.

## How to use

Open the notebooks in GitHub, Jupyter Notebook/JupyterLab, or Google Colab. The notebooks contain Markdown and C/C++ examples; those snippets are not Python cells. Copy Arduino sketches into Arduino IDE, select the exact board and port, compile, and test one subsystem at a time.

---

**OIROV Robotics Training Program · Software Track**  
**Maintained by:** Hazem Elshafey · CTO, OIROV Robotics