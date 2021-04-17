#ifndef INC_06_EXPLORER_COLOUR_MANAGER_H
#define INC_06_EXPLORER_COLOUR_MANAGER_H

#include "colour.h"
#include "robot.h"

class ColourManager {
public:
    explicit ColourManager(Robot *robot);
    ~ColourManager() = default;

    void calibrateColourSensor();
    Colour getColour(int reading);
    bool isMatch(int reading, int referenceValue );
    Colour showGroundColour();

    int getBlueCalibrationValue() const;
    int getGreenCalibrationValue() const;
    int getRedCalibrationValue() const;

private:
    int calibrateColourSensor(Colour colour);

    static const int MAX_DEVIATION_ = 10;

    // Negative calibration values are used for unit testing and
    // replaced with positive values when calibrating the colour sensor.
    //
    int blueCalibrationValue_ = -100;
    int greenCalibrationValue_ = -200;
    int redCalibrationValue_ = -300;

    Robot *robot_;

};

ColourManager::ColourManager(Robot *robot) : robot_(robot) {}

void ColourManager::calibrateColourSensor() {
    calibrateColourSensor(Colour::RED);
    calibrateColourSensor(Colour::GREEN);
    calibrateColourSensor(Colour::BLUE);
}

int ColourManager::calibrateColourSensor(Colour colour) {
    robot_->turnLedsOff();
    robot_->turnLedOn(colour);
    robot_->delayThings(1000);

    while (robot_->readButton() == 1) {
        robot_->delayThings(100);
    }

    int reading = robot_->readColourSensor();

    switch (colour) {
        case Colour::BLUE:
            blueCalibrationValue_ = reading;
            break;
        case Colour::GREEN:
            greenCalibrationValue_ = reading;
            break;
        case Colour::RED:
            redCalibrationValue_ = reading;
            break;
        case Colour::BLACK:
        case Colour::UNDEFINED:
        default:
            break;
    }

    robot_->turnLedOff(colour);
    return reading;
}

Colour ColourManager::getColour(int reading) {
    if (isMatch(reading, blueCalibrationValue_) ) {
        return Colour::BLUE;
    }
    if (isMatch(reading, greenCalibrationValue_) ) {
        return Colour::GREEN;
    }
    if (isMatch(reading, redCalibrationValue_) ) {
        return Colour::RED;
    }
    return Colour::UNDEFINED;
}

bool ColourManager::isMatch(int reading, int referenceValue) {
    if (reading > referenceValue - ColourManager::MAX_DEVIATION_ ) {
        return reading < referenceValue + ColourManager::MAX_DEVIATION_;
    } else {
        return false;
    }
}

Colour ColourManager::showGroundColour() {
    Colour colour = getColour(robot_->readColourSensor());
    robot_->turnLedsOff();
    robot_->turnLedOn(colour);
    return colour;
}

int ColourManager::getBlueCalibrationValue() const {
    return blueCalibrationValue_;
}

int ColourManager::getGreenCalibrationValue() const {
    return greenCalibrationValue_;
}

int ColourManager::getRedCalibrationValue() const {
    return redCalibrationValue_;
}

#endif //INC_06_EXPLORER_COLOUR_MANAGER_H
