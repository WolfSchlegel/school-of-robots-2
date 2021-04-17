#include "gtest/gtest.h"
#include "pilot.h"

TEST(pilotTests, shouldGetDirectionForwards)
{
    EXPECT_EQ(Pilot::getDirection(10,10), Direction::FORWARDS);
}

TEST(pilotTests, shouldGetDirectionBackwards)
{
    EXPECT_EQ(Pilot::getDirection(900,900), Direction::BACKWARDS);
}

TEST(pilotTests, shouldGetDirectionRight)
{
    EXPECT_EQ(Pilot::getDirection(900,10), Direction::CLOCK_WISE);
}

TEST(pilotTests, shouldGetDirectionLeft)
{
    EXPECT_EQ(Pilot::getDirection(10,900), Direction::COUNTER_CLOCK_WISE);
}

TEST(pilotTests, shouldGetNextSpeed)
{
    int min = Speed::MIN;
    EXPECT_EQ(Pilot::getNextSpeed(Speed::ZERO), min);

    int medium = Speed::MEDIUM;
    EXPECT_EQ(Pilot::getNextSpeed(Speed::MIN), medium);

    int max = Speed::MAX;
    EXPECT_EQ(Pilot::getNextSpeed(Speed::MEDIUM), max);

    int zero = Speed::ZERO;
    EXPECT_EQ(Pilot::getNextSpeed(Speed::MAX), zero);
}
