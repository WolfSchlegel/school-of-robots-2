#include <unity.h>

#include "../../lib/morse/src/morse_mock.h"

MorseMock morseMock;

void test_dash(void) {
    // given
    morseMock.resetCounters();

    // when
    morseMock.dash();

    // then
    TEST_ASSERT_EQUAL(1, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterWordCounter());
}

void test_dot(void) {
    // given
    morseMock.resetCounters();

    // when
    morseMock.dot();

    // then
    TEST_ASSERT_EQUAL(0, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(1, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterWordCounter());
}

void test_pause_after_letter(void) {
    // given
    morseMock.resetCounters();

    // when
    morseMock.pauseAfterLetter();

    // then
    TEST_ASSERT_EQUAL(0, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(1, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterWordCounter());
}

void test_pause_after_word(void) {
    // given
    morseMock.resetCounters();

    // when
    morseMock.pauseAfterWord();

    // then
    TEST_ASSERT_EQUAL(0, morseMock.getDashCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getDotCounter());
    TEST_ASSERT_EQUAL(0, morseMock.getPauseAfterLetterCounter());
    TEST_ASSERT_EQUAL(1, morseMock.getPauseAfterWordCounter());
}

int main() {
    UnityBegin("test/native_1/test_alphabet.cpp");
    RUN_TEST(test_dash);
    RUN_TEST(test_dot);
    RUN_TEST(test_pause_after_letter);
    RUN_TEST(test_pause_after_word);
    return (UnityEnd());
}
