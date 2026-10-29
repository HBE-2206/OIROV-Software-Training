/*
 * OIROV Software Track — Session 04
 * Practical: sensor reading + servo positioning + relay interface.
 * Hardware counterpart: IR/flame sensor, servo, relay, water pump.
 *
 * This is a supervised bench demonstration. Keep the pump output disabled
 * until the relay module polarity, wiring, ratings, and power circuit are
 * verified by the hardware trainer. Prefer testing with an LED/Serial output
 * before connecting the real pump.
 *
 * All pin numbers are examples and must match the approved wiring plan.
 */

#include <Servo.h>

const int SENSOR_PIN = 2;          // Example only
const int SERVO_PIN = 9;           // Example only; verify board and wiring
const int RELAY_PIN = 4;           // Example only
const bool SENSOR_ACTIVE_LOW = true; 
const bool RELAY_ACTIVE_LOW = true;

// Keep false for initial testing. Set true only after hardware approval.
const bool ALLOW_REAL_PUMP_OUTPUT = false;

const unsigned long PUMP_MAX_ON_MS = 1500;
const int SERVO_HOME_DEG = 90;
const int SERVO_TARGET_DEG = 45;

Servo nozzleServo;
bool pumpOn = false;
unsigned long pumpStartedAt = 0;

bool targetDetected(int rawState) {
  return SENSOR_ACTIVE_LOW ? (rawState == LOW) : (rawState == HIGH);
}

void setPump(bool on) {
  pumpOn = on;
  const int activeLevel = RELAY_ACTIVE_LOW ? LOW : HIGH;
  const int inactiveLevel = RELAY_ACTIVE_LOW ? HIGH : LOW;

  if (!ALLOW_REAL_PUMP_OUTPUT) {
    Serial.println(on ? "SIMULATED PUMP REQUEST ON" : "SIMULATED PUMP REQUEST OFF");
    return;
  }
  digitalWrite(RELAY_PIN, on ? activeLevel : inactiveLevel);
}

void stopPump() {
  setPump(false);
}

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);

  nozzleServo.attach(SERVO_PIN);
  nozzleServo.write(SERVO_HOME_DEG);

  Serial.println("OIROV Session 04 — sensor/servo/relay demo");
  Serial.println("Pump output is simulation-only until hardware is approved.");
}

void loop() {
  const bool detected = targetDetected(digitalRead(SENSOR_PIN));

  if (detected && !pumpOn) {
    Serial.println("Target condition detected");
    nozzleServo.write(SERVO_TARGET_DEG);
    pumpStartedAt = millis();
    setPump(true);
  }

  if (pumpOn && millis() - pumpStartedAt >= PUMP_MAX_ON_MS) {
    stopPump();
    nozzleServo.write(SERVO_HOME_DEG);
    Serial.println("Maximum activation interval reached; output stopped");
  }

  delay(20);
}

/*
 * Required practical verification before any real actuator:
 * 1. Test sensor inactive/active states and confirm polarity.
 * 2. Test servo with no mechanical obstruction and a safe range.
 * 3. Verify relay ON/OFF polarity without pump attached.
 * 4. Verify relay contact rating and pump supply/driver circuit.
 * 5. Only then enable real output under trainer supervision.
 */