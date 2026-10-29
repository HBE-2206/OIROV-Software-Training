/*
 * OIROV Software Track — Session 05
 * Practical: safe startup, command timeout and fault-state pattern.
 * Hardware counterpart: power distribution, buck converter, common ground,
 * protection, correct rails, and safe wiring.
 *
 * This sketch demonstrates software policy; it does not measure rail voltage.
 * A voltage-monitor sensor and calibrated thresholds would be required for
 * actual low-voltage detection. Never substitute software for fuses,
 * suitable wire/driver ratings, a physical disconnect, or correct power design.
 */

const int STATUS_LED_PIN = LED_BUILTIN;
const unsigned long COMMAND_TIMEOUT_MS = 5000;

enum SystemState {
  IDLE,
  ACTIVE,
  FAULT
};

SystemState state = IDLE;
unsigned long lastValidCommandAt = 0;

void enterSafeState(const char* reason) {
  state = FAULT;
  digitalWrite(STATUS_LED_PIN, LOW);
  Serial.print("FAULT: ");
  Serial.println(reason);
  Serial.println("Outputs should remain in the hardware-approved safe state.");
}

void setup() {
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, LOW);

  Serial.begin(9600);
  Serial.println("OIROV Session 05 — safe startup demo");
  Serial.println("Commands: A=active demo, I=idle/reset demo");
  state = IDLE;
  lastValidCommandAt = millis();
}

void loop() {
  if (Serial.available() > 0) {
    const char command = Serial.read();

    if (command == 'A' || command == 'a') {
      state = ACTIVE;
      lastValidCommandAt = millis();
      digitalWrite(STATUS_LED_PIN, HIGH);
      Serial.println("ACTIVE demo state (LED only)");
    } else if (command == 'I' || command == 'i') {
      state = IDLE;
      digitalWrite(STATUS_LED_PIN, LOW);
      lastValidCommandAt = millis();
      Serial.println("IDLE state");
    }
  }

  if (state == ACTIVE && millis() - lastValidCommandAt > COMMAND_TIMEOUT_MS) {
    enterSafeState("command timeout");
  }

  // For this training demo, a new A command is needed after FAULT to resume.
  // Real system reset/recovery policy must be defined and reviewed separately.
}

/*
 * Practice answers:
 * - Startup must set outputs to defined safe levels before active behavior.
 * - Timeout handles commands that stop arriving.
 * - A software fault state cannot replace a physical power disconnect.
 * - A buck converter output must be measured before connecting sensitive loads.
 */