/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "morse.h"
#include "Arduino.h"

void Morse::dot() {
  digitalWrite(13, HIGH);
  delay(Morse::PERIOD);
  digitalWrite(13, LOW);
  delay(Morse::PERIOD);
}

void Morse::dash() {
  digitalWrite(13, HIGH);
  delay(Morse::PERIOD * 3);
  digitalWrite(13, LOW);
  delay(Morse::PERIOD);
}

void Morse::pauseAfterLetter() {
    digitalWrite(13, LOW);
    delay(Morse::PERIOD * 2);
}

void Morse::pauseAfterWord() {
    digitalWrite(13, LOW);
    delay(Morse::PERIOD * 4);
}
