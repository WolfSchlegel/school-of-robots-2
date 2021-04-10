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

    void calibrateColourSensor();
    Colour getColour(int reading);
    bool isMatch(int reading, int referenceValue );
    Colour showGroundColour();

    int getBlueCalibrationValue() const;
    int getGreenCalibrationValue() const;
    int getRedCalibrationValue() const;

private:
    static const int MAX_DEVIATION = 10;
    int blueCalibrationValue, greenCalibrationValue, redCalibrationValue = 0;
    Robot *_robot;

    int calibrateColourSensor(Colour colour);
};

Foo::Foo(Robot *robot) : _robot(robot) {}

void Foo::calibrateColourSensor() {
    calibrateColourSensor(Colour::RED);
    calibrateColourSensor(Colour::GREEN);
    calibrateColourSensor(Colour::BLUE);
}

int Foo::calibrateColourSensor(Colour colour) {
    _robot->turnAllLedsOff();
    _robot->turnLedOn(colour);
    _robot->delayThings(1000);

    while (_robot->readButton() == 1) {
        _robot->delayThings(100);
    }

    int reading = _robot->readColourSensor();

    switch (colour) {
        case Colour::BLUE:
            blueCalibrationValue = reading;
            break;
        case Colour::GREEN:
            greenCalibrationValue = reading;
            break;
        case Colour::RED:
            redCalibrationValue = reading;
            break;
        case Colour::BLACK:
        case Colour::UNDEFINED:
        default:
            break;
    }

    _robot->turnLedOff(colour);
    return reading;
}

Colour Foo::getColour(int reading) {
    if (isMatch(reading, blueCalibrationValue) ) {
        return Colour::BLUE;
    }
    if (isMatch(reading, greenCalibrationValue) ) {
        return Colour::GREEN;
    }
    if (isMatch(reading, redCalibrationValue) ) {
        return Colour::RED;
    }
    return Colour::UNDEFINED;
}

bool Foo::isMatch(int reading, int referenceValue) {
    if (reading > referenceValue - Foo::MAX_DEVIATION ) {
        return reading < referenceValue + Foo::MAX_DEVIATION;
    } else {
        return false;
    }
}

Colour Foo::showGroundColour() {
    Colour colour = getColour(_robot->readColourSensor());
    _robot->turnAllLedsOff();
    _robot->turnLedOn(colour);
    return colour;
}

int Foo::getBlueCalibrationValue() const {
    return blueCalibrationValue;
}

int Foo::getGreenCalibrationValue() const {
    return greenCalibrationValue;
}

int Foo::getRedCalibrationValue() const {
    return redCalibrationValue;
}

#endif //INC_06_EXPLORER_FOO_H
