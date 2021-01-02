//
// Created by Wolf on 30.12.20.
//

#ifndef INC_04_MORSE_ALPHABET_H
#define INC_04_MORSE_ALPHABET_H

#include "morse.h"

class Alphabet {
  public:
    Alphabet(Morse *morse);

    void o();

    void s();

    void pause();

  private:
    Morse *_morse;
};

#endif //INC_04_MORSE_ALPHABET_H

Alphabet::Alphabet(Morse *morse)  : _morse(morse) {
    morse->setPin(13);
}

void Alphabet::o() {
    _morse->dash(); _morse->dash(); _morse->dash();
    _morse->pauseAfterLetter();
}

void Alphabet::s() {
    _morse->dot(); _morse->dot(); _morse->dot();
    _morse->pauseAfterLetter();
}

void Alphabet::pause() {
    _morse->pauseAfterWord();
}
