#define POT_PIN A0          // Pin connected to the potentiometer
#define BUTTON_PIN 2        // Pin connected to the button

void setup() {
  Serial.begin(9600);                // Initialize serial communication
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with internal pull-up
}

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(POT_PIN);
  float voltage = potValue * (5.0 / 1023.0); // Convert to voltage

  // Read the button state
  bool buttonState = digitalRead(BUTTON_PIN); // HIGH if not pressed, LOW if pressed

  // Print the potentiometer readings and button state to the serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print(" | Button State: ");
  Serial.println(buttonState == LOW ? "Pressed" : "Not Pressed");

  delay(200); // Short delay to smooth readings
}

