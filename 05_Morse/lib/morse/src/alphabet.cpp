//
// Created by Wolf on 30.12.20.
//

#include "alphabet.h"

Alphabet::Alphabet(int pin) : _morse(pin) {}

void Alphabet::o() {
    _morse.dot(); _morse.dot(); _morse.dot();
    _morse.pauseAfterLetter();
}

void Alphabet::s() {
    _morse.dash(); _morse.dash(); _morse.dash();
    _morse.pauseAfterLetter();
}

void Alphabet::pause() {
    _morse.pauseAfterWord();
}
