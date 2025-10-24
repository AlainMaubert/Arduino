#include <SPI.h>
#include <MFRC522.h>

// Pin Definitions
#define RST_PIN 9       // Reset pin for MFRC522
#define SS_PIN 10       // Slave Select pin for MFRC522
#define GREEN_LED 2     // Green LED pin
#define RED_LED 3       // Red LED pin

// Create an MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);

//----------------------------------------------------------------------------------
// Predefined authorized RFID tag (replace with your actual RFID tag UID)
byte authorizedUID[] = {0x7D, 0x4, 0xC9, 0x1}; // Replace with your RFID tag UID
//SHOULD LOOK LIKE: byte authorizedUID[] = {0x14, 0x26, 0x78, 0x45};
//----------------------------------------------------------------------------------

void setup() {
  // Initialize Serial communication
  Serial.begin(115200);
  while (!Serial); // Wait for the Serial Monitor to open
  
  // Initialize SPI and MFRC522
  SPI.begin();
  mfrc522.PCD_Init();

  // Set LED pins as OUTPUT
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Turn off LEDs initially
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  
}

void loop() {
  
  Serial.println("Place an RFID tag near the reader."); // ask for an RFID key.

  // Check if a new RFID card is present
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Compare the scanned UID with the authorized UID
  if (isAuthorized(mfrc522.uid.uidByte, mfrc522.uid.size)) {
    // Authorized RFID tag detected
    
    //-------------------------------------------------------------------------------
    Serial.println("YOU CAN NOW ENTER ED 440.2!"); //replace this message with your secret message of your choice
    //-------------------------------------------------------------------------------

    blinkLED(GREEN_LED, 3); // Blink green LED 3 times
  } else {
    // Unauthorized RFID tag detected

    //-------------------------------------------------------------------------------
    Serial.println("YOU SHALL NOT PASS! Wrong RFID tag! CALLING PROTECTIVE SERVICES!"); //replace this message with a wrong ID message of your choice
    //-------------------------------------------------------------------------------

    blinkLED(RED_LED, 5); // Blink red LED 3 times
  }

  // Halt PICC (Passive Communication Card)
  mfrc522.PICC_HaltA();
}

// Function to compare the scanned UID with the authorized UID
bool isAuthorized(byte *scannedUID, byte length) {
  if (length != sizeof(authorizedUID)) {
    return false; // Length mismatch
  }

  for (byte i = 0; i < length; i++) {
    if (scannedUID[i] != authorizedUID[i]) {
      return false; // UID mismatch
    }
  }

  return true; // UID matches
}

// Function to blink an LED
void blinkLED(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(1000); // LED ON for 300ms
    digitalWrite(pin, LOW);
    delay(1000); // LED OFF for 300ms
  }
}
