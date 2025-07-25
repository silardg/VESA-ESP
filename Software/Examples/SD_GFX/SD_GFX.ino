#include <SD.h>
#include <SPI.h>
#include "ESP32S3VGA.h"
#include <GfxWrapper.h>
#include <Fonts/FreeMonoBoldOblique24pt7b.h>
#include <Fonts/FreeSerif24pt7b.h>

//                   r,r,r,r,r,  g,g, g, g, g, g,   b, b, b, b, b,   h,v
const PinConfig pins(4,5,6,7,8,  9,10,11,12,13,14,  15,16,17,18,21,  1,2);

//VGA Device
VGA vga;
Mode mode = Mode::MODE_320x240x60;
GfxWrapper<VGA> gfx(vga, mode.hRes, mode.vRes);

// Define pins
#define SD_CS_PIN 40   // CD/DAT3 (CS)
#define MOSI_PIN 38    // CMD (MOSI)
#define MISO_PIN 39    // DAT0 (MISO)
#define SCK_PIN 45     // CLK (SCK)

// Create a custom SPI instance
SPIClass mySPI(FSPI);

void setup() {
  delay(5000);
  Serial.begin(115200);

  // Initialize SPI with custom pins
  mySPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, SD_CS_PIN);

  // Initialize SD card
  if (!SD.begin(SD_CS_PIN, mySPI)) {
    Serial.println("SD Card initialization failed!");
    return;
  }
  Serial.println("SD Card initialized successfully.");

  vga.bufferCount = 2;
	if(!vga.init(pins, mode, 16)) while(1) delay(1);

	vga.start();
  static int x = 0;
	vga.clear(vga.rgb(0x80, 0, 0));
  // List files on the SD card
  File root = SD.open("/");
  printDirectory(root, 0);
}

void loop() {
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
    vga.clear(vga.rgb(0x80, 0, 0));
    gfx.setCursor(100, 100);
    gfx.print(entry.name());
    vga.show();
    delay(200);
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