#include <Servo.h> // Include the Servo library

Servo myServo; // Create a Servo object

const int potPin = A0; // Define the analog input pin for the potentiometer

void setup() {
myServo.attach(11); // Attach the servo to pin 10
}

void loop() {
int potValue = analogRead(potPin); // Read the potentiometer value (0-1023)

int servoAngle = map(potValue, 0, 1023, 0, 180); // Map potentiometer value to servo angle

myServo.write(servoAngle); // Set the servo to the calculated angle
delay(15); // Small delay for smooth movement
}