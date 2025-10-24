#define BUTTON_PIN 2  // The pin connected to the button
#define LED_PIN 9    // The pin connected to the LED

bool ledState = false; // This variable keeps track of whether the LED is ON or OFF

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set the button pin to input with a built-in pull-up resistor
  pinMode(LED_PIN, OUTPUT);          // Set the LED pin as an output
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) { // Check if the button is pressed (LOW means pressed)
    ledState = !ledState;              // Flip the LED state (ON becomes OFF, OFF becomes ON)
    digitalWrite(LED_PIN, ledState);   // Update the LED to match the new state
    delay(2000);                        // Wait a short time to avoid double presses (debouncing)
  }
}

