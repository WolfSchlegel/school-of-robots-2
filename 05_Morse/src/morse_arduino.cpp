/*
  Based on Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "morse_arduino.h"
#include "Arduino.h"

void MorseArduino::dot() {
    digitalWrite(getPin(), HIGH);
    delay(Morse::PERIOD);
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD);
}

void MorseArduino::dash() {
    digitalWrite(getPin(), HIGH);
    delay(Morse::PERIOD * 3);
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD);
}

void MorseArduino::pauseAfterLetter() {
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD * 2);
}

void MorseArduino::pauseAfterWord() {
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD * 4);
}