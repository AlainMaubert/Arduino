#include <Wire.h>                   // Include the wire library for I2C communication
#include <Adafruit_GFX.h>            // Include the graphics library
#include <Adafruit_SSD1306.h>        // Include the SSD1306 OLED display library

// Pin definitions for the ultrasonic sensor
const int trigPin = 9;  // Trigger pin for the ultrasonic sensor
const int echoPin = 10; // Echo pin for the ultrasonic sensor

// Create an SSD1306 display object
#define SCREEN_WIDTH 128    // OLED display width in pixels
#define SCREEN_HEIGHT 64    // OLED display height in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // Display object

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Stay here if initialization failed
  }
  
  display.display();  // Initialize the display
  delay(2000);        // Wait for 2 seconds to let the display initialize
}

void loop() {
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);  // Make sure the trigger pin is low
  delayMicroseconds(2);        // Wait for a short time
  digitalWrite(trigPin, HIGH); // Send a high pulse
  delayMicroseconds(10);       // Pulse duration of 10ms
  digitalWrite(trigPin, LOW);  // Set the trigger pin back to low

  // Measure the duration of the pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the time it takes for the pulse to return
  // The speed of sound is 343 meters per second, or 0.0343 cm per microsecond
  long distance = duration * 0.0343 / 2;

  // Clear the display and print the distance
  display.clearDisplay();
  display.setCursor(0, 0);  // Set the cursor to the top-left corner
  display.setTextSize(1);    // Set the text size to normal
  display.setTextColor(SSD1306_WHITE);  // Set the text color to white
  
  // Display the measured distance on the OLED
  display.print("Distance: ");
  display.print(distance);
  display.println(" cm");

  // Update the display
  display.display();
  
  // Wait for a short time before the next measurement
  delay(500);
}
