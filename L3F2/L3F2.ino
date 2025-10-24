#include <Adafruit_NeoPixel.h>  // Include the NeoPixel library.

#define BUTTON_PIN 2  // Define a pin to be used as a button.

#define LED_PIN 6   // Set pin 6 on the Arduino as the LED control pin.
#define NUM_LEDS 8  // Set the number of LEDs on the LED strip.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int currentColor = 0;  // Set up a variable to change the color with a button.

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Use internal pull-up
  strip.begin();
  strip.show();
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    currentColor = (currentColor + 1) % 3;  // Cycle through 0, 1, 2
    delay(200);                             // Debounce delay
  }

  if (currentColor == 0) {
    setStripColor(255, 0, 0);  // Red
  } else if (currentColor == 1) {
    setStripColor(0, 255, 0);  // Green
  } else if (currentColor == 2) {
    setStripColor(0, 0, 255);  // Blue
  }
}

void setStripColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}

