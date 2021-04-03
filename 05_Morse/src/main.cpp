#include "Arduino.h"
#include "alphabet.h"
#include "morse_arduino.h"

MorseArduino morse;
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
