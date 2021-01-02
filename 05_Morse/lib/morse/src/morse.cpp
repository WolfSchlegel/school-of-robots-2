/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "morse.h"
#include "Arduino.h"

Morse::Morse(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Morse::dot() {
  digitalWrite(_pin, HIGH);
  delay(Morse::PERIOD);
  digitalWrite(_pin, LOW);
  delay(Morse::PERIOD);
}

void Morse::dash() {
  digitalWrite(_pin, HIGH);
  delay(Morse::PERIOD * 3);
  digitalWrite(_pin, LOW);
  delay(Morse::PERIOD);
}

void Morse::pauseAfterLetter() {
    digitalWrite(_pin, LOW);
    delay(Morse::PERIOD * 2);
}

void Morse::pauseAfterWord() {
    digitalWrite(_pin, LOW);
    delay(Morse::PERIOD * 4);
}
