#include "Arduino.h"
#include "../lib/morse/src/alphabet.h"
#include "../lib/morse/src/morse_impl.h"

MorseImpl morseImpl;
Morse morse;
Alphabet alphabet(&morse);

void setup() {
    Serial.begin(9600); // set up Serial library at 9600 bps
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    Serial.println("Blinking SOS...!");
    alphabet.s();
    alphabet.o();
    alphabet.s();
    alphabet.pause();
}
