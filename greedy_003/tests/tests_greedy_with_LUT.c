#include <stdio.h>

#include "tinytest.h"
#include "..\greedy_with_LUT\types.h"
#include "..\greedy_with_LUT\functions.h"

TINYTEST_DECLARE_SUITE(GREEDY_WITH_LUT);

// greedy with look-up-table should read a file with the problem description: header
int read_problem_description_from_file_should_store_number_of_elements_and_number_of_sets(const char* pName) {
	struct problem specific_problem;
	char* path_to_file = "..\\..\\data\\sc_6_1";
	read_problem_description_from_file(path_to_file, &specific_problem);
	TINYTEST_ASSERT((specific_problem.number_of_sets == 6) && (specific_problem.number_of_elements == 9));
	return 1;
}

// greedy with look-up-table should read a file with the problem description: body
int read_problem_description_from_file_should_store_element_value_table(const char* pName) {
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_6_1";
	read_problem_description_from_file(path_to_file, &specific_problem);	
	
	int every_element_value_is_mapped_to_its_sets_and_element_indices = 1;
	
	// element value 0
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0]).data[0]).set_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0]).data[1]).set_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0]).data[2]).set_index == 4);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0]).data[0]).element_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0]).data[1]).element_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0]).data[2]).element_index == 0);
	
	// element value 1
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[1]).data[0]).set_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[1]).data[1]).set_index == 2);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[1]).data[2]).set_index == 5);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[1]).data[0]).element_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[1]).data[1]).element_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[1]).data[2]).element_index == 0);
	
	// element value 2
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[2]).data[0]).set_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[2]).data[1]).set_index == 2);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[2]).data[2]).set_index == 5);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[2]).data[0]).element_index == 2);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[2]).data[1]).element_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[2]).data[2]).element_index == 1);
	
	// element value 3
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[3]).data[0]).set_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[3]).data[1]).set_index == 4);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[3]).data[0]).element_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[3]).data[1]).element_index == 1);
	
	// element value 4
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[4]).data[0]).set_index == 4);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[4]).data[0]).element_index == 2);
	
	// element value 5
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[5]).data[0]).set_index == 1);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[5]).data[0]).element_index == 3);
	
	// element value 6
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[0]).set_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[1]).set_index == 2);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[2]).set_index == 3);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[3]).set_index == 4);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[0]).element_index == 4);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[1]).element_index == 3);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[2]).element_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[6]).data[3]).element_index == 4);
	
	// element value 7
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[7]).data[0]).set_index == 3);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[7]).data[1]).set_index == 5);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[7]).data[0]).element_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[7]).data[1]).element_index == 2);
	
	// element value 8
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[0]).set_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[1]).set_index == 2);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[2]).set_index == 3);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[3]).set_index == 5);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[0]).element_index == 5);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[1]).element_index == 4);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[2]).element_index == 2);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[8]).data[3]).element_index == 3);
	
	TINYTEST_ASSERT(every_element_value_is_mapped_to_its_sets_and_element_indices);
	return 1;
}

// greedy with look-up-table should create sets: a set is a data type including its cost efficiency, and a list of element data types, containing value and indices to previous and next values; every set corresponds to a line in the body of the file
int read_problem_description_from_file_should_store_cost_efficiency(const char* pName) {
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_6_1";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	int all_efficiencies_are_included_in_sets = 1;
	
	all_efficiencies_are_included_in_sets &= (((specific_problem.sets)[0]).efficiency == 1.f/2);
	all_efficiencies_are_included_in_sets &= (((specific_problem.sets)[1]).efficiency == 1.f/6);
	all_efficiencies_are_included_in_sets &= (((specific_problem.sets)[2]).efficiency == 1.f/5);
	all_efficiencies_are_included_in_sets &= (((specific_problem.sets)[3]).efficiency == 1.f/3);
	all_efficiencies_are_included_in_sets &= (((specific_problem.sets)[4]).efficiency == 1.f/5);
	all_efficiencies_are_included_in_sets &= (((specific_problem.sets)[5]).efficiency == 1.f/4);

	TINYTEST_ASSERT(all_efficiencies_are_included_in_sets);
	
	return 1;
}

int read_problem_description_should_identify_the_most_cost_efficient_set(const char* pName) {
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_9_0";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	TINYTEST_ASSERT(specific_problem.minimum_efficiency_set_index == 0);
	
	return 1;
}

