#define BUZZER_PIN 10  // Pin connected to the buzzer
#define BUTTON_PIN 2   // Pin connected to the button

int frequencies[] = {0, 500, 1000, 1500}; // Array of frequencies (the higher the number, the higher the frequency)
int currentFrequencyIndex = 0; // Index to track the current frequency
bool buttonState = false;      // To store the current button state
bool lastButtonState = false;  // To store the previous button state

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer pin as an output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set the button pin as an input with internal pull-up
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN); // Read the button state

  if (buttonState == LOW && lastButtonState == HIGH) { // Detect button press
    currentFrequencyIndex++; // Move to the next frequency
    if (currentFrequencyIndex >= (sizeof(frequencies) / sizeof(frequencies[0]))) {
      currentFrequencyIndex = 0; // Wrap around to the first frequency
    }
    delay(200); // Debounce delay
  }

  lastButtonState = buttonState; // Update the last button state

  // Play the current frequency
  tone(BUZZER_PIN, frequencies[currentFrequencyIndex]);
}

