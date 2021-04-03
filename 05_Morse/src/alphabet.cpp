#include "../lib/morse/src/alphabet.h"

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
