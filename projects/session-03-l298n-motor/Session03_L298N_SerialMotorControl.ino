/*
 * OIROV Software Track — Session 03
 * Practical: DC motor direction + PWM command using an L298N-style driver.
 * Hardware counterpart: DC motor, H-Bridge, L298N, PWM.
 *
 * EXAMPLE PIN MAP ONLY — must match the team's approved wiring diagram.
 * This is written for Arduino Uno-style analogWrite(). ESP32 PWM APIs differ
 * by Arduino core/version; do not assume identical behavior.
 *
 * Safety:
 * - Never power a motor from a GPIO pin.
 * - Keep wheels lifted, secure the chassis, start at low PWM.
 * - Confirm driver/motor voltage and current ratings and the stop truth table.
 * - Disconnect power before changing wiring.
 */

const int ENA_PIN = 5;   // Example PWM pin; verify board
const int IN1_PIN = 7;   // Example only
const int IN2_PIN = 8;   // Example only
const int TEST_PWM = 90; // Conservative starting command, not a speed guarantee

void stopMotor() {
  analogWrite(ENA_PIN, 0);
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
}

void setForward(int pwm) {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  analogWrite(ENA_PIN, constrain(pwm, 0, 255));
}

void setReverse(int pwm) {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  analogWrite(ENA_PIN, constrain(pwm, 0, 255));
}

void setup() {
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  stopMotor();

  Serial.begin(9600);
  Serial.println("OIROV Session 03 — L298N motor test");
  Serial.println("Commands: F=forward, B=reverse, S=stop");
  Serial.println("Test only with wheels lifted and trainer approval.");
}

void loop() {
  if (Serial.available() > 0) {
    const char command = Serial.read();

    if (command == 'F' || command == 'f') {
      setForward(TEST_PWM);
      Serial.println("Forward command");
    } else if (command == 'B' || command == 'b') {
      setReverse(TEST_PWM);
      Serial.println("Reverse command");
    } else if (command == 'S' || command == 's') {
      stopMotor();
      Serial.println("Stop command");
    }
  }
}

/*
 * Practical answer:
 * - The H-Bridge switches motor current direction using driver inputs.
 * - PWM is a switching command used to vary average drive; it is not a
 *   guarantee of exact motor RPM.
 * - Reverse direction if physical motor polarity/mapping requires it, only
 *   after checking the wiring and driver truth table.
 */