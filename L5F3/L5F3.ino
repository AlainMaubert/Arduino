#define SW_PIN 2   // Button pin
#define RX_PIN A0  // Horizontal axis pin
#define RY_PIN A1  // Vertical axis pin

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);  // Button uses internal pull-up resistor
  pinMode(RX_PIN, INPUT);        // Horizontal axis pin set as input
  pinMode(RY_PIN, INPUT);        // Vertical axis pin set as input

  Serial.begin(9600);  // Start serial communication at 9600 baud
}

void loop() {
  int xValue = analogRead(RX_PIN);  // Read horizontal axis value
  int yValue = analogRead(RY_PIN);  // Read vertical axis value
  int buttonState = digitalRead(SW_PIN);  // Read button state

  Serial.print("X: ");
  Serial.print(xValue);  // Print horizontal axis value
  Serial.print(" | Y: ");
  Serial.print(yValue);  // Print vertical axis value

  if (buttonState == LOW) {
    Serial.println(" | Button: Pressed");  // Button is pressed
  } else {
    Serial.println(" | Button: Not Pressed");  // Button is not pressed
  }

  delay(100);  // Short delay for readability
}
