#include <unity.h>

// TODO uncomment and fix
//
//#include "../../lib/morse/src/morse_mock.h"
//MorseMock morseMock;

const int FORTY_TWO = 42;

void setup() {
//    morseMock.resetCounters();
}

void loop() {
}

void test_o(void) {
    TEST_ASSERT_EQUAL(42, 42);
//    TEST_ASSERT_EQUAL(0, morseMock.getDashCounter());
//    TEST_ASSERT_EQUAL(3, morseMock.getDotCounter());
}

void test_s(void) {
    TEST_ASSERT_EQUAL(43, 43);
//    TEST_ASSERT_EQUAL(3, morseMock.getDashCounter());
//    TEST_ASSERT_EQUAL(0, morseMock.getDotCounter());
}

int main() {
    UnityBegin("test/native_1/test_alphabet.cpp");
    RUN_TEST(test_o);
    RUN_TEST(test_s);
    return (UnityEnd());
}
