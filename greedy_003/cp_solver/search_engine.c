#include "search_engine.h"

#include <stdio.h>
#include <stdlib.h>

int number_of_calls_to_depth_first_search = 0;
int maximum_number_of_depth_first_search_on_stack = 0;

char* convert_binary_integer_array_to_character_array(int* binary_integer_array, int number_of_elements) {
	
	char* converted_array = calloc(2 * number_of_elements + 1, sizeof(char));
	
	for (int i = 0; i < number_of_elements; ++i) {
		converted_array[2*i] = binary_integer_array[i] ? '1' : '0';
		converted_array[2*i + 1] = ' ';
	}
	
	converted_array[2 * number_of_elements - 1] = '\0';
	
	return converted_array;
}

int depth_first_search(int depth, double cost_limit, struct solution *candidate, const struct problem *specific_problem) {
	
	++number_of_calls_to_depth_first_search;
	maximum_number_of_depth_first_search_on_stack = number_of_calls_to_depth_first_search > maximum_number_of_depth_first_search_on_stack ? number_of_calls_to_depth_first_search : maximum_number_of_depth_first_search_on_stack;
	
	if (candidate->cost >= cost_limit) {
		--number_of_calls_to_depth_first_search;
		return 0; /* prune */
	}
		
	
	// leaf
	if (depth == specific_problem->number_of_sets)
		if (constraint_store(specific_problem, candidate)) {
			--number_of_calls_to_depth_first_search;
			return 1; /* new solution found */
		}
		else {
			--number_of_calls_to_depth_first_search;
			return 0;
		}
			
	
	// go the `1' way
	candidate->mask_of_picked_sets[depth] = 1;
	++(candidate->number_of_sets_picked);
	candidate->cost += specific_problem->sets[depth].cost;		
	if (depth_first_search(depth + 1, cost_limit, candidate, specific_problem)) {
		--number_of_calls_to_depth_first_search;
		return 1;
	}
		

	// go the `0' way
	candidate->mask_of_picked_sets[depth] = 0;
	--(candidate->number_of_sets_picked);
	candidate->cost -= specific_problem->sets[depth].cost;
	--number_of_calls_to_depth_first_search;
	return depth_first_search(depth + 1, cost_limit, candidate, specific_problem);
		
}

void search_engine(const struct problem *specific_problem, double cost_limit, struct solution *candidate) {
	
	// find new solution candidate
	number_of_calls_to_depth_first_search = 0;
	maximum_number_of_depth_first_search_on_stack = 0;
	if (depth_first_search(0, cost_limit, candidate, specific_problem)) {
		printf("New solution found. Cost: %.1f \n", candidate->cost);
		printf("%s\n", convert_binary_integer_array_to_character_array(candidate->mask_of_picked_sets, specific_problem->number_of_sets));
	}
	printf("search_engine: Maximum number of depth-first search on stack: %i\n", maximum_number_of_depth_first_search_on_stack);
	
}