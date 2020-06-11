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
int read_problem_description_from_file_should_store_set_specific_values {
	struct problem specific_problem;
	int every_element_value_is_mapped_to_its_sets_and_element_indices = 1;
	
	// element value 0
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0])[0]).set_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0])[1]).set_index == 1);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0])[2]).set_index == 4);
	
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0])[0]).element_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0])[1]).element_index == 0);
	every_element_value_is_mapped_to_its_sets_and_element_indices &= (((specific_problem.element_value_table[0])[2]).element_index == 0);
	
	TINYTEST_ASSERT(every_element_value_is_mapped_to_its_sets_and_element_indices);
	return 1;
}



TINYTEST_START_SUITE(GREEDY_WITH_LUT);
	TINYTEST_ADD_TEST(read_problem_description_from_file_should_store_number_of_elements_and_number_of_sets, NULL, NULL);
TINYTEST_END_SUITE();

TINYTEST_START_MAIN();
	TINYTEST_RUN_SUITE(GREEDY_WITH_LUT);
TINYTEST_END_MAIN();