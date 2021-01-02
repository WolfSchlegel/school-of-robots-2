#include <unity.h>

#include "../../lib/morse/src/alphabet.h"
#include "../../lib/morse/src/morse_mock.h"

MorseMock morseMock;
Alphabet alphabet(&morseMock);

void test_o(void) {
    // given
    morseMock.resetCounters();

    // when
    alphabet.o();

    // then
    TEST_ASSERT_EQUAL(3, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(1, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterWordCounter());
}

void test_s(void) {
    // given
    morseMock.resetCounters();

    // when
    alphabet.s();

    // then
    TEST_ASSERT_EQUAL(0, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(3, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(1, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterWordCounter());
}

void test_sos(void) {
    // given
    morseMock.resetCounters();

    // when
    alphabet.s();
    alphabet.o();
    alphabet.s();
    alphabet.pause();

    // then
    TEST_ASSERT_EQUAL(3, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(6, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(3, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(1, morseMock.getPauseAfterWordCounter());
}

int main() {
    UnityBegin("test/native_1/test_alphabet.cpp");
    RUN_TEST(test_o);
    RUN_TEST(test_s);
    RUN_TEST(test_sos);
    return (UnityEnd());
}
