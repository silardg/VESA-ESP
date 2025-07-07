#include <SD.h>
#include <SPI.h>

// Define pins
#define SD_CS_PIN 40   // CD/DAT3 (CS)
#define MOSI_PIN 38    // CMD (MOSI)
#define MISO_PIN 39    // DAT0 (MISO)
#define SCK_PIN 45     // CLK (SCK)

// Create a custom SPI instance
SPIClass mySPI(FSPI);

void setup() {
  Serial.begin(115200);

  // Initialize SPI with custom pins
  mySPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SD_CS_PIN);

  // Initialize SD card
  if (!SD.begin(SD_CS_PIN, mySPI)) {
    Serial.println("SD Card initialization failed!");
    return;
  }
  Serial.println("SD Card initialized successfully.");

  // List files on the SD card
  File root = SD.open("/");
  printDirectory(root, 0);
}

void loop() {
  // Nothing to do here
}

void printDirectory(File dir, int numTabs) {
  while (true) {
    File entry = dir.openNextFile();
    if (!entry) {
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}