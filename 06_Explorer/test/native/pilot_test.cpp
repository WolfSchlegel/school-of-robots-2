#include "gtest/gtest.h"
#include "direction.h"
#include "pilot.h"

TEST(pilotTests, shouldGetDirectionForwards)
{
    Pilot pilot;
    EXPECT_EQ(pilot.getDirection(10,10), Direction::FORWARDS);
}

TEST(pilotTests, shouldGetDirectionBackwards)
{
    Pilot pilot;
    EXPECT_EQ(pilot.getDirection(900,900), Direction::BACKWARDS);
}

TEST(pilotTests, shouldGetDirectionRight)
{
    Pilot pilot;
    EXPECT_EQ(pilot.getDirection(900,10), Direction::RIGHT);
}

TEST(pilotTests, shouldGetDirectionLeft)
{
    Pilot pilot;
    EXPECT_EQ(pilot.getDirection(10,900), Direction::LEFT);
}
