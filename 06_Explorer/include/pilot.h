#ifndef INC_06_INCLUDE_PILOT_H
#define INC_06_INCLUDE_PILOT_H

#include "direction.h"
#include "robot.h"
#include "speed.h"

class Pilot {
public:
    Pilot(Robot *robot);
    ~Pilot() = default;

    Direction getDirection(int leftValue, int rightValue);
    Direction move();

private:
    static const int TRACK_SENSOR_THRESHOLD = 600;
    Robot *_robot;
};

Pilot::Pilot(Robot *robot) : _robot(robot) {}  

Direction Pilot::getDirection(int leftValue, int rightValue){
    bool leftOnTrack = leftValue < TRACK_SENSOR_THRESHOLD;
    bool rightOnTrack = rightValue < TRACK_SENSOR_THRESHOLD;

    if (!leftOnTrack && !rightOnTrack) {
        return Direction::BACKWARDS;
    }
    if (leftOnTrack && rightOnTrack) {
        return Direction::FORWARDS;
    }
    if (leftOnTrack) {
        return Direction::LEFT;
    }
    if (rightOnTrack) {
        return Direction::RIGHT;
    }
    return Direction::FORWARDS;
}

Direction Pilot::move() {
    Direction direction = getDirection(_robot->readLeftTrackSensor(), _robot->readRightTrackSensor());

    switch(direction) {
        case Direction::BACKWARDS:
            _robot->moveBackwards(Speed::MIN);
            break;
        case Direction::FORWARDS:
            _robot->moveForwards(Speed::MEDIUM);
            break;
        case Direction::LEFT:
            _robot->rotateCounterClockwise(Speed::MAX);
            break;
        case Direction::RIGHT:
            _robot->rotateClockwise(Speed::MAX);
            break;
        case Direction::UNDEFINED:
        default:
            _robot->stop();
    }

    return direction;
}

#endif //INC_06_INCLUDE_PILOT_H

