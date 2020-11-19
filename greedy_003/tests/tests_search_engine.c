/*
 * Compile with:
 * gcc -o tests_search_engine.exe tests_search_engine.c ..\cp_solver\search_engine.c ..\cp_solver\constraint_store.c ..\greedy_with_LUT\read_problem_description_from_file.c ..\greedy_with_LUT\greedy_with_LUT_core.c ..\greedy_with_LUT\dynamic_array_element.c ..\greedy_with_LUT\dynamic_array_index_pair.c ..\greedy_with_LUT\remove_element_from_all_sets.c ..\greedy_with_LUT\find_most_cost_efficient_set.c
 */

#include "tinytest.h"

#include "..\cp_solver\search_engine.h"

struct problem specific_problem;
struct solution specific_solution;

int setup_greedy_solution_6_1() {
	
	char *path = "..\\..\\data\\sc_6_1";

	// read problem description from file and create element-value-table
	read_problem_description_from_file(path, &specific_problem);

	// solve problem
	greedy_with_LUT_core(&specific_problem, &specific_solution);

}

int search_engine_should_accept_problem_description_and_maximum_cost_as_parameters() {
	double cost_limit;
	struct solution candidate;
	search_engine(&specific_problem, cost_limit, &candidate);
	return 1;
}

int search_engine_returns_000011_for_sc_6_1() {
	double cost_limit = specific_solution.cost;
	struct solution candidate;
	search_engine(&specific_problem, cost_limit, &candidate);
	if (candidate.number_of_sets_picked == 2)
		return 1;
	return 0;
}

TINYTEST_START_SUITE(SEARCH_ENGINE);
	// TINYTEST_ADD_TEST(search_engine_should_accept_problem_description_and_maximum_cost_as_parameters, NULL, NULL);
	TINYTEST_ADD_TEST(search_engine_returns_000011_for_sc_6_1, setup_greedy_solution_6_1, NULL);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(SEARCH_ENGINE);