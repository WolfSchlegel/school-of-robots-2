/*
  Based on Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/
#ifndef Morse_h
#define Morse_h

class Morse {
public:
    virtual void dot();

    virtual void dash();

    virtual void pauseAfterLetter();

    virtual void pauseAfterWord();

    static const int PIN = 13;

    static const int PERIOD = 250;

};

#endif