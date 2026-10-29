/*
 * OIROV Software Track — Session 06
 * Final practical integration demo: Firefighting Robot control skeleton.
 * Hardware counterpart: assembly, continuity, integration, troubleshooting.
 *
 * IMPORTANT:
 * - Example pin map only; replace after reviewing the team's approved wiring.
 * - Start in simulation mode: the relay/pump output is NOT enabled by default.
 * - Test sensor and motor functions separately before combining.
 * - The sensor's active level, motor direction, driver behavior, relay polarity,
 *   and power system must be verified on the real hardware.
 * - This is a training skeleton, not a certified autonomous safety controller.
 */

#include <Servo.h>

const int SENSOR_PIN = 2;       // Example only
const int MOTOR_EN_PIN = 5;     // Example PWM pin for Uno-style board
const int MOTOR_IN1_PIN = 7;    // Example only
const int MOTOR_IN2_PIN = 8;    // Example only
const int SERVO_PIN = 9;        // Example only
const int RELAY_PIN = 4;        // Example only

const bool SENSOR_ACTIVE_LOW = true;
const bool RELAY_ACTIVE_LOW = true;
const bool ALLOW_REAL_PUMP_OUTPUT = false; // Keep false until supervised approval

const int SEARCH_PWM = 80; // Conservative command; not a calibrated speed
const unsigned long PUMP_DURATION_MS = 1500;
const unsigned long SENSOR_SETTLE_MS = 100;

enum RobotState {
  SAFE_IDLE,
  SEARCHING,
  TARGET_CONFIRM,
  EXTINGUISHING,
  FAULT
};

RobotState robotState = SAFE_IDLE;
Servo nozzleServo;
unsigned long stateStartedAt = 0;
unsigned long lastSensorSampleAt = 0;
bool targetConfirmed = false;

bool readTarget() {
  const int raw = digitalRead(SENSOR_PIN);
  return SENSOR_ACTIVE_LOW ? (raw == LOW) : (raw == HIGH);
}

void stopDrive() {
  analogWrite(MOTOR_EN_PIN, 0);
  digitalWrite(MOTOR_IN1_PIN, LOW);
  digitalWrite(MOTOR_IN2_PIN, LOW);
}

void searchDrive() {
  digitalWrite(MOTOR_IN1_PIN, HIGH);
  digitalWrite(MOTOR_IN2_PIN, LOW);
  analogWrite(MOTOR_EN_PIN, SEARCH_PWM);
}

void setPump(bool on) {
  if (!ALLOW_REAL_PUMP_OUTPUT) {
    Serial.println(on ? "SIMULATED: pump request ON" : "SIMULATED: pump request OFF");
    return;
  }
  const int onLevel = RELAY_ACTIVE_LOW ? LOW : HIGH;
  const int offLevel = RELAY_ACTIVE_LOW ? HIGH : LOW;
  digitalWrite(RELAY_PIN, on ? onLevel : offLevel);
}

void enterFault(const char* reason) {
  stopDrive();
  setPump(false);
  robotState = FAULT;
  Serial.print("FAULT: ");
  Serial.println(reason);
}

void changeState(RobotState nextState) {
  robotState = nextState;
  stateStartedAt = millis();
}

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(MOTOR_EN_PIN, OUTPUT);
  pinMode(MOTOR_IN1_PIN, OUTPUT);
  pinMode(MOTOR_IN2_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  stopDrive();
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);

  nozzleServo.attach(SERVO_PIN);
  nozzleServo.write(90);

  Serial.begin(9600);
  Serial.println("OIROV Firefighting Robot integration demo");
  Serial.println("Pump is simulation-only by default. Verify hardware before enabling.");
  changeState(SAFE_IDLE);
}

void loop() {
  const unsigned long now = millis();

  switch (robotState) {
    case SAFE_IDLE:
      stopDrive();
      setPump(false);
      // Start search by sending 'S' in Serial Monitor after safety checks.
      if (Serial.available() > 0) {
        const char c = Serial.read();
        if (c == 'S' || c == 's') {
          Serial.println("Search started");
          changeState(SEARCHING);
        }
      }
      break;

    case SEARCHING:
      if (now - lastSensorSampleAt >= SENSOR_SETTLE_MS) {
        lastSensorSampleAt = now;
        if (readTarget()) {
          stopDrive();
          targetConfirmed = false;
          Serial.println("Sensor active; confirming target");
          changeState(TARGET_CONFIRM);
        } else {
          searchDrive();
        }
      }
      if (Serial.available() > 0) {
        const char c = Serial.read();
        if (c == 'X' || c == 'x') {
          stopDrive();
          changeState(SAFE_IDLE);
          Serial.println("Operator stop: IDLE");
        }
      }
      break;

    case TARGET_CONFIRM:
      stopDrive();
      // Simple second observation after a short settling interval.
      if (now - stateStartedAt >= 250) {
        targetConfirmed = readTarget();
        if (targetConfirmed) {
          Serial.println("Target confirmed; beginning bounded extinguishing demo");
          nozzleServo.write(45);
          setPump(true);
          changeState(EXTINGUISHING);
        } else {
          Serial.println("Target not confirmed; return to search");
          changeState(SEARCHING);
        }
      }
      break;

    case EXTINGUISHING:
      stopDrive();
      if (now - stateStartedAt >= PUMP_DURATION_MS) {
        setPump(false);
        nozzleServo.write(90);
        Serial.println("Extinguishing interval ended; returning to IDLE");
        changeState(SAFE_IDLE);
      }
      break;

    case FAULT:
      stopDrive();
      setPump(false);
      // Recovery is intentionally manual/reviewed; reset the board after
      // investigating the cause and completing the team's safety checklist.
      break;
  }
}

/*
 * Integration test plan:
 * 1. Compile with pump output disabled.
 * 2. Test sensor polarity and Serial Monitor messages only.
 * 3. Test motor direction at low PWM with wheels lifted.
 * 4. Test servo travel with no obstruction.
 * 5. Verify relay OFF polarity with no pump connected.
 * 6. Simulate target absent/present and operator stop.
 * 7. Test the real pump only after power, relay, and water-safety checks.
 *
 * Limitations to address before real use:
 * - This demo has no independent hardware emergency stop.
 * - The simple sensor confirmation is not robust target classification.
 * - Add actual command-loss, sensor-fault, and board-specific PWM handling.
 * - Verify all output safe states against the actual driver truth tables.
 */