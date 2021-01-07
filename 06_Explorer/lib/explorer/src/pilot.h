#ifndef INC_06_EXPLORER_PILOT_H
#define INC_06_EXPLORER_PILOT_H

// TODO replace <Arduino.h> with c++ string type
// Arduino.h still imported to provide String class
//
#include <Arduino.h>

#include "direction.h"
#include "robot.h"

class Pilot {
public:
    static const int INPUT_LEFT = 0;   // Yellow cable
    static const int INPUT_RIGHT = 1;  // Blue cable

    static const int IR_SENSOR_THRESHOLD = 600;
    static const bool SENSOR_DEBUG = true;

    String directionToString(Direction direction);

    Direction getDirection(Robot *robot);

    Direction getDirectionFromReadings(int rightValue, int leftValue);

};

// TODO - does this mapping belong here to should it be closer to the enum?
//
String Pilot::directionToString(Direction direction) {
    switch(direction) {
        case Direction::BACKWARDS:
            return "backwards";
        case Direction::FORWARDS:
            return "forwards";
        case Direction::LEFT:
            return "left";
        case Direction::RIGHT:
            return "right";
        default:
            return "undefined";
    }
}

Direction Pilot::getDirectionFromReadings(int rightValue, int leftValue){
    bool leftOnBlack = leftValue < IR_SENSOR_THRESHOLD;
    bool rightOnBlack = rightValue < IR_SENSOR_THRESHOLD;

    if (!leftOnBlack && !rightOnBlack) {
        return Direction::BACKWARDS;
    }
    if (leftOnBlack && rightOnBlack) {
        return Direction::FORWARDS;
    }
    if (leftOnBlack) {
        return Direction::LEFT;
    }
    if (rightOnBlack) {
        return Direction::RIGHT;
    }
    return Direction::FORWARDS;
}

Direction Pilot::getDirection(Robot *robot) {
    int rightValue = robot->my_analogRead(INPUT_RIGHT);
    int leftValue = robot->my_analogRead(INPUT_LEFT);

    if ( SENSOR_DEBUG ) {
        robot->my_println("right sensor value is " + String(rightValue));
        robot->my_println("left sensor value is " + String(leftValue));
    }

    Direction direction = getDirectionFromReadings(rightValue, leftValue);
    robot->my_println("direction is " + directionToString(direction));

    return direction;
}

#endif //INC_06_EXPLORER_PILOT_H

