// TODO use another string type and remove include
#include <Arduino.h>
#include <ArduinoLog.h>

#include "colour_manager.h"
#include "pilot.h"
#include "robot_impl.h"

const int VERSION = 43;

RobotImpl robot;
ColourManager colourManager(&robot);
Pilot pilot(&robot);

void calibrateColourSensor() {
    Log.notice("calibrating colour sensor..." CR);
    colourManager.calibrateColourSensor();
    Log.notice("colour sensor reads %d for red" CR, colourManager.getRedCalibrationValue());
    Log.notice("colour sensor reads %d for green" CR, colourManager.getGreenCalibrationValue());
    Log.notice("colour sensor reads %d for blue" CR, colourManager.getBlueCalibrationValue());
}

void setup() {
    Serial.begin(9600 );
    Log.begin( LOG_LEVEL_NOTICE, &Serial );

    Log.notice("executing version %d" CR, VERSION);

    Log.notice("initialising robot..." CR);
    robot.setup();

    Log.notice("calibrating colour sensor..." CR);
    calibrateColourSensor();
}

void loop() {
    Log.notice("-- executing loop() -------------" CR);
    colourManager.showGroundColour();
    pilot.move();
    pilot.changeSpeed();
}




