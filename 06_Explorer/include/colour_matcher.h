#ifndef INC_06_EXPLORER_COLOUR_MATCHER_H
#define INC_06_EXPLORER_COLOUR_MATCHER_H

#include "colour.h"

class ColourMatcher {
public:
    ~ColourMatcher() = default;

    Colour getColour(int reading);

    bool isColour( int reading, int colour );

    static const int BLACK = 575;
    static const int BLUE = 460;
    static const int GREEN = 420;
    static const int RED = 300;

    static const int MAX_DEVIATION = 10;
};

bool ColourMatcher::isColour(int reading, int colour) {
    if ( reading > colour - ColourMatcher::MAX_DEVIATION ) {
        return reading < colour + ColourMatcher::MAX_DEVIATION;
    } else {
        return false;
    }
}

Colour ColourMatcher::getColour(int reading) {
    if ( isColour( reading, ColourMatcher::BLACK ) ) {
        return Colour::BLACK;
    }
    if ( isColour( reading, ColourMatcher::BLUE ) ) {
        return Colour::BLUE;
    }
    if ( isColour( reading, ColourMatcher::GREEN ) ) {
        return Colour::GREEN;
    }
    if ( isColour( reading, ColourMatcher::RED ) ) {
        return Colour::RED;
    }
    return Colour::UNDEFINED;
}

#endif //INC_06_EXPLORER_COLOUR_MATCHER_H
