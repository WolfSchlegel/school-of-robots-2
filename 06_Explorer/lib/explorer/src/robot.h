#ifndef INC_06_EXPLORER_ROBOT_H
#define INC_06_EXPLORER_ROBOT_H

class Robot {
public:
    virtual int my_analogRead(int) = 0;
    virtual void my_delay(int) = 0;

    virtual void my_println(String) = 0;
    virtual void my_setup() = 0;

    virtual void accelerate() = 0;
    virtual void decelerate() = 0;
    virtual void moveForwards(int) = 0;
    virtual void moveBackwards(int) = 0;
    virtual void rotateClockwise(int) = 0;
    virtual void rotateCounterClockwise(int) = 0;
    virtual void stop(int) = 0;
    virtual void stop() = 0;
};

#endif //INC_06_EXPLORER_ROBOT_H