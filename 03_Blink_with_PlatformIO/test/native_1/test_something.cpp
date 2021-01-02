#include <unity.h>

const int FORTY_TWO = 42;

void setup() {
}

void loop() {
}

void test_equality(void) {
    TEST_ASSERT_EQUAL(42, FORTY_TWO);
}

int main() {
    UnityBegin("test/native_1/test_something.cpp");
    RUN_TEST(test_equality);
    return (UnityEnd());
}
