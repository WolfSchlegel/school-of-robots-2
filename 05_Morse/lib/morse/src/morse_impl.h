/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "morse.h"
#include "Arduino.h"

class MorseImpl : public Morse {
public:
    void dot();

    void dash();

    void pauseAfterLetter();

    void pauseAfterWord();

private:
    static const int PERIOD = 250;

};

void MorseImpl::dot() {
    digitalWrite(PIN, HIGH);
    delay(PERIOD);
    digitalWrite(PIN, LOW);
    delay(PERIOD);
}

void MorseImpl::dash() {
    digitalWrite(PIN, HIGH);
    delay(PERIOD * 3);
    digitalWrite(PIN, LOW);
    delay(PERIOD);
}

void MorseImpl::pauseAfterLetter() {
    digitalWrite(PIN, LOW);
    delay(PERIOD * 2);
}

void MorseImpl::pauseAfterWord() {
    digitalWrite(PIN, LOW);
    delay(PERIOD * 4);
}