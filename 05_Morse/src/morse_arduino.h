/*
  Based on Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef INC_05_MORSE_MORSE_ARDUINO_H
#define INC_05_MORSE_MORSE_ARDUINO_H

#include "morse.h"

class MorseArduino : public Morse {
public:
    void dot() override;

    void dash() override;

    void pauseAfterLetter() override;

    void pauseAfterWord() override;
};

#endif //INC_05_MORSE_MORSE_ARDUINO_H