int read_problem_description_from_file_should_store_the_values_of_the_elements_of_the_sets(const char* pName) {
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_6_1";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	int all_elements_included_in_sets = 1;
	
	// set 0: 0 3
	all_elements_included_in_sets &= (specific_problem.sets[0].elements->data[0].value == 0);
	all_elements_included_in_sets &= (specific_problem.sets[0].elements->data[1].value == 3);
	
	// set 1: 0 1 2 5 6 8
	all_elements_included_in_sets &= (specific_problem.sets[1].elements->data[0].value == 0);
	all_elements_included_in_sets &= (specific_problem.sets[1].elements->data[1].value == 1);
	all_elements_included_in_sets &= (specific_problem.sets[1].elements->data[2].value == 2);
	all_elements_included_in_sets &= (specific_problem.sets[1].elements->data[3].value == 5);
	all_elements_included_in_sets &= (specific_problem.sets[1].elements->data[4].value == 6);
	all_elements_included_in_sets &= (specific_problem.sets[1].elements->data[5].value == 8);
	
	// set 2: 1 2 5 6 8
	all_elements_included_in_sets &= (specific_problem.sets[2].elements->data[0].value == 1);
	all_elements_included_in_sets &= (specific_problem.sets[2].elements->data[1].value == 2);
	all_elements_included_in_sets &= (specific_problem.sets[2].elements->data[2].value == 5);
	all_elements_included_in_sets &= (specific_problem.sets[2].elements->data[3].value == 6);
	all_elements_included_in_sets &= (specific_problem.sets[2].elements->data[4].value == 8);
	
	// set 3: 6 7 8
	all_elements_included_in_sets &= (specific_problem.sets[3].elements->data[0].value == 6);
	all_elements_included_in_sets &= (specific_problem.sets[3].elements->data[1].value == 7);
	all_elements_included_in_sets &= (specific_problem.sets[3].elements->data[2].value == 8);
	
	// set 4: 0 3 4 5 6
	all_elements_included_in_sets &= (specific_problem.sets[4].elements->data[0].value == 0);
	all_elements_included_in_sets &= (specific_problem.sets[4].elements->data[1].value == 3);
	all_elements_included_in_sets &= (specific_problem.sets[4].elements->data[2].value == 4);
	all_elements_included_in_sets &= (specific_problem.sets[4].elements->data[3].value == 5);
	all_elements_included_in_sets &= (specific_problem.sets[4].elements->data[4].value == 6);
	
	// set 5: 1 2 7 8
	all_elements_included_in_sets &= (specific_problem.sets[5].elements->data[0].value == 1);
	all_elements_included_in_sets &= (specific_problem.sets[5].elements->data[1].value == 2);
	all_elements_included_in_sets &= (specific_problem.sets[5].elements->data[2].value == 7);
	all_elements_included_in_sets &= (specific_problem.sets[5].elements->data[3].value == 8);
	
	TINYTEST_ASSERT(all_elements_included_in_sets);
	
	return 1;
}

// greedy with look-up-table should remove an element from all sets that is currently being iterated over in the most cost-efficient set
int remove_element_from_all_sets_should_remove_an_element_from_all_sets(const char* pName) {
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_6_1";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	struct element element_to_be_removed;
	element_to_be_removed.value = 0;

	remove_element_from_all_sets(element_to_be_removed, specific_problem.sets, specific_problem.element_value_table);
	
	int the_element_is_still_there = 0;
	int number_of_sets = specific_problem.number_of_sets;
	int number_of_elements, index_of_current_element;
	
	for (int i = 0; i < number_of_sets; ++i) {
		
		number_of_elements = specific_problem.sets[i].number_of_elements;
		index_of_current_element = specific_problem.sets[i].index_of_root_element;
		while (index_of_current_element != -1) {
			the_element_is_still_there |= (((specific_problem.sets[i].elements->data[index_of_current_element].value) == 0) ? 1 : 0);
			// next element
			index_of_current_element = specific_problem.sets[i].elements->data[index_of_current_element].index_next;
		}
	}
	
	TINYTEST_ASSERT(!the_element_is_still_there);
	
	return 1;
}

// greedy with look-up-table should be able to identify the most cost-efficient set after each removal of an element from all sets
int find_most_cost_efficient_set_should_identify_the_most_cost_efficient_set(const char* pName) {

	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_15_0";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	struct element element_to_be_removed;
	element_to_be_removed.value = 30;
	
	remove_element_from_all_sets(element_to_be_removed, specific_problem.sets, specific_problem.element_value_table);
	
	find_most_cost_efficient_set(specific_problem.sets, specific_problem.number_of_sets, &specific_problem.minimum_efficiency, &specific_problem.minimum_efficiency_set_index);
	
	TINYTEST_ASSERT(specific_problem.minimum_efficiency_set_index == 1);
	
	return 1;
}

