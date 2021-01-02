# Sending Morse signals with CLion and the PlatformIO plugin

TBD

## Prerequisites
* PlatformIO Core (CLI) which is available [here](https://docs.platformio.org/en/latest/core/index.html)
* CLion which is available [here](https://www.jetbrains.com/clion/)
* The PlatformIO plugin for CLion can be found by searching for "Arduino" [here](https://plugins.jetbrains.com/)

## How to run the Blink example
* Open the project folder in CLion
* Build and upload the Morse example to your board

## How to build the project on a console

Open a terminal window and run the following commands:
```
cd <root folder>/school-of-robots-2/05_Morse

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
