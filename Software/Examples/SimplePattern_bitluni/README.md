# SimplePattern_bitluni.ino

## Overview
This Arduino sketch demonstrates a simple VGA display pattern for the ESP32-S3 microcontroller using the VESA-ESP. It generates a colorful test pattern on a VGA monitor using the `ESP32S3VGA` library.

## Functionality
- **Display Setup**: Initializes a VGA display in 800x600 resolution at 60Hz (with an option for 1024x768 commented out).
- **Pattern Generation**: Creates a gradient pattern across the screen where pixel colors are based on their x and y coordinates.
- **Color Bars**: Draws three horizontal color bars (red, green, blue) at the top of the screen, each 30 pixels high, with intensity varying from 0 to 255.
- **Static Display**: The pattern is rendered once and displayed continuously.

## Required Libraries
- **ESP32S3VGA**: Provides VGA output functionality for the ESP32-S3.

## Library Installation
1. Open the Arduino IDE.
2. For **ESP32S3VGA**, refer to the main README for detailed installation instructions, as it may require downloading from an external repository (e.g., GitHub, if provided by the author, such as bitluni) and placing it in the Arduino `libraries` directory or adding it as a `.zip` file.
3. Restart the Arduino IDE after installation.

## Notes
- A VGA connection is needed for the VESA-ESP to display the output.

## Usage
1. Ensure the VESA-ESP is connected to a VGA monitor.
2. Upload the sketch to the ESP32-S3 using the Arduino IDE.
3. The VGA monitor will display the gradient pattern and color bars.