// greedy with look-up-table should be able to identify the most cost-efficient set after each removal of an element from all sets (2)
int find_most_cost_efficient_set_should_identify_the_most_cost_efficient_set_after_removal_of_multiple_values(const char* pName) {
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_27_0";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	struct element elements_to_be_removed[14];
	elements_to_be_removed[0].value = 108;
	elements_to_be_removed[1].value = 3;
	elements_to_be_removed[2].value = 30;
	elements_to_be_removed[3].value = 97;
	elements_to_be_removed[4].value = 96;
	elements_to_be_removed[5].value = 34;
	elements_to_be_removed[6].value = 1;
	elements_to_be_removed[7].value = 47;
	elements_to_be_removed[8].value = 33;
	elements_to_be_removed[9].value = 102;
	elements_to_be_removed[10].value = 90;
	elements_to_be_removed[11].value = 18;
	elements_to_be_removed[12].value = 29;
	elements_to_be_removed[13].value = 54;
	
	for (int e = 0; e < 14; ++e)
		remove_element_from_all_sets(elements_to_be_removed[e], specific_problem.sets, specific_problem.element_value_table);
	
	find_most_cost_efficient_set(specific_problem.sets, specific_problem.number_of_sets, &specific_problem.minimum_efficiency, &specific_problem.minimum_efficiency_set_index);
	
	TINYTEST_ASSERT(specific_problem.minimum_efficiency_set_index == 3);
	
	return 1;
	
}

// greedy with LUT should be able to remove every element from a set
int remove_element_from_all_sets_should_be_able_to_remove_every_element_from_a_set(const char* pName) {
	
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_9_0";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	struct element elements_to_be_removed[4];
	elements_to_be_removed[0].value = 1;
	elements_to_be_removed[1].value = 2;
	elements_to_be_removed[2].value = 6;
	elements_to_be_removed[3].value = 9;
	
	for (int e = 0; e < 4; ++e)
		remove_element_from_all_sets(elements_to_be_removed[e], specific_problem.sets, specific_problem.element_value_table);
	
	TINYTEST_ASSERT((specific_problem.sets[0].number_of_elements == 0) && (specific_problem.sets[0].index_of_root_element == -1));
	
	return 1;
}

// greedy with LUT should remove only one element if the same element is removed twice
int remove_element_from_all_sets_should_remove_only_one_element_if_called_twice_on_the_same_element(const char* pName) {
	
	struct problem specific_problem;
	
	char* path_to_file = "..\\..\\data\\sc_9_0";
	read_problem_description_from_file(path_to_file, &specific_problem);

	struct element element_to_be_removed;
	element_to_be_removed.value = 1;
	
	remove_element_from_all_sets(element_to_be_removed, specific_problem.sets, specific_problem.element_value_table);
	remove_element_from_all_sets(element_to_be_removed, specific_problem.sets, specific_problem.element_value_table);
	
	TINYTEST_ASSERT((specific_problem.sets[0].number_of_elements == 3));
	
}

// greedy with LUT should keep track which set indices are part of the solution
int greedy_with_LUT_should_return_the_indices_of_the_picked_sets(const char* pName) {
	
	int reference_solution[] = {0, 1, 0, 1, 1, 0};
	int all_elements_match = 1;
	
	struct problem specific_problem;
	struct solution specific_solution;
	
	char* path_to_file = "..\\..\\data\\sc_6_1";
	read_problem_description_from_file(path_to_file, &specific_problem);
	
	greedy_with_LUT_core(&specific_problem, &specific_solution);
	
	printf("\n");
	printf("Computed solution\n");
	printf("=================\n");
	
	for (int i = 0; i < 6; ++i) {
		printf("%i ", specific_solution.mask_of_picked_sets[i]);
		all_elements_match &= (reference_solution[i] == specific_solution.mask_of_picked_sets[i]);		
	}
	
	printf("\n");
	
	TINYTEST_ASSERT(all_elements_match);
	return 1;
}


TINYTEST_START_SUITE(GREEDY_WITH_LUT);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_number_of_elements_and_number_of_sets, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_element_value_table, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_cost_efficiency, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_should_identify_the_most_cost_efficient_set, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_the_values_of_the_elements_of_the_sets, NULL, NULL);
	TINYTEST_ADD_TEST(remove_element_from_all_sets_should_remove_an_element_from_all_sets, NULL, NULL);
	TINYTEST_ADD_TEST(find_most_cost_efficient_set_should_identify_the_most_cost_efficient_set, NULL, NULL);
	TINYTEST_ADD_TEST(find_most_cost_efficient_set_should_identify_the_most_cost_efficient_set_after_removal_of_multiple_values, NULL, NULL);
	TINYTEST_ADD_TEST(remove_element_from_all_sets_should_be_able_to_remove_every_element_from_a_set, NULL, NULL);
	TINYTEST_ADD_TEST(remove_element_from_all_sets_should_remove_only_one_element_if_called_twice_on_the_same_element, NULL, NULL);
	TINYTEST_ADD_TEST(greedy_with_LUT_should_return_the_indices_of_the_picked_sets, NULL, NULL);
TINYTEST_END_SUITE();

TINYTEST_START_MAIN();
	TINYTEST_RUN_SUITE(GREEDY_WITH_LUT);
TINYTEST_END_MAIN();