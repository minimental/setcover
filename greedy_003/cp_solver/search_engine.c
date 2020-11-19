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
	
	if (candidate->cost >= cost_limit)
		return 0; /* prune */
	
	// leaf
	if (depth == specific_problem->number_of_sets)
		if (constraint_store(specific_problem, candidate))
			return 1; /* new solution found */
		else
			return 0;
	
	// go the `1' way
	candidate->mask_of_picked_sets[depth] = 1;
	++(candidate->number_of_sets_picked);
	candidate->cost += specific_problem->sets[depth].cost;		
	if (depth_first_search(depth + 1, cost_limit, candidate, specific_problem))
		return 1;

	// go the `0' way
	candidate->mask_of_picked_sets[depth] = 0;
	--(candidate->number_of_sets_picked);
	candidate->cost -= specific_problem->sets[depth].cost;		
	return depth_first_search(depth + 1, cost_limit, candidate, specific_problem);
		
}

void search_engine(const struct problem *specific_problem, double cost_limit, struct solution *candidate) {
	
	// find new solution candidate
	if (depth_first_search(0, cost_limit, candidate, specific_problem))
		printf("New solution found.\n");
	
}