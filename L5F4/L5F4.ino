#include <Adafruit_NeoPixel.h>

#define SW_PIN 2      // Button pin
#define RX_PIN A0     // Horizontal axis pin
#define RY_PIN A1     // Vertical axis pin
#define LED_PIN 6     // NeoPixel data pin
#define NUM_LEDS 8    // Number of LEDs on the strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(SW_PIN, INPUT_PULLUP);  // Button uses internal pull-up resistor
  pinMode(RX_PIN, INPUT);         // Horizontal axis pin set as input
  pinMode(RY_PIN, INPUT);         // Vertical axis pin set as input

  strip.begin();                  // Initialize the NeoPixel strip
  strip.show();                   // Clear the strip
  Serial.begin(9600);             // Start serial communication
}

void loop() {
  int xValue = analogRead(RX_PIN);  // Read horizontal axis value
  int yValue = analogRead(RY_PIN);  // Read vertical axis value
  int buttonState = digitalRead(SW_PIN);  // Read button state

  // Map joystick values to RGB color for full color wheel
  int red = map(xValue, 0, 1023, 0, 255);      // Map X axis to Red channel
  int green = map(yValue, 0, 1023, 0, 255);    // Map Y axis to Green channel
  int blue = map((xValue + yValue) / 2, 0, 1023, 0, 255);  // Combine X and Y axis for Blue channel

  // Output joystick values to Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  if (buttonState == LOW) {
    Serial.println(" | Button: Pressed");
  } else {
    Serial.println(" | Button: Not Pressed");
  }

  // Set LED colors based on button state
  if (buttonState == LOW) {
    // Button pressed: Turn all LEDs white
    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(255, 255, 255));
    }
  } else {
    // Button not pressed: Set LEDs based on joystick values to create RGB wheel
    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(red, green, blue));
    }
  }

  strip.show(); // Update the LED strip after all colors are set
  delay(100);   // Small delay for stability
}
