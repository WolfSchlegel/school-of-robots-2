# Blinking with CLion and the PlatformIO plugin

This folder contains the Blink example adapted for CLion and the PlatformIO plugin.

The original example code is available [here](http://www.arduino.cc/en/Tutorial/Blink).

The test code is part of the [PlatformIO tutorial for unit testing the "Blink" example](https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html). The tutorial is published under the Apache License 2.0 which (c.f. `LICENSE` file in the `test` folder).

## Prerequisites
* PlatformIO Core (CLI) which is available [here](https://docs.platformio.org/en/latest/core/index.html)
* CLion which is available [here](https://www.jetbrains.com/clion/)
* The PlatformIO plugin for CLion can be found by searching for "Arduino" [here](https://plugins.jetbrains.com/)

## How to run the Blink example
* Open the project folder in CLion
* Build and upload Blink to your board

## How to build and run on a console
Open a terminal window and run the following commands:
```
cd <root folder>/school-of-robots-2/03_Blink4Platformio
pio run -t upload
```
