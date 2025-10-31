#include <Stepper.h>  // Include the Stepper library

#define STEPS 2038                   // Define the number of steps per revolution for the motor
Stepper stepper(STEPS, 4, 5, 6, 7);  // Initialize stepper object and set pin connections (IN1, IN3, IN2, IN4)

void setup() {
}

void loop() {
  // Rotate clockwise at 5 RPM
  stepper.setSpeed(13);
  stepper.step(STEPS);  // Rotate one full revolution clockwise
  delay(1000);          // Wait for 1 second

}
