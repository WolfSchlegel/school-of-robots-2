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

#endif //INC_05_MORSE_ALPHABET_H
