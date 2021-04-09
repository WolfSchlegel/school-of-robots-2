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

void setup() {
    robot.setupRobot();
    Log.notice("executing version %d" CR, VERSION);
}

void loop() {
    Log.notice("-- executing loop() -------------" CR);
    foo.toggleLed();
    pilot.move();
}




