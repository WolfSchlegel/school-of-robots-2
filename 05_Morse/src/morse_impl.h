/*
  Based on Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef INC_05_MORSE_MORSE_IMPL_H
#define INC_05_MORSE_MORSE_IMPL_H

#include "morse.h"
#include "Arduino.h"

class MorseImpl : public Morse {
public:
    void dot() override;

    void dash() override;

    void pauseAfterLetter() override;

    void pauseAfterWord() override;
};

void MorseImpl::dot() {
    digitalWrite(getPin(), HIGH);
    delay(Morse::PERIOD);
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD);
}

void MorseImpl::dash() {
    digitalWrite(getPin(), HIGH);
    delay(Morse::PERIOD * 3);
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD);
}

void MorseImpl::pauseAfterLetter() {
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD * 2);
}

void MorseImpl::pauseAfterWord() {
    digitalWrite(getPin(), LOW);
    delay(Morse::PERIOD * 4);
}

#endif //INC_05_MORSE_MORSE_IMPL_H