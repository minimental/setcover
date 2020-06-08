#include <stdio.h>
#include <stdlib.h>

struct dynamic_array {
	int size;
	int capacity;
	
	int* data;
	
	void (*add)(int, struct dynamic_array*);
};

void _double_capacity(struct dynamic_array* array) {
	int* extended_data = calloc(2 * array->capacity, sizeof(int));		
	for (int i = 0; i < array->capacity; ++i)
		extended_data[i] = (array->data)[i];
	free(array->data);
	array->data = extended_data;
	array->capacity *= 2;
}

void _add(int arg, struct dynamic_array* array) {
	if (array->size == array->capacity)
		_double_capacity(array);
	array->data[(array->size)++] = arg;
}

void initialize(struct dynamic_array* array) {
	array->data = calloc(16, sizeof(int));
	array->size = 0;
	array->capacity = 16;
	array->add = _add;
}