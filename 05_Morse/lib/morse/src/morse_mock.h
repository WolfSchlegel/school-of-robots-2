#ifndef INC_05_MORSE_MORSE_MOCK_H
#define INC_05_MORSE_MORSE_MOCK_H

#include "morse.h"

class MorseMock : public Morse {
public:
    void dot() {
        dotCounter += 1;
    }

    void dash() {
        dashCounter += 1;
    }

    void pauseAfterLetter() {
        pauseAfterLetterCounter += 1;
    }

    void pauseAfterWord() {
        pauseAfterWordCounter += 1;
    }

    int getDashCounter() {
        return dashCounter;
    };

    int getDotCounter() {
        return dotCounter;
    };

    int getPauseAfterLetterCounter() {
        return pauseAfterLetterCounter;
    };

    int getPauseAfterWordCounter() {
        return pauseAfterWordCounter;
    };

    void resetCounters() {
        dashCounter = 0;
        dotCounter = 0;
        pauseAfterLetterCounter = 0;
        pauseAfterWordCounter = 0;
    }

protected:
    int dashCounter;

    int dotCounter;

    int pauseAfterLetterCounter;

    int pauseAfterWordCounter;

};

#endif //INC_05_MORSE_MORSE_MOCK_H