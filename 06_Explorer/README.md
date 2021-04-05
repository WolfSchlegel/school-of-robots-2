# Teaching the Explorer robot to follow a line

Stay tuned...

## How to build and run on a console
Open a terminal window and run the following commands:
```
cd <root folder>/school-of-robots-2/06_Explorer

# (re-)initialise the project
pio init

# clean the project
pio run -t clean

# run all unit tests
pio -c ./platformio.ini test

# run native unit tests
pio -c ./platformio.ini test -e native

# run unit tests on Arduino Uno
pio test -e uno 
 
# upload firmware to the Arduino board
pio run -e uno -t upload

# monitor the Arduino board
pio device monitor -e uno
```