#include "gtest/gtest.h"
#include "foo.h"

TEST(colourMatcherTests, shouldRecogniseReadingAsColour)
{
    Foo foo(nullptr);
    EXPECT_TRUE( foo.isMatch( 33, 42 ) );
    EXPECT_TRUE( foo.isMatch( 51, 42 ) );
}

TEST(colourMatcherTests, shouldRejectReadingAsColour)
{
    Foo foo(nullptr);
    EXPECT_FALSE( foo.isMatch( 32, 42 ) );
    EXPECT_FALSE( foo.isMatch( 52, 42 ) );
}

TEST(colourMatcherTests, shouldRecogniseBlack)
{
    Foo foo(nullptr);
    EXPECT_EQ(foo.getColour(Foo::BLACK), Colour::BLACK);
}

TEST(colourMatcherTests, shouldRecogniseBlue)
{
    Foo foo(nullptr);
    EXPECT_EQ(foo.getColour(Foo::BLUE), Colour::BLUE);
}

TEST(colourMatcherTests, shouldRecogniseGreen)
{
    Foo foo(nullptr);
    EXPECT_EQ(foo.getColour(Foo::GREEN), Colour::GREEN);
}

TEST(colourMatcherTests, shouldRecogniseRed)
{
    Foo foo(nullptr);
    EXPECT_EQ(foo.getColour(Foo::RED), Colour::RED);
}

TEST(colourMatcherTests, shouldNotRecogniseUnknownColour)
{
    Foo foo(nullptr);
    EXPECT_EQ(foo.getColour(123), Colour::UNDEFINED);
}
