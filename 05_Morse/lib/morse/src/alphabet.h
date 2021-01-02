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
