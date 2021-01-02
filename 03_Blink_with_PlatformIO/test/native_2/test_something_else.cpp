#include <unity.h>

const int FORTY_THREE = 43;

void setup() {
}

void loop() {
}

void test_equality(void) {
    TEST_ASSERT_EQUAL(43, FORTY_THREE);
}

int main() {
    UnityBegin("test/native_1/test_something_else.cpp");
    RUN_TEST(test_equality);
    return (UnityEnd());
}
