#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address (0x27) if necessary (16 in the # of horizontal characters, 02 is the # of vertical lines)

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
// Display the first message
lcd.setCursor(0, 0); // Set cursor to the first column of the first row
  lcd.print("1ML1");
  lcd.setCursor(0, 1); // Move to the second row
  lcd.print("1ML2");

  delay(3000);

  // Clear the display
  lcd.clear();


  // Display the second message
  lcd.setCursor(0, 0); // Set cursor to the first column of the first row
  lcd.print("2ML1"); // Replace with your second message
  lcd.setCursor(0, 1); // Move to the second row
  lcd.print("2ML2");
 
  delay(3000); // Wait for 6 seconds

  // Clear the display
  lcd.clear();
 

}