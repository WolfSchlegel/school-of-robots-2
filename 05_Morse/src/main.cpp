#include "Arduino.h"
#include "alphabet.h"

Alphabet alphabet(13);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
}

void loop() {
  Serial.println("Blinking SOS...!");
  alphabet.s();
  alphabet.o();
  alphabet.s();
  alphabet.pause();
}
