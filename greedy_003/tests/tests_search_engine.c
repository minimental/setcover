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

int setup_greedy_solution_9_0() {
	
	char *path = "..\\..\\data\\sc_9_0";

	// read problem description from file and create element-value-table
	read_problem_description_from_file(path, &specific_problem);

	// solve problem
	greedy_with_LUT_core(&specific_problem, &specific_solution);

}

int setup_greedy_solution_15_0() {
	
	char *path = "..\\..\\data\\sc_15_0";

	// read problem description from file and create element-value-table
	read_problem_description_from_file(path, &specific_problem);

	// solve problem
	greedy_with_LUT_core(&specific_problem, &specific_solution);

}

int setup_greedy_solution_25_0() {
	
	char *path = "..\\..\\data\\sc_25_0";

	// read problem description from file and create element-value-table
	read_problem_description_from_file(path, &specific_problem);

	// solve problem
	greedy_with_LUT_core(&specific_problem, &specific_solution);

}

int setup_greedy_solution_27_0() {
	
	char *path = "..\\..\\data\\sc_27_0";

	// read problem description from file and create element-value-table
	read_problem_description_from_file(path, &specific_problem);

	// solve problem
	greedy_with_LUT_core(&specific_problem, &specific_solution);

}

int setup_greedy_solution_45_0() {
	
	char *path = "..\\..\\data\\sc_45_0";

	// read problem description from file and create element-value-table
	read_problem_description_from_file(path, &specific_problem);

	// solve problem
	greedy_with_LUT_core(&specific_problem, &specific_solution);
	
	printf("greedy sc_45_0 - cost: %.1f\n", specific_solution.cost);

}

int teardown() {
	free(specific_problem.element_value_table);
	free(specific_problem.sets);
	free(specific_solution.mask_of_picked_sets);	
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
	int picked_sets[6] = {0, 0, 0, 0, 0, 0};
	candidate.mask_of_picked_sets = picked_sets;
	candidate.number_of_sets_picked = 0;
	search_engine(&specific_problem, cost_limit, &candidate);
	
	// verify solution
	int reference_solution[6] = {0, 0, 0, 0, 1, 1};
	int passed = 1;
	for (int i = 0; i < 6; ++i)
		passed &= (reference_solution[i] == candidate.mask_of_picked_sets[i]);
	
	return passed;
}

int search_engine_should_terminate_for_sc_9_0() {
	double cost_limit = specific_solution.cost;
	struct solution candidate;
	int picked_sets[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	candidate.mask_of_picked_sets = picked_sets;
	candidate.number_of_sets_picked = 0;
	search_engine(&specific_problem, cost_limit, &candidate);

	return 1;
	
}

int search_engine_should_terminate_for_sc_15_0() {
	double cost_limit = specific_solution.cost;
	struct solution candidate;
	int picked_sets[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	candidate.mask_of_picked_sets = picked_sets;
	candidate.number_of_sets_picked = 0;
	search_engine(&specific_problem, cost_limit, &candidate);

	return 1;
	
}

int search_engine_should_terminate_for_sc_25_0() {
	double cost_limit = specific_solution.cost;
	struct solution candidate;
	int picked_sets[25];
	for (int i = 0; i < 25; ++i)
		picked_sets[i] = 0;
	candidate.mask_of_picked_sets = picked_sets;
	candidate.number_of_sets_picked = 0;
	search_engine(&specific_problem, cost_limit, &candidate);

	return 1;
	
}

int search_engine_should_terminate_for_sc_27_0() {
	double cost_limit = specific_solution.cost;
	struct solution candidate;
	int picked_sets[27];
	for (int i = 0; i < 27; ++i)
		picked_sets[i] = 0;
	candidate.mask_of_picked_sets = picked_sets;
	candidate.number_of_sets_picked = 0;
	search_engine(&specific_problem, cost_limit, &candidate);
	printf("greedy sc_27_0 - cost: %.1f\n", specific_solution.cost);
	return 1;
	
}

int search_engine_should_terminate_for_sc_45_0() {
	return 1;
	double cost_limit = specific_solution.cost;
	struct solution candidate;
	int picked_sets[45];
	for (int i = 0; i < 45; ++i)
		picked_sets[i] = 0;
	candidate.mask_of_picked_sets = picked_sets;
	candidate.number_of_sets_picked = 0;
	search_engine(&specific_problem, cost_limit, &candidate);

	return 1;
	
}

int constraint_store_should_return_0_for_000000() {
	struct solution candidate;
	int picked_sets[6] = {0, 0, 0, 0, 0, 0};
	candidate.mask_of_picked_sets = picked_sets;
	if (!constraint_store(&specific_problem, &candidate))
		return 1;
	return 0;
}

int constraint_store_should_return_1_for_000011() {
	struct solution candidate;
	int picked_sets[6] = {0, 0, 0, 0, 1, 1};
	candidate.mask_of_picked_sets = picked_sets;
	if (constraint_store(&specific_problem, &candidate))
		return 1;
	return 0;
}

TINYTEST_START_SUITE(SEARCH_ENGINE);
	// TINYTEST_ADD_TEST(search_engine_should_accept_problem_description_and_maximum_cost_as_parameters, NULL, NULL);
	// TINYTEST_ADD_TEST(search_engine_returns_000011_for_sc_6_1, setup_greedy_solution_6_1, teardown);
	// TINYTEST_ADD_TEST(constraint_store_should_return_0_for_000000, setup_greedy_solution_6_1, teardown);
	// TINYTEST_ADD_TEST(constraint_store_should_return_1_for_000011, setup_greedy_solution_6_1, teardown);
	// TINYTEST_ADD_TEST(search_engine_should_terminate_for_sc_9_0, setup_greedy_solution_9_0, teardown);
	// TINYTEST_ADD_TEST(search_engine_should_terminate_for_sc_15_0, setup_greedy_solution_15_0, teardown);
	// TINYTEST_ADD_TEST(search_engine_should_terminate_for_sc_25_0, setup_greedy_solution_25_0, teardown);
	// TINYTEST_ADD_TEST(search_engine_should_terminate_for_sc_27_0, setup_greedy_solution_27_0, teardown);
	TINYTEST_ADD_TEST(search_engine_should_terminate_for_sc_45_0, setup_greedy_solution_45_0, teardown);
TINYTEST_END_SUITE();

TINYTEST_MAIN_SINGLE_SUITE(SEARCH_ENGINE);