#ifndef INC_06_EXPLORER_ROBOT_IMPL_H
#define INC_06_EXPLORER_ROBOT_IMPL_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include "direction.h"
#include "robot.h"
#include "speed.h"

class RobotImpl : public Robot {
public:
    RobotImpl() {
        AFMS = Adafruit_MotorShield();
        leftMotor = AFMS.getMotor(1);
        rightMotor = AFMS.getMotor(2);
    }

    int my_analogRead(int) override;
    void my_delay(int) override;

    void my_println(String) override;
    void my_setup() override;

    void accelerate() override;
    void decelerate() override;
    void moveForwards(int) override;
    void moveBackwards(int) override;
    void rotateClockwise(int) override;
    void rotateCounterClockwise(int) override;
    void stop(int) override;
    void stop() override;

private:
    Adafruit_MotorShield AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;
};

int RobotImpl::my_analogRead(int input) {
    return analogRead(input);
}

void RobotImpl::my_delay(int value) {
    delay(value);
}

void RobotImpl::my_println(String value) {
    Serial.println(value);
}

void RobotImpl::my_setup() {
    Serial.begin(9600);

    Serial.println("initialising Adafruit Motorshield v2");
    AFMS.begin();  // create with the default frequency 1.6KHz

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("finished setup");
}

// experimental
void RobotImpl::accelerate() {
    Serial.println("accelerating...");

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
    for (int i = Speed::MIN; i <= Speed::MAX; i += Speed::DELTA){
        Serial.println("setting speed to " + String(i));

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delay(Speed::DELAY);
    }
}

// still experimental
void RobotImpl::decelerate() {
    Serial.println("decelerating...");

    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);

    for (int i = Speed::MIN; i >= Speed::MAX; i -= Speed::DELTA){
        Serial.println("setting speed to " + String(i));

        rightMotor->setSpeed(i);
        leftMotor->setSpeed(i);
        delay(Speed::DELAY);
    }
}

void RobotImpl::moveForwards(int speed) {
    Serial.println("moving forwards...");
    rightMotor->run(FORWARD);
    leftMotor->run(FORWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::moveBackwards(int speed) {
    Serial.println("moving backwards...");
    rightMotor->run(BACKWARD);
    leftMotor->run(BACKWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::rotateClockwise(int speed) {
    Serial.println("moving counterclockwise...");
    rightMotor->run(BACKWARD);
    leftMotor->run(FORWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::rotateCounterClockwise(int speed) {
    Serial.println("moving counterclockwise...");
    rightMotor->run(FORWARD);
    leftMotor->run(BACKWARD);
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::stop(int speed) {
    Serial.println("stopping...");
    rightMotor->setSpeed(speed);
    leftMotor->setSpeed(speed);
}

void RobotImpl::stop() {
    stop(0);
}

#endif //INC_06_EXPLORER_ROBOT_IMPL_H
