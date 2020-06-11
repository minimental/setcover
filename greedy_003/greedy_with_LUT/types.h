struct index_pair {
	int set_index;
	int element_index;
};

struct dynamic_array_index_pair {
	int size;
	int capacity;
	
	struct index_pair* data;
	
	void (*add)(struct index_pair, struct dynamic_array_index_pair*);
};

struct set {
	double cost;
	int numberOfElements;
	int* elements;
};

struct problem {
	int number_of_sets;
	int number_of_elements;
	float* costs;
	struct dynamic_array_index_pair* element_value_table;
};