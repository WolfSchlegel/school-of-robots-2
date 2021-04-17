#include "gtest/gtest.h"
#include "colour_manager.h"

TEST(colourMatcherTests, shouldRecogniseReadingAsColour)
{
    ColourManager colourManager(nullptr);
    EXPECT_TRUE( colourManager.isMatch( 33, 42 ) );
    EXPECT_TRUE( colourManager.isMatch( 51, 42 ) );
}

TEST(colourMatcherTests, shouldRejectReadingAsColour)
{
    ColourManager colourManager(nullptr);
    EXPECT_FALSE( colourManager.isMatch( 32, 42 ) );
    EXPECT_FALSE( colourManager.isMatch( 52, 42 ) );
}

TEST(colourMatcherTests, shouldRecogniseBlue)
{
    ColourManager colourManager(nullptr);
    EXPECT_EQ(colourManager.getColour(colourManager.getBlueCalibrationValue()), Colour::BLUE);
}

TEST(colourMatcherTests, shouldRecogniseGreen)
{
    ColourManager colourManager(nullptr);
    EXPECT_EQ(colourManager.getColour(colourManager.getGreenCalibrationValue()), Colour::GREEN);
}


TEST(colourMatcherTests, shouldRecogniseRed)
{
    ColourManager colourManager(nullptr);
    EXPECT_EQ(colourManager.getColour(colourManager.getRedCalibrationValue()), Colour::RED);
}

TEST(colourMatcherTests, shouldNotRecogniseUnknownColour)
{
    ColourManager colourManager(nullptr);
    EXPECT_EQ(colourManager.getColour(123), Colour::UNDEFINED);
}
