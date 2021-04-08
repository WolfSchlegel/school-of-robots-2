// TODO use another string type and remove include
#include <Arduino.h>
#include <ArduinoLog.h>

#include "direction.h"
#include "pilot.h"
#include "robot_impl.h"

const int VERSION = 42;
Pilot pilot;
RobotImpl robot;

void setup() {
    robot.my_setup();
    Log.notice("executing version %s" CR, VERSION);
}

void loop() {

    robot.readColourSensor();

    Direction direction = pilot.getDirection(robot.readLeftTrackSensor(), robot.readRightTrackSensor() );

    switch(direction) {
        case Direction::BACKWARDS:
            robot.moveBackwards(Speed::MIN);
            break;
        case Direction::FORWARDS:
            robot.moveForwards(Speed::MEDIUM);
            break;
        case Direction::LEFT:
            robot.rotateCounterClockwise(Speed::MAX);
            break;
        case Direction::RIGHT:
            robot.rotateClockwise(Speed::MAX);
            break;
        case Direction::UNDEFINED:
        default:
            robot.stop(Speed::ZERO);
    }

    // accelerate();
    // delay(2500);
    // decelerate();
}


