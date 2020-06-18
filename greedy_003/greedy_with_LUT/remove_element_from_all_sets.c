#include "types.h"

void remove_element_from_all_sets(struct element _element, struct set* sets, struct dynamic_array_index_pair* element_value_table, int* minimum_efficiency_set_index, float* minimum_efficiency) {
	
	int current_set_index, current_element_index, current_previous_element_index, current_next_element_index;
	
	int number_of_sets = element_value_table->size;
	for (int i = 0; i < number_of_sets; ++i) {
		
		current_set_index = ((element_value_table[_element.value]).data[i]).set_index;
		current_element_index = ((element_value_table[_element.value]).data[i]).element_index;
		current_previous_element_index = sets[current_set_index].elements->data[current_element_index].index_previous;
		current_next_element_index = sets[current_set_index].elements->data[current_element_index].index_next;
		
		--(sets[current_set_index].number_of_elements);
		
		// identify most cost efficient set index
		sets[current_set_index].efficiency = sets[current_set_index].cost / sets[current_set_index].number_of_elements;
		if (sets[current_set_index].efficiency < *minimum_efficiency) {
			*minimum_efficiency = sets[current_set_index].efficiency;
			*minimum_efficiency_set_index = current_set_index;
		}
		
		// special case: current element index points to first element of set
		if (current_element_index == sets[current_set_index].index_of_root_element) {
			// special case: only one element remaining
			if (current_next_element_index == -1) {
				sets[current_set_index].index_of_root_element = -1;	
				continue;
			}
				
			sets[current_set_index].index_of_root_element = current_next_element_index;
			continue;
		}
				
		// special case: current element index points to last element of set
		if (sets[current_set_index].elements->data[current_element_index].index_next == -1)	{
			sets[current_set_index].elements->data[current_previous_element_index].index_next = -1;
			continue;
		}
		
		// current element is neither first nor last element
		sets[current_set_index].elements->data[current_previous_element_index].index_next = current_next_element_index;
		sets[current_set_index].elements->data[current_next_element_index].index_previous = current_previous_element_index;
	}
}