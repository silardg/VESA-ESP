# SD_Test.ino

## Overview
This Arduino sketch tests the functionality of an SD card connected to an ESP32-S3 microcontroller using a custom SPI interface. It lists the contents of the SD card on the Serial Monitor.

## Functionality
- **SPI Setup**: Configures a custom SPI interface using defined pins for MOSI, MISO, SCK, and CS.
- **SD Card Initialization**: Initializes the SD card using the `SD` library over the custom SPI interface.
- **Directory Listing**: Recursively lists all files and directories on the SD card, printing their names and sizes (for files) to the Serial Monitor.
- **Static Operation**: The listing occurs once during setup, with no actions in the loop.

## Required Libraries
- **SD**: Standard Arduino library for SD card operations.
- **SPI**: Standard Arduino library for SPI communication.

## Library Installation
1. Open the Arduino IDE.
2. The **SD** and **SPI** libraries are included with the Arduino core for ESP32, so no additional installation is typically required.
3. If not present, go to **Sketch > Include Library > Manage Libraries** and search for **SD** and **SPI** to ensure they are installed.
4. Restart the Arduino IDE if any libraries are installed.

## Notes
- No VGA connection is required for this sketch, as it outputs to the Serial Monitor.

## Usage
1. Connect an SD card module to the ESP32-S3 using the specified SPI pins.
2. Insert an SD card formatted with a FAT32 or exFAT file system.
3. Upload the sketch to the ESP32-S3 using the Arduino IDE.
4. Open the Serial Monitor (115200 baud) to view the SD card's directory listing.