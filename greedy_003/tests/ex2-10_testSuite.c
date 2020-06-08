// Exercise 2-10. Rewrite the function `lower', which converts upper case letters to lower case, with a conditional expression instead of `if-else'.

#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "tinytest.h"
#include "..\lower.h"

// declare test suite
TINYTEST_DECLARE_SUITE(LOWER);

int lower_should_turn_A_into_a(const char* pName) {
	TINYTEST_ASSERT(lower('A') == 'a');
	return 1;
}

int lower_should_turn_an_arbitrary_uppercase_letter_into_lowercase(const char* pName) {
	srand(time(NULL));
	int character = (rand() % 26) + 0x41;
	printf("Test 2: Character under test: '%c'\n", character);
	TINYTEST_ASSERT(lower(character) == tolower(character));
}

// add tests to test suite
TINYTEST_START_SUITE(LOWER);
	TINYTEST_ADD_TEST(lower_should_turn_A_into_a,NULL,NULL);
	TINYTEST_ADD_TEST(lower_should_turn_an_arbitrary_uppercase_letter_into_lowercase,NULL,NULL);
TINYTEST_END_SUITE();

// run test suite
TINYTEST_START_MAIN();
	TINYTEST_RUN_SUITE(LOWER);
TINYTEST_END_MAIN();