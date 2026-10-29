# OIROV Software Training

Structured learning materials for the **OIROV Robotics Training Program — Software Track**. Aligned with the agreed Hardware Track sequence: **3 weeks, 2 sessions per week, 2 hours per session**, using Arduino Uno and ESP32. The final project is a **Firefighting Robot**.

## Trainer

- **Name:** Hazem Elshafey
- **Role:** Chief Technology Officer (CTO), OIROV Robotics
- **GitHub:** [@HBE-2206](https://github.com/HBE-2206)

## Course roadmap — aligned with Hardware Track

| Week | Session | Software topic | Hardware counterpart |
|---|---|---|---|
| 1 | 01 | Programming fundamentals, C/C++ basics, Arduino IDE, Blink | Robotics/components overview; Uno and ESP32 introduction |
| 1 | 02 | Digital I/O, HIGH/LOW, pin setup, Serial Monitor | Electrical fundamentals: voltage, current, polarity, VCC/GND, 3.3 V/5 V/12 V awareness |
| 2 | 03 | DC motor direction, PWM, driver control, safe stop | DC motors, H-Bridge, L298N, PWM |
| 2 | 04 | Sensor reading and decision logic; servo/relay/pump interfaces | IR/flame sensors, servo, relay, water pump |
| 3 | 05 | Safe startup, output defaults, timeouts, fault handling | Power distribution, buck converter, common ground, protection, wiring |
| 3 | 06 | Assembly integration, test cases, debugging and troubleshooting | Assembly, continuity checks, integration and troubleshooting |

## Session notebooks

1. [Session 01 — Introduction to Programming (C/C++)](./OIROV_Software_Session_01_Introduction_C_CPP.ipynb)
2. [Session 02 — Digital I/O & Electrical Logic](./sessions/Session-02_Digital-IO-and-Electrical-Logic.ipynb)
3. [Session 03 — DC Motors, H-Bridge & PWM](./sessions/Session-03_DC-Motors-HBridge-PWM.ipynb)
4. [Session 04 — Sensors & Actuators: IR/Flame, Servo, Relay/Pump](./sessions/Session-04_Sensors-Actuators-Relay-Pump-Servo.ipynb)
5. [Session 05 — Power Distribution, Ground & Protection](./sessions/Session-05_Power-Distribution-Ground-Protection.ipynb)
6. [Session 06 — Assembly, Integration & Troubleshooting](./sessions/Session-06_Assembly-Integration-Troubleshooting.ipynb)

## Final project — Firefighting Robot

The software work connects the agreed hardware modules: Arduino Uno/ESP32, IR/flame sensor, DC motor and L298N H-Bridge, servo, relay and water pump, plus the approved power-distribution and protection setup. Exact pin mappings, relay polarity, voltage limits, and driver behavior must follow the team's confirmed wiring diagram and component datasheets; example pin numbers in lesson code are placeholders.

## Assessment

- **20%** Technical knowledge
- **30%** Practical implementation
- **35%** Final project
- **15%** Teamwork and documentation

## Expected deliverables

- Readable source code and project README
- Confirmed pinout and wiring diagram
- Test cases with expected/actual results
- Troubleshooting log
- Final-project documentation and demonstration evidence

## Safety and hardware assumptions

- Disconnect power before changing wiring.
- Never power motors or pumps directly from microcontroller GPIO pins.
- Uno and ESP32 logic-voltage limits differ; ESP32 GPIO is generally 3.3 V logic and not 5 V tolerant.
- Check buck converter outputs with a multimeter before connecting loads.
- Confirm common ground/reference, relay polarity, driver ratings, and the approved power diagram with the hardware trainer.
- Keep a physical power disconnect accessible and protect electronics from water.
- Test motors with wheels lifted and start at a conservative command.
- Simulate pump activation before testing the real pump under supervision.

## How to use

Open each notebook in GitHub, Jupyter Notebook/JupyterLab, or Google Colab. The notebooks contain Markdown explanations and C/C++ code snippets; the code is not intended to run as Python cells. Copy Arduino sketches into Arduino IDE, select the exact board and port, then compile and upload.

---

**OIROV Robotics Training Program · Software Track**  
**Maintained by:** Hazem Elshafey · CTO, OIROV Robotics