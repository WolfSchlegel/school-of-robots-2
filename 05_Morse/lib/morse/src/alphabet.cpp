//
// Created by Wolf on 30.12.20.
//

#include "alphabet.h"

Alphabet::Alphabet(Morse *morse)  : _morse{ morse } {
    morse->setPin(13);
}

void Alphabet::o() {
    _morse->dot(); _morse->dot(); _morse->dot();
    _morse->pauseAfterLetter();
}

void Alphabet::s() {
    _morse->dash(); _morse->dash(); _morse->dash();
    _morse->pauseAfterLetter();
}

void Alphabet::pause() {
    _morse->pauseAfterWord();
}
