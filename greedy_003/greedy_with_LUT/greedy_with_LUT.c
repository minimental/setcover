#include "types.h"

void greedy_with_LUT(struct problem* specific_problem, struct solution* specific_solution) {
	// pick the minimum efficiency set, and iterate over its elements, successively removing them from the other sets
	int current_set_index, current_element_index;
	
	current_set_index = specific_problem->minimum_efficiency_set_index;
	current_element_index = specific_problem->sets[current_set_index].index_of_root_element;
	
	struct element current_element;
	
	// iterate over elements
	while (current_element_index != -1) {
		
		// look up element to be removed
		current_element = *(specific_problem->sets[current_set_index].elements->data[current_element_index]);
		
		// remove element from all sets
		remove_element_from_all_sets(current_element, specific_problem->sets, specific_problem->element_value_table);
		if ((++specific_solution->number_of_elements_picked) == specific_problem->number_of_elements) {
			// mark stop for outer set loop
			break;
		}
		
		// next element
		current_element_index = specific_problem->sets[current_set_index].elements->data[current_element_index].index_next;
	}
	
	// find new cost efficient set
	find_most_cost_efficient_set(specific_problem->sets, specific_problem->number_of_sets, specific_problem->minimum_efficiency, specific_problem->minimum_efficiency_set_index);
	
}