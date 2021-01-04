/*
  Based on Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef INC_05_MORSE_MORSE_H
#define INC_05_MORSE_MORSE_H

class Morse {
public:
    virtual void dot() = 0;

    virtual void dash() = 0;

    virtual void pauseAfterLetter() = 0;

    virtual void pauseAfterWord() = 0;

    int getPin() const;

    void setPin(int pin);

    static const int PERIOD = 250;

protected:
    int pin;
};

int Morse::getPin() const {
    return pin;
}

void Morse::setPin(int pin) {
    Morse::pin = pin;
}

#endif  //INC_05_MORSE_MORSE_H

