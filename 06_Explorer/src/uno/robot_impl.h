#ifndef INC_06_EXPLORER_ROBOT_IMPL_H
#define INC_06_EXPLORER_ROBOT_IMPL_H

#include <Arduino.h>
#include <ArduinoLog.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#include "colour.h"
#include "robot.h"
#include "speed.h"

class RobotImpl : public Robot {
public:
    RobotImpl() {
        AFMS_ = Adafruit_MotorShield();
        leftMotor_ = AFMS_.getMotor(1 );
        rightMotor_ = AFMS_.getMotor(2 );
    }

    ~RobotImpl() = default;

    void accelerate(int) override;
    void blink(unsigned long) override;

    void decelerate(int) override;
    void delayThings(unsigned long) override;

    void moveForwards(int) override;
    void moveBackwards(int) override;

    int readButton() override;
    int readButton(unsigned long) override;

    int readColourSensor() override;
    int readDistanceSensor() override;

    int readLeftTrackSensor() override;
    int readRightTrackSensor() override;

    void rotateClockwise(int) override;
    void rotateCounterClockwise(int) override;

    void setup() override;

    void turnLedsOff() override;
    void turnLedsOn() override;

    void turnLedOff(Colour) override;
    void turnLedOn(Colour) override;

    void setSpeed(int) override;
    void stop() override;

private:
    void rotate(int, int, int);
    static void setupButton();
    void setupLeds();
    void setupMotors();
    static void toggleLed(Colour, int);

    Adafruit_MotorShield AFMS_;
    Adafruit_DCMotor *leftMotor_;
    Adafruit_DCMotor *rightMotor_;

    static const int COLOUR_SENSOR_PIN_ = 2;       // Black cable
    static const int DISTANCE_SENSOR_PIN_ = 3;     // Black cable
    static const int LEFT_TRACK_SENSOR_PIN_ = 0;   // Yellow cable
    static const int RIGHT_TRACK_SENSOR_PIN_ = 1;  // Blue cable

    static const int BUTTON_PIN_ = 11;

    static const int BLUE_LED_PIN_ = 10;
    static const int GREEN_LED_PIN_ = 9;
    static const int RED_LED_PIN_ = 8;

    Direction currentDirection_ = Direction::UNDEFINED;
    int currentSpeed_ = 0;
};

void RobotImpl::setupButton() {
    pinMode(BUTTON_PIN_, INPUT);
    digitalWrite(BUTTON_PIN_, HIGH); // activate internal pullup
}

void RobotImpl::setupLeds() {
    pinMode(BLUE_LED_PIN_, OUTPUT);
    pinMode(GREEN_LED_PIN_, OUTPUT);
    pinMode(RED_LED_PIN_, OUTPUT);

    turnLedOn( Colour::RED);
    delay(300);
    turnLedOn( Colour::GREEN);
    delay(300);
    turnLedOn( Colour::BLUE);
    delay(300);
    turnLedsOff();

    digitalWrite(LED_BUILTIN, HIGH);
}

void RobotImpl::setupMotors() {
    Log.notice("initialising Adafruit Motorshield v2" CR );
    AFMS_.begin();  // create with the default frequency 1.6KHz

    rightMotor_->run(FORWARD);
    leftMotor_->run(FORWARD);

    currentDirection_ = Direction::FORWARDS;
}

void RobotImpl::setup() {
    setupButton();
    setupLeds();
    setupMotors();
    Log.notice("finished setup" CR);
}

// experimental and not used yet, the goal is to move less jerkily
//
void RobotImpl::accelerate(int speed) {
    Log.notice("accelerating from %d to %d" CR, currentSpeed_, speed);

    rightMotor_->run(FORWARD);
    leftMotor_->run(FORWARD);

    for (int i = currentSpeed_; i <= speed; i += Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor_->setSpeed(i);
        leftMotor_->setSpeed(i);
        delay(Speed::DELAY);
    }

    currentDirection_ = Direction::FORWARDS;
    currentSpeed_ = speed;
}

void RobotImpl::blink(unsigned long millis) {
    turnLedsOn();
    delay(millis);
    turnLedsOff();
}

// still experimental and not used yet
//
void RobotImpl::decelerate(int speed) {
    Log.notice("decelerating from %d to %d" CR, currentSpeed_, speed );

    rightMotor_->run(FORWARD);
    leftMotor_->run(FORWARD);

    for (int i = currentSpeed_; i >= speed; i -= Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor_->setSpeed(i);
        leftMotor_->setSpeed(i);
        delay(Speed::DELAY);
    }

    currentDirection_ = Direction::FORWARDS;
    currentSpeed_ = speed;
}

