#ifndef INC_06_EXPLORER_ROBOT_IMPL_H
#define INC_06_EXPLORER_ROBOT_IMPL_H

#include <Arduino.h>
#include <ArduinoLog.h>
#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#include "direction.h"
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

    void my_setup() override;

    void accelerate() override;
    void decelerate() override;

    void moveForwards(int) override;
    void moveBackwards(int) override;

    int readColourSensor() override;
    int readDistanceSensor() override;
    int readLeftTrackSensor() override;
    int readRightTrackSensor() override;

    void rotateClockwise(int) override;
    void rotateCounterClockwise(int) override;

    void stop(int) override;
    void stop() override;

private:
    Adafruit_MotorShield AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;

    static const int COLOUR_SENSOR = 2;       // Black cable
    static const int DISTANCE_SENSOR = 3;     // Black cable
    static const int LEFT_TRACK_SENSOR = 0;   // Yellow cable
    static const int RIGHT_TRACK_SENSOR = 1;  // Blue cable
};

void RobotImpl::my_setup() {
    Serial.begin(9600 );
    Log.begin( LOG_LEVEL_NOTICE, &Serial );

    Log.notice("initialising Adafruit Motorshield v2" CR );
    AFMS.begin();  // create with the default frequency 1.6KHz

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
    digitalWrite(LED_BUILTIN, HIGH);
    Log.notice("finished setup" CR);
}

// experimental
void RobotImpl::accelerate() {
    Log.notice("accelerating..." CR);

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
    for ( int i = Speed::MIN; i <= Speed::MAX; i += Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delay(Speed::DELAY);
    }
}

// still experimental
void RobotImpl::decelerate() {
    Log.notice("decelerating..." CR);

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    for ( int i = Speed::MIN; i >= Speed::MAX; i -= Speed::DELTA ){
        Log.notice("setting speed to %d" CR, i );

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delay(Speed::DELAY);
    }
}

void RobotImpl::moveForwards(int speed) {
    Log.notice("moving forwards at speed %d" CR, speed );
    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::moveBackwards(int speed) {
    Log.notice("moving backwards at speed %d" CR, speed );
    rightMotor->run(BACKWARD);
    leftMotor->run(BACKWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

int RobotImpl::readColourSensor() {
    int result = analogRead(COLOUR_SENSOR);
    Log.notice("colour sensor value is %d" CR, result );
    return result;
}

int RobotImpl::readDistanceSensor() {
    return -1;
}

int RobotImpl::readLeftTrackSensor() {
    int result = analogRead(LEFT_TRACK_SENSOR);
    Log.notice("left track sensor value is %d" CR, result );
    return result;
}

int RobotImpl::readRightTrackSensor() {
    int result = analogRead(RIGHT_TRACK_SENSOR);
    Log.notice("right track sensor value is %d" CR, result );
    return result;
}

void RobotImpl::rotateClockwise(int speed) {
    Log.notice("moving counterclockwise at speed %d" CR, speed );
    rightMotor->run(BACKWARD);
    leftMotor->run(FORWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::rotateCounterClockwise(int speed) {
    Log.notice("moving counterclockwise at speed %d" CR, speed );
    rightMotor->run(FORWARD);
    leftMotor->run(BACKWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::stop(int speed) {
    Log.notice("stopping and setting speed to %d" CR, speed );
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::stop() {
    stop(0);
}

#endif //INC_06_EXPLORER_ROBOT_IMPL_H
