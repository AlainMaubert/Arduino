#include <SPI.h>
#include <MFRC522.h>

// Define RFID pins
#define RST_PIN 9
#define SS_PIN 10

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  SPI.begin();       // Initialize SPI bus
  rfid.PCD_Init();   // Initialize the RFID reader
  Serial.println("Place your RFID tag near the reader...");
}

void loop() {
  // Check if a new RFID card is present
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Print the UID (unique identifier) of the RFID tag
  Serial.print("RFID UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Halt communication with the tag
  rfid.PICC_HaltA();
}
