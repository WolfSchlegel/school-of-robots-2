#include "morse.h"

class MorseMock : public Morse {
public:
    void dot();

    void dash();

    void pauseAfterLetter();

    void pauseAfterWord();

    int getDashCounter() {
        return dashCounter;
    };

    int getDotCounter() {
        return dotCounter;
    };

    void resetCounters() {
        dashCounter = 0;
        dotCounter = 0;
    }

protected:
    int dashCounter;

    int dotCounter;

};

void MorseMock::dot() {
    dotCounter += 1;
}

void MorseMock::dash() {
    dashCounter += 1;
}

void MorseMock::pauseAfterLetter() {}

void MorseMock::pauseAfterWord() {}