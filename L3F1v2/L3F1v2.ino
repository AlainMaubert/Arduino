#include <Adafruit_NeoPixel.h> // include the NeoPixel library.

#define LED_PIN 6 // set pin 6 on the Arduino as the LED control pin.
#define NUM_LEDS 8 // set the number of LEDs on the LED strip.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); //Start the LED function.
  strip.show(); // Initialize all LEDs to off
}

void loop() {
  setStripColor(255, 0, 0); // Red
  delay(1000);
  setStripColor(0, 255, 0); // Green
  delay(1000);
  setStripColor(0, 0, 255); // Blue
  delay(1000);
}

void setStripColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}

