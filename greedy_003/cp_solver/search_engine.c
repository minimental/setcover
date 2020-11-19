#include "search_engine.h"

#include <stdio.h>
#include <stdlib.h>

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
	
	// for debugging purposes
	printf("dfs (depth = %i): %s\n", depth, convert_binary_integer_array_to_character_array(candidate->mask_of_picked_sets, specific_problem->number_of_sets));
	
	// base case: reached the leaves of the search tree
	if (depth == specific_problem->number_of_sets)
		return 1;
	
	// base case: cost exceeds limit
	if (candidate->cost >= cost_limit)
		return 0;
	
	// choose current set
	candidate->mask_of_picked_sets[depth] = 1;
	++(candidate->number_of_sets_picked);
	candidate->cost += specific_problem->sets[depth].cost;
	
	// recursive call
	if (!depth_first_search(depth + 1, cost_limit, candidate, specific_problem)) {
		
		// wrong turn: remove picked set
		candidate->mask_of_picked_sets[depth] = 0;
		--(candidate->number_of_sets_picked);
		candidate->cost -= specific_problem->sets[depth].cost;
		depth_first_search(depth + 1, cost_limit, candidate, specific_problem);
		
	}
		
	// base case: cost below limit
	return 1;
		
}

void search_engine(const struct problem *specific_problem, double cost_limit, struct solution *candidate) {
	
	// find new solution candidate
	depth_first_search(0, cost_limit, candidate, specific_problem);
	
}