#ifndef INC_06_INCLUDE_ROBOT_H
#define INC_06_INCLUDE_ROBOT_H

class Robot {
public:
    ~Robot() = default;

    virtual void my_setup() = 0;

    virtual void accelerate() = 0;
    virtual void decelerate() = 0;

    virtual void moveForwards(int) = 0;
    virtual void moveBackwards(int) = 0;

    virtual int readColourSensor() = 0;
    virtual int readDistanceSensor() = 0;

    virtual int readLeftTrackSensor() = 0;
    virtual int readRightTrackSensor() = 0;

    virtual void rotateClockwise(int) = 0;
    virtual void rotateCounterClockwise(int) = 0;

    virtual void stop(int) = 0;
    virtual void stop() = 0;
};

#endif //INC_06_INCLUDE_ROBOT_H