#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Définir les broches pour le module RFID
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adresse I2C, 16 colonnes, 2 lignes

bool responseReceived = false;  // Variable pour suivre l'état de la réponse

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin();
  lcd.setBacklight(HIGH);  // Allumer le rétroéclairage dès le début
  lcd.print("Scanner une carte");
}

void loop() {
  // Vérifie si une nouvelle carte est présente
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }

    uid.toUpperCase();  // Pour s'assurer que l'UID est en majuscule
    Serial.println("UID reçu : " + uid);  // Afficher l'UID dans la console série

    lcd.clear();
    lcd.setBacklight(HIGH);
    lcd.print("Carte lue...");
    delay(500);

    // Attente de la réponse de Qt
    unsigned long startTime = millis();
    responseReceived = false;  // Réinitialiser la variable avant chaque tentative

    while (millis() - startTime < 5000) {  // Timeout de 5 secondes
      if (Serial.available() > 0) {
        String response = Serial.readStringUntil('\n');
        response.trim();  // Supprimer \r et espaces

        if (response == "Autorise") {
          lcd.clear();
          lcd.print("Access Granted");
          Serial.println("Réponse reçue : Autorise");
          responseReceived = true;
          break;
        } else if (response == "Refuse") {
          lcd.clear();
          lcd.print("Access Denied");
          Serial.println("Réponse reçue : Refuse");
          responseReceived = true;
          break;
        }
      }
    }

    // Si aucune réponse n'a été reçue dans le délai imparti
    if (!responseReceived) {
      lcd.clear();
      lcd.print("No response");
      Serial.println("Aucune réponse reçue dans le délai.");
    }

    delay(3000);  // Attendre avant prochain scan
    lcd.clear();
    lcd.print("Scanner une carte");
  }
}
