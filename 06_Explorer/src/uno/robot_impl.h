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

    void setupRobot() override;

    void accelerate(int) override;
    void decelerate(int) override;

    void moveForwards(int) override;
    void moveBackwards(int) override;

    int readColourSensor() override;
    int readDistanceSensor() override;

    int readLeftTrackSensor() override;
    int readRightTrackSensor() override;

    void rotateClockwise(int) override;
    void rotateCounterClockwise(int) override;

    void toggleLed(Colour) override;

    void setSpeed(int) override;
    void stop() override;

private:
    void setupLeds();
    void setupMotors();
    void toggleLedsOff();

    Adafruit_MotorShield AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;

    static const int COLOUR_SENSOR_PIN = 2;       // Black cable
    static const int DISTANCE_SENSOR_PIN = 3;     // Black cable
    static const int LEFT_TRACK_SENSOR_PIN = 0;   // Yellow cable
    static const int RIGHT_TRACK_SENSOR_PIN = 1;  // Blue cable

    static const int BLUE_LED_PIN = 10;
    static const int GREEN_LED_PIN = 9;
    static const int RED_LED_PIN = 8;

    int currentSpeed;
    Direction currentDirection = Direction::UNDEFINED;
};

void RobotImpl::setupLeds() {
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    toggleLed( Colour::RED);
    delay(1000);
    toggleLed( Colour::GREEN);
    delay(1000);
    toggleLed( Colour::BLUE);
    delay(1000);
    toggleLed( Colour::UNDEFINED);

    digitalWrite(LED_BUILTIN, HIGH);
}

void RobotImpl::setupMotors() {
    Log.notice("initialising Adafruit Motorshield v2" CR );
    AFMS.begin();  // create with the default frequency 1.6KHz

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    currentDirection = Direction::FORWARDS;
}

void RobotImpl::setupRobot() {
    Serial.begin(9600 );
    Log.begin( LOG_LEVEL_NOTICE, &Serial );
    setupLeds();
    setupMotors();
    Log.notice("finished setup" CR);
}

// experimental and not used yet
//
void RobotImpl::accelerate(int speed) {
    Log.notice("accelerating from %d to %d" CR, currentSpeed, speed );

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    for ( int i = Speed::MIN; i <= speed; i += Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delay(Speed::DELAY);
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
        delay(Speed::DELAY);
    }

    currentDirection = Direction::FORWARDS;
    currentSpeed = speed;
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

void RobotImpl::toggleLed(Colour colour) {
    toggleLedsOff();
    switch (colour) {
        case Colour::BLUE:
            Log.notice("turning blue LED on" CR );
            digitalWrite(BLUE_LED_PIN, HIGH);
            digitalWrite(GREEN_LED_PIN, LOW);
            digitalWrite(RED_LED_PIN, LOW);
            break;
        case Colour::GREEN:
            Log.notice("turning blue LED on" CR );
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, HIGH);
            digitalWrite(RED_LED_PIN, LOW);
            break;
        case Colour::RED:
            Log.notice("turning blue LED on" CR );
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, LOW);
            digitalWrite(RED_LED_PIN, HIGH);
            break;
        default:
            Log.notice("turning all LEDs off" CR );
            digitalWrite(BLUE_LED_PIN, LOW);
            digitalWrite(GREEN_LED_PIN, LOW);
            digitalWrite(RED_LED_PIN, LOW);
    }
}

void RobotImpl::toggleLedsOff() {
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
}

#endif //INC_06_EXPLORER_ROBOT_IMPL_H
