#include "setcover_greedy.h"
#include <stdio.h>

// test suite for functions in `setcover_greedy'
int main(int nargs, char** args) {
	
	printf("Checking `isEveryItemCovered()'...\n");
	printf("Calling `isEveryItemCovered(array, 0)' with an empty array.\n");
	printf("Expecting the return value to be 1...");
	int array_0[0];
	if (isEveryItemCovered(array_0, 0))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("Calling `isEveryItemCovered(array, 1)' with [1].\n");
	printf("Expecting the return value to be 1...");
	int array_1_passed[1] = {1};
	if (isEveryItemCovered(array_1_passed, 1))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("Calling `isEveryItemCovered(array, 1)' with [-1].\n");
	printf("Expecting the return value to be 0...");
	int array_1_failed[1] = {-1};
	if (isEveryItemCovered(array_1_failed, 1))
		printf("failed.\n");
	else
		printf("passed.\n");
	
	printf("Calling `isEveryItemCovered(array, 2)' with [1, -1].\n");
	printf("Expecting the return value to be 0...");
	int array_pn[2] = {1, -1};
	if (isEveryItemCovered(array_pn, 2))
		printf(".\n");
	else
		printf("passed.\n");
	
	printf("Calling `isEveryItemCovered(array, 2)' with [-1, 2].\n");
	printf("Expecting the return value to be 0...");
	int array_np[2] = {-1, 2};
	if (isEveryItemCovered(array_np, 2))
		printf(".\n");
	else
		printf("passed.\n");
	
	printf("Calling `isEveryItemCovered(array, 2)' with [-1, -1].\n");
	printf("Expecting the return value to be 0...");
	int array_nn[2] = {-1, -1};
	if (isEveryItemCovered(array_nn, 2))
		printf(".\n");
	else
		printf("passed.\n");
	
	printf("Calling `isEveryItemCovered(array, 2)' with [1, 2].\n");
	printf("Expecting the return value to be 1...");
	int array_pp[2] = {1, 2};
	if (isEveryItemCovered(array_pp, 2))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("\n==================\n\n");
	printf("Checking `numberOfDistinctElements()'...\n");
	printf("Calling `numberOfDistinctElements' with two single-element sets that are equal.\n");
	printf("Expecting the return value to be 0...");
	int set1_1_eq[1] = {2};
	int set2_1_eq[1] = {2};
	if (!numberOfDistinctElements(set1_1_eq, 1, set2_1_eq, 1))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("Calling `numberOfDistinctElements' with two single-element sets that are unequal.\n");
	printf("Expecting the return value to be 1...");
	int set1_1_neq[1] = {2};
	int set2_1_neq[1] = {0};
	if (!numberOfDistinctElements(set1_1_neq, 1, set2_1_neq, 1))
		printf("failed.\n");
	else
		printf("passed.\n");	
	
	printf("Calling `numberOfDistinctElements' with two two-element sets that are equal.\n");
	printf("Expecting the return value to be 0...");
	int set1_2_eq[2] = {2, 3};
	int set2_2_eq[2] = {3, 2};
	if (!numberOfDistinctElements(set1_2_eq, 2, set2_2_eq, 2))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("Calling `numberOfDistinctElements' with two two-element sets that have one element in common.\n");
	printf("Expecting the return value to be 1...");
	int set1_2_1oo2[2] = {2, 3};
	int set2_2_1oo2[2] = {3, 4};
	if (numberOfDistinctElements(set1_2_1oo2, 2, set2_2_1oo2, 2) != 1)
		printf("failed.\n");
	else
		printf("passed.\n");	
	
	return 0;
}