#ifndef INC_06_EXPLORER_FOO_H
#define INC_06_EXPLORER_FOO_H

#include "colour.h"
#include "robot.h"

// TODO find better name
//
class Foo {
public:
    Foo(Robot *robot);
    ~Foo() = default;

    Colour getColour(int reading);
    bool isMatch(int reading, int referenceColour );
    Colour toggleLed();

    static const int BLACK = 575;
    static const int BLUE = 460;
    static const int GREEN = 420;
    static const int RED = 300;

    static const int MAX_DEVIATION = 10;

private:
    Robot *_robot;
};

Foo::Foo(Robot *robot) : _robot(robot) {}

bool Foo::isMatch(int reading, int referenceColour) {
    if (reading > referenceColour - Foo::MAX_DEVIATION ) {
        return reading < referenceColour + Foo::MAX_DEVIATION;
    } else {
        return false;
    }
}

Colour Foo::getColour(int reading) {
    if (isMatch(reading, BLACK) ) {
        return Colour::BLACK;
    }
    if (isMatch(reading, BLUE) ) {
        return Colour::BLUE;
    }
    if (isMatch(reading, GREEN) ) {
        return Colour::GREEN;
    }
    if (isMatch(reading, RED) ) {
        return Colour::RED;
    }
    return Colour::UNDEFINED;
}

Colour Foo::toggleLed() {
    Colour colour = getColour(_robot->readColourSensor());
    _robot->toggleLed(colour);
    return colour;
}

#endif //INC_06_EXPLORER_FOO_H
