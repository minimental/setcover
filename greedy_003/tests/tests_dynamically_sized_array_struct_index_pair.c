/*
 * Tests specified properties of a dynamically sized array with elements of type `struct index_pair'
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
#include "tinytest.h"
#include "..\greedy_with_LUT\dynamic_array_index_pair.h"

TINYTEST_DECLARE_SUITE(DYN_ARRAY_INDEX_PAIR);

// the dynamic array should have an initial size of 16
int dynamic_array_should_have_an_initial_size_of_16(const char* pName) {
	struct dynamic_array_index_pair array;
	initialize(&array);
	TINYTEST_ASSERT(array.capacity == 16);
	return 1;
}

// the dynamic array should support adding functionality
int dynamic_array_should_support_adding_functionality(const char* pName) {
	struct dynamic_array_index_pair array;
	initialize(&array);
	struct index_pair element;
	array.add(element, &array);
	TINYTEST_ASSERT(array.size == 1);
	return 1;
}

// the dynamic array should resize to 32 if the 17-th element is added.
int dynamic_array_should_resize_to_32_if_the_17th_element_is_added(const char* pName) {
	struct dynamic_array_index_pair array;
	initialize(&array);
	struct index_pair element;
	for (int i = 0; i < 17; ++i)
		array.add(element, &array);
	TINYTEST_ASSERT(array.capacity == 32);
	return 1;
}

// the dynamic array should resize to n * 2 if the (n + 1)-th element is added
int dynamic_array_should_double_its_capacity_if_more_than_capacity_elements_is_added(const char* pName) {
	struct dynamic_array_index_pair array;
	initialize(&array);
	srand(time(NULL));
	struct index_pair element;
	int number_of_elements = (int) (((1. * rand()) / RAND_MAX) * 1000000);
	for (int i = 0; i < number_of_elements; ++i)
		array.add(element, &array);
	TINYTEST_ASSERT(array.capacity >= number_of_elements);
	return 1;
}

// the dynamic array should keep its elements after extension
int dynamic_array_should_keep_its_elements_after_extension(const char* pName) {
	struct dynamic_array_index_pair array;
	initialize(&array);
	srand(time(NULL));
	int number_of_elements = (int) (((1. * rand()) / RAND_MAX) * 1000000);
	
	printf("Test 5: Adding %i elements to the array.\n", number_of_elements);
	
	struct index_pair* reference_array = calloc(number_of_elements, sizeof(struct index_pair));
	struct index_pair element;
	int random_integer;
	for (int i = 0; i < number_of_elements; ++i) {
		random_integer = rand();
		element.element_index = random_integer;
		array.add(element, &array);
		reference_array[i] = element;
	}
	int all_elements_are_the_same = 1;
	for (int i = 0; i < array.size; ++i)
		if ((reference_array[i]).element_index != (array.data[i]).element_index) {
			all_elements_are_the_same = 0;
			break;
		}
		
	free(reference_array);
			
	TINYTEST_ASSERT(all_elements_are_the_same);
	return 1;
}

TINYTEST_START_SUITE(DYN_ARRAY_INDEX_PAIR);
	TINYTEST_ADD_TEST(dynamic_array_should_have_an_initial_size_of_16,NULL,NULL);
	TINYTEST_ADD_TEST(dynamic_array_should_support_adding_functionality,NULL,NULL);
	TINYTEST_ADD_TEST(dynamic_array_should_resize_to_32_if_the_17th_element_is_added,NULL,NULL);
	TINYTEST_ADD_TEST(dynamic_array_should_double_its_capacity_if_more_than_capacity_elements_is_added,NULL,NULL);
	TINYTEST_ADD_TEST(dynamic_array_should_keep_its_elements_after_extension,NULL,NULL);
TINYTEST_END_SUITE();

TINYTEST_START_MAIN();
	TINYTEST_RUN_SUITE(DYN_ARRAY_INDEX_PAIR);
TINYTEST_END_MAIN();