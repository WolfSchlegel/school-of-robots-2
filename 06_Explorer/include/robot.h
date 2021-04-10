#ifndef INC_06_INCLUDE_ROBOT_H
#define INC_06_INCLUDE_ROBOT_H

#include "colour.h"

// TODO decompose into robots with different responsibilities, such as moving, dealing with colours and distances.
//
class Robot {
public:
    ~Robot() = default;


    virtual void accelerate(int) = 0;
    virtual void decelerate(int) = 0;
    virtual void delayThings(unsigned long) = 0;

    virtual void moveForwards(int) = 0;
    virtual void moveBackwards(int) = 0;

    virtual int readButton() = 0;
    virtual int readColourSensor() = 0;
    virtual int readDistanceSensor() = 0;

    virtual int readLeftTrackSensor() = 0;
    virtual int readRightTrackSensor() = 0;

    virtual void rotateClockwise(int) = 0;
    virtual void rotateCounterClockwise(int) = 0;

    virtual void setSpeed(int) = 0;
    virtual void setup() = 0;
    virtual void stop() = 0;

    virtual void turnAllLedsOff() = 0;
    virtual void turnLedOff(Colour) = 0;
    virtual void turnLedOn(Colour) = 0;


};

#endif //INC_06_INCLUDE_ROBOT_H