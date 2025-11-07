#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address (0x27) if necessary (16 in the # of horizontal characters, 02 is the # of vertical lines)

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); // Set cursor to the first column of the first row
  lcd.print("CS 207 Gadgets!");
  lcd.setCursor(0, 1); // Move to the second row
  lcd.print("Lab 8: Displays");
}

void loop() {
  // No additional code needed for static display
}
