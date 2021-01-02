# Sending Morse signals with CLion and the PlatformIO plugin

This project implements a (reduced) Morse alphabet and provides examples for the following aspects:
* Organise shared code in a library and use that library
* Use the library in the actual embedded application as well as in unit tests
* Distinguish between native and embedded unit tests
* Hand-rolled mocking and dependency injection
  * Use the same Alphabet class throughout and inject different implementations of the Morse interface
  * Use the real Morse implementation for the embedded application
  * Use the mock implementation of the Morse class for native testing

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

# run embedded unit tests
pio test -e uno

# upload firmware to the Arduino board
pio run -e uno -t upload
```

The PlatformIO CLI is documented [here](https://docs.platformio.org/en/latest/core/userguide/index.html).
