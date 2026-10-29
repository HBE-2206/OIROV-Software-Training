# OIROV Software Training

Structured learning materials for the **OIROV Robotics Training Program — Software Track**. This repository follows the original three-week plan: **2 sessions per week, 2 hours per session**, using Arduino Uno and ESP32 as the training platforms.

## Trainer

- **Name:** Hazem Elshafey
- **Role:** Chief Technology Officer (CTO), OIROV Robotics
- **Responsibility:** Software Track training
- **GitHub:** [@HBE-2206](https://github.com/HBE-2206)

## Course roadmap

| Week | Session | Topic | Main outcome |
|---|---|---|---|
| 1 | 01 | Programming Fundamentals | Understand algorithms, variables, conditions, loops, and upload Blink |
| 1 | 02 | Functions & Problem Solving | Break robot behavior into reusable, testable functions |
| 2 | 03 | Sensors & Data Processing | Read, inspect, calibrate, and interpret sensor data |
| 2 | 04 | Embedded Programming | Structure Arduino code, use timing, and debug reliably |
| 3 | 05 | Robot Movement & Control Logic | Design movement commands, motor mapping, and safe stopping |
| 3 | 06 | Integration & Testing | Integrate modules, test states, document results, and prepare the final project |

## Session notebooks

1. [Session 01 — Introduction to Programming (C/C++)](./OIROV_Software_Session_01_Introduction_C_CPP.ipynb)
2. [Session 02 — Functions & Problem Solving](./sessions/Session-02_Functions-and-Problem-Solving.ipynb)
3. [Session 03 — Sensors & Data Processing](./sessions/Session-03_Sensors-and-Data-Processing.ipynb)
4. [Session 04 — Embedded Programming](./sessions/Session-04_Embedded-Programming.ipynb)
5. [Session 05 — Robot Movement & Control Logic](./sessions/Session-05_Robot-Movement-and-Control-Logic.ipynb)
6. [Session 06 — Integration & Testing](./sessions/Session-06_Integration-and-Testing.ipynb)

## Final project: Firefighting Robot

The Software Track supports a robot that can move under control, detect an approved safe flame/thermal target or simulation, make a decision from sensor input, activate an extinguishing mechanism through appropriate driver hardware, and stop safely.

## Assessment

- **20%** Technical knowledge
- **30%** Practical implementation
- **35%** Final project
- **15%** Teamwork and documentation

## Expected deliverables

- README and understandable source code
- Wiring diagram / pinout and interface notes
- Test cases and recorded results
- Final-project documentation
- Evidence of safe integration between software and hardware

## How to use the notebooks

- View in GitHub, Jupyter Notebook/JupyterLab, or Google Colab.
- The notebooks are lesson notes containing C/C++ examples; those snippets are not Python code cells.
- Copy Arduino sketches into Arduino IDE, choose the exact board and port, then compile and upload.
- Verify pinouts, sensor voltage limits, motor driver/ESC ratings, and board-specific differences before connecting hardware.

## Safety rules

- Disconnect power before changing wiring.
- Never drive motors or pumps directly from microcontroller GPIO pins.
- Use properly rated drivers/ESCs and power distribution.
- Protect electronics from water and keep a physical power disconnect accessible.
- Test modules separately and use a safe simulated target or approved controlled setup.

---

**OIROV Robotics Training Program · Software Track**  
**Maintained by:** Hazem Elshafey · CTO, OIROV Robotics