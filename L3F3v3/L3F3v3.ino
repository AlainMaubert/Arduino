#include <Adafruit_NeoPixel.h>  // include the NeoPixel library.

#define LED_PIN 6   // set pin 6 on the Arduino as the LED control pin.
#define NUM_LEDS 8  // set the number of LEDs on the LED strip.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  colorWipe(strip.Color(255, 0, 0), 150); // Red wipe
  colorWipe(strip.Color(0, 255, 0), 150); // Green wipe
  colorWipe(strip.Color(0, 0, 255), 150); // Blue wipe
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
