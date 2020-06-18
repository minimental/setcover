void read_problem_description_from_file(char* path, struct problem* specific_problem);
void remove_element_from_all_sets(struct element _element, struct set* sets, struct dynamic_array_index_pair* element_value_table);
void find_most_cost_efficient_set(struct set* sets, int number_of_sets, float* minimum_efficiency, int* minimum_efficiency_set_index);