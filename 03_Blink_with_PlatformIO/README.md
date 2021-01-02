# Blinking with CLion and the PlatformIO plugin

This folder contains the Blink example adapted for CLion and the PlatformIO plugin.

The original Blink code is available [here](http://www.arduino.cc/en/Tutorial/Blink).

The test code for the `uno`environment is part of the 
[PlatformIO tutorial for unit testing the "Blink" example](https://docs.platformio.org/en/latest/tutorials/core/unit_testing_blink.html). 
The PlatformIO tutorial is published under the Apache License 2.0 (c.f. `LICENSE` file in the `test/uno` folder).

## Prerequisites
* PlatformIO Core (CLI) which is available [here](https://docs.platformio.org/en/latest/core/index.html)
* CLion which is available [here](https://www.jetbrains.com/clion/)
* The PlatformIO plugin for CLion can be found by searching for "Arduino" [here](https://plugins.jetbrains.com/)

## How to run the Blink example
* Open the project folder in CLion
* Build and upload Blink to your board

## How to build the project on a console

Open a terminal window and run the following commands:
```
cd <root folder>/school-of-robots-2/03_Blink4Platformio

# (re-)initialise the project
pio init

# clean the project
pio run -t clean

# run all unit tests
pio test

# run native unit tests
pio test -e native

# run unit tests on Arduino Uno
pio test -e uno 
 
# upload firmware to the Arduino board
pio run -e uno -t upload
```

The PlatformIO CLI is documented [here](https://docs.platformio.org/en/latest/core/userguide/index.html).

