# SD_GFX.ino

## Overview
This Arduino sketch combines SD card access with VGA display output on an ESP32-S3 microcontroller using the VESA-ESP. It lists the contents of an SD card on both the Serial Monitor and a VGA display using the `ESP32S3VGA` and `Adafruit_GFX` libraries.

## Functionality
- **SPI Setup**: Configures a custom SPI interface for SD card communication using defined pins for MOSI, MISO, SCK, and CS.
- **SD Card Initialization**: Initializes the SD card using the `SD` library.
- **Display Setup**: Initializes a VGA display in 320x240 resolution at 60Hz using the `ESP32S3VGA` library.
- **Directory Listing**: Recursively lists all files and directories on the SD card, printing their names to the Serial Monitor and displaying them on the VGA screen with a 200ms delay between each entry.
- **Static Operation**: The listing occurs once during setup, with no actions in the loop.

## Required Libraries
- **ESP32S3VGA**: Provides VGA output functionality for the ESP32-S3.
- **Adafruit_GFX**: A graphics library used via `GfxWrapper` for rendering text and shapes.
- **Adafruit_BusIO** (dependency for Adafruit_GFX): Handles I2C/SPI communication.
- **SD**: Standard Arduino library for SD card operations.
- **SPI**: Standard Arduino library for SPI communication.

## Library Installation
1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for and install:
   - **Adafruit_GFX** (installs Adafruit_BusIO automatically).
   - **SD** and **SPI** (typically included with the Arduino core for ESP32).
4. For **ESP32S3VGA**, refer to the main README for detailed installation instructions, as it may require downloading from an external repository (e.g., GitHub, if provided by the author, such as bitluni) and placing it in the Arduino `libraries` directory or adding it as a `.zip` file.
5. Restart the Arduino IDE after installation.

## Notes
- A VGA connection is needed for the VESA-ESP to display the output.

## Usage
1. Connect an SD card module and ensure the VESA-ESP is connected to a VGA monitor.
2. Insert an SD card formatted with a FAT32 or exFAT file system.
3. Upload the sketch to the ESP32-S3 using the Arduino IDE.
4. Open the Serial Monitor (115200 baud) to view the SD card's directory listing.
5. The VGA monitor will display each file/directory name with a 200ms delay between entries.