// TODO use another string type and remove include
#include <Arduino.h>
#include <ArduinoLog.h>

#include "foo.h"
#include "pilot.h"
#include "robot_impl.h"

const int VERSION = 43;

RobotImpl robot;
Foo foo(&robot);
Pilot pilot(&robot);

void calibrateColourSensor() {
    Log.notice("calibrating colour sensor..." CR);
    foo.calibrateColourSensor();
    Log.notice("colour sensor reads %d for red" CR, foo.getRedCalibrationValue());
    Log.notice("colour sensor reads %d for green" CR, foo.getGreenCalibrationValue());
    Log.notice("colour sensor reads %d for blue" CR, foo.getBlueCalibrationValue());
}

void setup() {
    Serial.begin(9600 );
    Log.begin( LOG_LEVEL_NOTICE, &Serial );

    Log.notice("executing version %d" CR, VERSION);

    Log.notice("initialising robot..." CR);
    robot.setup();

    calibrateColourSensor();
}

void loop() {
    Log.notice("-- executing loop() -------------" CR);
    foo.showGroundColour();
    pilot.move();
}




