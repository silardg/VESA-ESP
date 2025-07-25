# Welcome.ino

## Overview
This Arduino sketch is designed for the ESP32-S3 microcontroller to display a thank-you message and a QR code on a VGA monitor using the VESA-ESP. It uses the `ESP32S3VGA` library to interface with a VGA display and the `GfxWrapper` library to render text and graphics.

## Functionality
- **Display Setup**: Initializes a VGA display in 320x240 resolution at 60Hz using the `ESP32S3VGA` library.
- **Text Rendering**: Displays the text "Thank you!" and "For supporting this project! More on:" using the `FreeSerif24pt7b` font.
- **QR Code Rendering**: Renders a 100x100 pixel QR code from a predefined `qr_map` array, where each pixel is either black (1) or white (0).
- **Continuous Display**: The display is updated once and then holds indefinitely with a 500ms delay loop.

## Required Libraries
- **ESP32S3VGA**: Provides VGA output functionality for the ESP32-S3.
- **Adafruit_GFX**: A graphics library used via `GfxWrapper` for rendering text and shapes.
- **Adafruit_BusIO** (dependency for Adafruit_GFX): Handles I2C/SPI communication.

## Library Installation
1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. Search for and install:
   - **Adafruit_GFX** (installs Adafruit_BusIO automatically).
4. For **ESP32S3VGA**, refer to the main README for detailed installation instructions, as it may require downloading from an external repository (e.g., GitHub, if provided by the author, such as bitluni) and placing it in the Arduino `libraries` directory or adding it as a `.zip` file.
5. Restart the Arduino IDE after installation.

## Notes
- A VGA connection is needed for the VESA-ESP to display the output.

## Usage
1. Ensure the VESA-ESP is connected to a VGA monitor.
2. Upload the sketch to the ESP32-S3 using the Arduino IDE.
3. The VGA monitor will display the thank-you message and QR code.