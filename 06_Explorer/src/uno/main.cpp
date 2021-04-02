// TODO use another string type and remove include
#include <Arduino.h>

#include "direction.h"
#include "pilot.h"
#include "robot_impl.h"

const int VERSION = 42;
Pilot pilot;
RobotImpl robotImpl;

void setup() {
    robotImpl.my_setup();
    robotImpl.my_println("executing version " + String(VERSION));
}

void loop() {

    // TODO debug backwards motion
    // moveBackwards();

    Direction direction = pilot.getDirection(&robotImpl);

    switch(direction) {
        case Direction::BACKWARDS:
            robotImpl.moveBackwards(Speed::MIN);
            break;
        case Direction::FORWARDS:
            robotImpl.moveForwards(Speed::MAX);
            break;
        case Direction::LEFT:
            robotImpl.rotateCounterClockwise(Speed::MAX);
            break;
        case Direction::RIGHT:
            robotImpl.rotateClockwise(Speed::MAX);
            break;
        default:
            robotImpl.stop(Speed::ZERO);
    }
    // accelerate();
    // my_delay(2500);
    // decelerate();
}