void RobotImpl::delayThings(unsigned long millis) {
    delay(millis);
}

void RobotImpl::moveForwards(int speed) {
    Log.notice("moving forwards at speed %d" CR, speed );

    rightMotor_->run(FORWARD);
    leftMotor_->run(FORWARD);

    rightMotor_->setSpeed(speed);
    leftMotor_->setSpeed(speed);

    currentDirection_ = Direction::FORWARDS;
    currentSpeed_ = speed;
}

void RobotImpl::moveBackwards(int speed) {
    Log.notice("moving backwards at speed %d" CR, speed );

    rightMotor_->run(BACKWARD);
    leftMotor_->run(BACKWARD);

    rightMotor_->setSpeed(speed);
    leftMotor_->setSpeed(speed);

    currentDirection_ = Direction::BACKWARDS;
    currentSpeed_ = speed;
}

int RobotImpl::readButton() {
    return digitalRead(BUTTON_PIN_);
}

int RobotImpl::readButton(unsigned long timeout) {
    unsigned long start = millis();
    int result = 1;

    while (readButton() == 1 && millis() - start < timeout) {
        delay(100);
        result = digitalRead(BUTTON_PIN_);
    }

    return result;
}

int RobotImpl::readColourSensor() {
    int result = analogRead(COLOUR_SENSOR_PIN_);
    Log.notice("colour sensor value is %d" CR, result );
    return result;
}

int RobotImpl::readDistanceSensor() {
    return -1;
}

int RobotImpl::readLeftTrackSensor() {
    int result = analogRead(LEFT_TRACK_SENSOR_PIN_);
    Log.notice("left track sensor value is %d" CR, result );
    return result;
}

int RobotImpl::readRightTrackSensor() {
    int result = analogRead(RIGHT_TRACK_SENSOR_PIN_);
    Log.notice("right track sensor value is %d" CR, result );
    return result;
}

void RobotImpl::rotate(int speed, int leftDirection, int rightDirection) {
    leftMotor_->run(leftDirection);
    rightMotor_->run(rightDirection);

    leftMotor_->setSpeed(speed);
    rightMotor_->setSpeed(speed);
}

void RobotImpl::rotateClockwise(int speed) {
    Log.notice("rotating clockwise at speed %d" CR, speed );
    rotate(speed, FORWARD, BACKWARD);
    currentDirection_ = Direction::CLOCK_WISE;
    currentSpeed_ = speed;
}

void RobotImpl::rotateCounterClockwise(int speed) {
    Log.notice("rotating counterclockwise at speed %d" CR, speed );
    rotate(speed, BACKWARD, FORWARD);
    currentDirection_ = Direction::COUNTER_CLOCK_WISE;
    currentSpeed_ = speed;
}

void RobotImpl::setSpeed(int speed) {
    Log.notice("setting speed to %d" CR, speed );

    rightMotor_->setSpeed(speed);
    leftMotor_->setSpeed(speed);

    currentSpeed_ = speed;
}

void RobotImpl::stop() {
    setSpeed(0);
}

void RobotImpl::toggleLed(Colour colour, int value) {
    switch (colour) {
        case Colour::BLACK:
            break;
        case Colour::BLUE:
            digitalWrite(BLUE_LED_PIN_, value);
            break;
        case Colour::GREEN:
            digitalWrite(GREEN_LED_PIN_, value);
            break;
        case Colour::RED:
            digitalWrite(RED_LED_PIN_, value);
            break;
        case Colour::UNDEFINED:
            break;
    }
}

void RobotImpl::turnLedsOff() {
    digitalWrite(BLUE_LED_PIN_, LOW);
    digitalWrite(GREEN_LED_PIN_, LOW);
    digitalWrite(RED_LED_PIN_, LOW);
}

void RobotImpl::turnLedsOn() {
    digitalWrite(BLUE_LED_PIN_, HIGH);
    digitalWrite(GREEN_LED_PIN_, HIGH);
    digitalWrite(RED_LED_PIN_, HIGH);
}

void RobotImpl::turnLedOff(Colour colour) {
    toggleLed(colour, LOW);
}

void RobotImpl::turnLedOn(Colour colour) {
    toggleLed(colour, HIGH);
}

#endif //INC_06_EXPLORER_ROBOT_IMPL_H
