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
}



TINYTEST_START_SUITE(GREEDY_WITH_LUT);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_number_of_elements_and_number_of_sets, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_element_value_table, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_cost_efficiency, NULL, NULL);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_the_values_of_the_elements_of_the_sets, NULL, NULL);
	TINYTEST_ADD_TEST(remove_element_from_all_sets_should_remove_an_element_from_all_sets, NULL, NULL);
TINYTEST_END_SUITE();

TINYTEST_START_MAIN();
	TINYTEST_RUN_SUITE(GREEDY_WITH_LUT);
TINYTEST_END_MAIN();