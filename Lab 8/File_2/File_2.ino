/*
  Program: CS 207 / CTCH Interactive Gadgets - Lab 8: Displays

  Description:
  ------------------------------------------
  This program demonstrates the use of an I2C 16x2 LCD display with an Arduino.

  1. Displays two double-line messages alternately:
     - Message 1:
         Line 1: "CS 207 Gadgets!"
         Line 2: "Lab 8: Displays"
     - Message 2:
         Line 1: "Potentiometer:"
         Line 2: shows the live analog value and corresponding voltage.

  2. Each message is displayed for 6 seconds.

  3. If a line exceeds 16 characters, it scrolls automatically across the display.

  Hardware:
  ------------------------------------------
  - LCD 16x2 with I2C interface (Address: 0x27)
  - Potentiometer connected to analog pin A2
      * One outer leg to +5V
      * Other outer leg to GND
      * Middle (wiper) leg to A2

  Author: Alain Maubert
  Date: November 06, 2025
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define POT_PIN A2  // Pin connected to the potentiometer

LiquidCrystal_I2C lcd(0x27, 16, 2); // (Address, columns, rows)

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // --- Message 1: Static double-line message ---
  displayMessage("CS 207 Gadgets!", "Lab 8: Displays");
  delay(6000); // Wait 6 seconds

  // --- Message 2: Live potentiometer values ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Potentiometer:");

  unsigned long startTime = millis();
  while (millis() - startTime < 6000) {  // Display live values for 6 seconds
    int potValue = analogRead(POT_PIN);
    float voltage = potValue * (5.0 / 1023.0);

    lcd.setCursor(0, 1);
    lcd.print("Val:");
    lcd.print(potValue);
    lcd.print("  ");
    lcd.print(voltage, 2); // 2 decimal places
    lcd.print("V  ");

    delay(200); // Update about 5 times per second
  }
}

// --- Function to display a two-line message (scrolls if too long) ---
void displayMessage(String line1, String line2) {
  lcd.clear();

  if (line1.length() <= 16) {
    lcd.setCursor(0, 0);
    lcd.print(line1);
  } else {
    scrollLine(line1, 0);
  }

  if (line2.length() <= 16) {
    lcd.setCursor(0, 1);
    lcd.print(line2);
  } else {
    scrollLine(line2, 1);
  }
}

// --- Function to scroll a long line horizontally ---
void scrollLine(String text, int row) {
  text = text + "                "; // Add spaces for smooth scroll
  for (int i = 0; i < text.length() - 15; i++) {
    lcd.setCursor(0, row);
    lcd.print(text.substring(i, i + 16));
    delay(300);
  }
}
