// Pin definitions for motor control
const int motorBI = 10;
const int motorFI = 9;
const int potPin = A0; // Pin for the potentiometer

// Initialization function
void setup() {
  // Set motor control pins as OUTPUT
  pinMode(motorBI, OUTPUT);
  pinMode(motorFI, OUTPUT);
  pinMode(potPin, INPUT);
}

// Main loop function
void loop() {
  int potValue = analogRead(potPin); // Read the potentiometer value (0-1023)
  int motorSpeed = map(potValue, 0, 1023, 20, 150); // Map it to motor speed (20-150)

  // Rotate motor clockwise with speed based on potentiometer
  clockwise(motorSpeed);
}

// Function to rotate the motor clockwise
void clockwise(int Speed) {
  analogWrite(motorBI, 0); // Ensure reverse pin is off
  analogWrite(motorFI, Speed); // Set forward pin to the desired speed
}
