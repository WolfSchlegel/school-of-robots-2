#ifndef INC_06_INCLUDE_PILOT_H
#define INC_06_INCLUDE_PILOT_H

#include "direction.h"
#include "robot.h"
#include "speed.h"

class Pilot {
public:
    explicit Pilot(Robot *robot);
    ~Pilot() = default;

    int changeSpeed();

    static Direction getDirection(int leftValue, int rightValue);
    static int getNextSpeed(int currentSpeed);

    Direction move();

private:
    static const int TRACK_SENSOR_THRESHOLD_ = 600;
    Robot *robot_;
    int speed_ = 0;
};

Pilot::Pilot(Robot *robot) : robot_(robot) {
    speed_ = Speed::MEDIUM;
}

int Pilot::changeSpeed() {
    if(robot_->readButton() == 0) {
        robot_->blink(100);
        speed_ = getNextSpeed(speed_);
    }
}

Direction Pilot::getDirection(int leftValue, int rightValue){
    bool leftOnTrack = leftValue < TRACK_SENSOR_THRESHOLD_;
    bool rightOnTrack = rightValue < TRACK_SENSOR_THRESHOLD_;

    if (!leftOnTrack && !rightOnTrack) {
        return Direction::BACKWARDS;
    }
    if (leftOnTrack && rightOnTrack) {
        return Direction::FORWARDS;
    }
    if (leftOnTrack) {
        return Direction::COUNTER_CLOCK_WISE;
    }
    if (rightOnTrack) {
        return Direction::CLOCK_WISE;
    }
    return Direction::FORWARDS;
}

int Pilot::getNextSpeed(int currentSpeed) {
    switch (currentSpeed) {
        case Speed::ZERO:
            return Speed::MIN;
        case Speed::MIN:
            return Speed::MEDIUM;
        case Speed::MEDIUM:
            return Speed::MAX;
        case Speed::MAX:
            return Speed::ZERO;
        default:
            return Speed::ZERO;
    }
}

Direction Pilot::move() {
    Direction direction = getDirection(robot_->readLeftTrackSensor(), robot_->readRightTrackSensor());

    switch(direction) {
        case Direction::BACKWARDS:
            robot_->moveBackwards(speed_);
            break;
        case Direction::FORWARDS:
            robot_->moveForwards(speed_);
            break;
        case Direction::COUNTER_CLOCK_WISE:
            robot_->rotateCounterClockwise(speed_);
            break;
        case Direction::CLOCK_WISE:
            robot_->rotateClockwise(speed_);
            break;
        case Direction::UNDEFINED:
        default:
            robot_->stop();
    }

    return direction;
}

#endif //INC_06_INCLUDE_PILOT_H

