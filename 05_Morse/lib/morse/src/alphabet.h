#ifndef INC_05_MORSE_ALPHABET_H
#define INC_05_MORSE_ALPHABET_H

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

#endif //INC_05_MORSE_ALPHABET_H
