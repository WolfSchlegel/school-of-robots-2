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
        AFMS = Adafruit_MotorShield();
        leftMotor = AFMS.getMotor(1 );
        rightMotor = AFMS.getMotor(2 );
    }

    ~RobotImpl() = default;

    void setup() override;

    void accelerate(int) override;

    void decelerate(int) override;
    void delayThings(unsigned long) override;

    void moveForwards(int) override;
    void moveBackwards(int) override;

    int readButton() override;
    int readColourSensor() override;
    int readDistanceSensor() override;
    int readLeftTrackSensor() override;
    int readRightTrackSensor() override;

    void rotateClockwise(int) override;
    void rotateCounterClockwise(int) override;

    void turnAllLedsOff() override;
    void turnLedOff(Colour) override;
    void turnLedOn(Colour) override;

    void setSpeed(int) override;
    void stop() override;

private:
    void setupButton();
    void setupLeds();
    void setupMotors();
    void toggleLed(Colour, int);

    Adafruit_MotorShield AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;

    static const int COLOUR_SENSOR_PIN = 2;       // Black cable
    static const int DISTANCE_SENSOR_PIN = 3;     // Black cable
    static const int LEFT_TRACK_SENSOR_PIN = 0;   // Yellow cable
    static const int RIGHT_TRACK_SENSOR_PIN = 1;  // Blue cable

    static const int BUTTON_PIN = 11;

    static const int BLUE_LED_PIN = 10;
    static const int GREEN_LED_PIN = 9;
    static const int RED_LED_PIN = 8;

    int currentSpeed;
    Direction currentDirection = Direction::UNDEFINED;
};

void RobotImpl::setupButton() {
    pinMode(BUTTON_PIN, INPUT);
    digitalWrite(BUTTON_PIN, HIGH); // activate internal pullup
}

void RobotImpl::setupLeds() {
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    turnLedOn( Colour::RED);
    delayThings(300);
    turnLedOn( Colour::GREEN);
    delayThings(300);
    turnLedOn( Colour::BLUE);
    delayThings(300);
    turnAllLedsOff();

    digitalWrite(LED_BUILTIN, HIGH);
}

void RobotImpl::setupMotors() {
    Log.notice("initialising Adafruit Motorshield v2" CR );
    AFMS.begin();  // create with the default frequency 1.6KHz

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    currentDirection = Direction::FORWARDS;
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
    Log.notice("accelerating from %d to %d" CR, currentSpeed, speed );

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    for ( int i = Speed::MIN; i <= speed; i += Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delayThings(Speed::DELAY);
    }

    currentDirection = Direction::FORWARDS;
    currentSpeed = speed;
}

// still experimental and not used yet
//
void RobotImpl::decelerate(int speed) {
    Log.notice("decelerating from %d to %d" CR, currentSpeed, speed );

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    for ( int i = Speed::MAX; i >= speed; i -= Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delayThings(Speed::DELAY);
    }

    currentDirection = Direction::FORWARDS;
    currentSpeed = speed;
}

void RobotImpl::delayThings(unsigned long millis) {
    delay(millis);
}

void RobotImpl::moveForwards(int speed) {
    Log.notice("moving forwards at speed %d" CR, speed );

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);

    currentDirection = Direction::FORWARDS;
    currentSpeed = speed;
}

void RobotImpl::moveBackwards(int speed) {
    Log.notice("moving backwards at speed %d" CR, speed );

    rightMotor->run(BACKWARD);
    leftMotor->run(BACKWARD);

    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);

    currentDirection = Direction::BACKWARDS;
    currentSpeed = speed;
}

int RobotImpl::readButton() {
    return digitalRead(BUTTON_PIN);
}

int RobotImpl::readColourSensor() {
    int result = analogRead(COLOUR_SENSOR_PIN);
    Log.notice("colour sensor value is %d" CR, result );
    return result;
}

int RobotImpl::readDistanceSensor() {
    return -1;
}

int RobotImpl::readLeftTrackSensor() {
    int result = analogRead(LEFT_TRACK_SENSOR_PIN);
    Log.notice("left track sensor value is %d" CR, result );
    return result;
}

int RobotImpl::readRightTrackSensor() {
    int result = analogRead(RIGHT_TRACK_SENSOR_PIN);
    Log.notice("right track sensor value is %d" CR, result );
    return result;
}

void RobotImpl::rotateClockwise(int speed) {
    Log.notice("moving counterclockwise at speed %d" CR, speed );

    rightMotor->run(BACKWARD);
    leftMotor->run(FORWARD);

    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);

    currentDirection = Direction::RIGHT;
    currentSpeed = speed;
}

void RobotImpl::rotateCounterClockwise(int speed) {
    Log.notice("moving counterclockwise at speed %d" CR, speed );

    rightMotor->run(FORWARD);
    leftMotor->run(BACKWARD);

    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);

    currentDirection = Direction::LEFT;
    currentSpeed = speed;
}

void RobotImpl::setSpeed(int speed) {
    Log.notice("setting speed to %d" CR, speed );

    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);

    currentSpeed = speed;
}

void RobotImpl::stop() {
    setSpeed(0);
}

void RobotImpl::toggleLed(Colour colour, int value) {
    switch (colour) {
        case Colour::BLACK:
            break;
        case Colour::BLUE:
            digitalWrite(BLUE_LED_PIN, value);
            break;
        case Colour::GREEN:
            digitalWrite(GREEN_LED_PIN, value);
            break;
        case Colour::RED:
            digitalWrite(RED_LED_PIN, value);
            break;
        case Colour::UNDEFINED:
            break;
    }
}

void RobotImpl::turnAllLedsOff() {
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
}

void RobotImpl::turnLedOff(Colour colour) {
    toggleLed(colour, LOW);
}

void RobotImpl::turnLedOn(Colour colour) {
    toggleLed(colour, HIGH);
}

#endif //INC_06_EXPLORER_ROBOT_IMPL_H
