/*
 * OIROV Software Track — Session 02
 * Practical: Digital Input + Serial Monitor
 * Hardware counterpart: electrical fundamentals, logic levels, VCC/GND,
 * polarity, safe GPIO use.
 *
 * IMPORTANT:
 * - SENSOR_PIN is an example only; use the approved team pinout.
 * - Confirm module voltage compatibility before wiring.
 * - Many sensor modules are active-low; configure SENSOR_ACTIVE_LOW below
 *   only after testing/documenting the actual module.
 */

const int SENSOR_PIN = 2;             // Example pin; verify wiring
const bool SENSOR_ACTIVE_LOW = true;  // Set from real module test

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  Serial.println("OIROV Session 02: sensor monitor started");
  Serial.println("Check board pinout, voltage and sensor polarity.");
}

void loop() {
  const int rawState = digitalRead(SENSOR_PIN);
  const bool detected = SENSOR_ACTIVE_LOW
      ? (rawState == LOW)
      : (rawState == HIGH);

  Serial.print("Raw state: ");
  Serial.print(rawState);
  Serial.print(" | Interpreted state: ");
  Serial.println(detected ? "ACTIVE" : "INACTIVE");

  delay(200);
}

/*
 * Practice answers:
 * 1. pinMode(..., INPUT) configures a digital input.
 * 2. Active-low means the active condition is represented by LOW.
 * 3. GPIO voltage limits differ by board; ESP32 GPIO is generally 3.3 V logic
 *    and is not 5 V tolerant.
 * 4. Serial output lets us observe the raw signal before adding decision logic.
 */