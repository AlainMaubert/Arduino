#define LIGHT_PIN A5
#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  int lightLevel = analogRead(LIGHT_PIN);

  // Print the light level to the serial monitor
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel < 600) { // Adjust threshold as needed
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}
