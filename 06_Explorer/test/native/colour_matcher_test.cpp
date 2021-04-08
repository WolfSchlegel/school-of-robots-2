#include "gtest/gtest.h"
#include "colour_matcher.h"

TEST(colourMatcherTests, shouldRecogniseReadingAsColour)
{
    ColourMatcher colourMatcher;
    EXPECT_TRUE( colourMatcher.isColour( 33, 42 ) );
    EXPECT_TRUE( colourMatcher.isColour( 51, 42 ) );
}

TEST(colourMatcherTests, shouldRejectReadingAsColour)
{
    ColourMatcher colourMatcher;
    EXPECT_FALSE( colourMatcher.isColour( 32, 42 ) );
    EXPECT_FALSE( colourMatcher.isColour( 52, 42 ) );
}

TEST(colourMatcherTests, shouldRecogniseBlack)
{
    ColourMatcher colourMatcher;
    EXPECT_EQ(colourMatcher.getColour(ColourMatcher::BLACK), Colour::BLACK);
}

TEST(colourMatcherTests, shouldRecogniseBlue)
{
    ColourMatcher colourMatcher;
    EXPECT_EQ(colourMatcher.getColour(ColourMatcher::BLUE), Colour::BLUE);
}

TEST(colourMatcherTests, shouldRecogniseGreen)
{
    ColourMatcher colourMatcher;
    EXPECT_EQ(colourMatcher.getColour(ColourMatcher::GREEN), Colour::GREEN);
}

TEST(colourMatcherTests, shouldRecogniseRed)
{
    ColourMatcher colourMatcher;
    EXPECT_EQ(colourMatcher.getColour(ColourMatcher::RED), Colour::RED);
}

TEST(colourMatcherTests, shouldNotRecogniseUnknownColour)
{
    ColourMatcher colourMatcher;
    EXPECT_EQ(colourMatcher.getColour(123), Colour::UNDEFINED);
}
