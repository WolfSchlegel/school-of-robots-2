#ifndef INC_06_INCLUDE_PILOT_H
#define INC_06_INCLUDE_PILOT_H

#include "direction.h"

class Pilot {
public:
    Direction getDirection(int rightValue, int leftValue);
private:
    static const int TRACK_SENSOR_THRESHOLD = 600;
};

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

#endif //INC_06_INCLUDE_PILOT_H

