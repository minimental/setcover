/*
 * Compile with:
 * gcc -o tests_search_engine.exe tests_search_engine.c ..\cp_solver\search_engine.c
 */

#include "..\cp_solver\search_engine.h"
#include "tinytest.h"

int search_engine_should_accept_problem_description_and_maximum_cost_as_parameters() {
	struct problem specific_problem;
	double cost;
	search_engine(&specific_problem, cost);
	return 0;
}

TINYTEST_START_SUITE(SEARCH_ENGINE);
	TINYTEST_ADD_TEST(search_engine_should_accept_problem_description_and_maximum_cost_as_parameters, NULL, NULL);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(SEARCH_ENGINE);