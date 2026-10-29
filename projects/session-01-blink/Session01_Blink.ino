/*
 * OIROV Software Track — Session 01
 * Practical: First Arduino Program (Blink)
 * Trainer: Hazem Elshafey | CTO, OIROV Robotics
 *
 * Hardware: Arduino Uno or compatible board with LED_BUILTIN.
 * Purpose: demonstrate setup(), loop(), OUTPUT, digitalWrite(), delay().
 * Safety: this sketch controls only the onboard LED; it does not drive motors.
 */

const int LED_PIN = LED_BUILTIN;
const unsigned long BLINK_INTERVAL_MS = 500;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_INTERVAL_MS);
  digitalWrite(LED_PIN, LOW);
  delay(BLINK_INTERVAL_MS);
}

/*
 * Practice answer:
 * - Faster blink: reduce BLINK_INTERVAL_MS, e.g. 200.
 * - Slower blink: increase it, e.g. 1000.
 * - setup() runs once after startup/reset; loop() repeats.
 */