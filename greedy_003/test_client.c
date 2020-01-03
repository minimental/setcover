#include <stdio.h>
#include "setcover_greedy.h"
#include "difference.h"
#include "read.h"

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
	
	printf("Creating a linked list object...");
	struct node coverageSetNode;
	printf("passed.\n");
	
	printf("Creating another linked list object, and attach it to the first one...");
	struct node nextCoverageSetNode;
	coverageSetNode.next = &nextCoverageSetNode;
	nextCoverageSetNode.next = 0;
	printf("passed.\n");
	
	printf("Associating integer values with the linked list elements, and propagating through them...");
	int data[2] = {13, 14};
	coverageSetNode.data = &(data[0]);
	nextCoverageSetNode.data = &(data[1]);
	struct node* currentNode = &coverageSetNode;
	int failed = 0, i = 0;
	while (currentNode) {
		if (*((int*) currentNode->data) != data[i])
			failed = 1;
		++i;
		currentNode = currentNode->next;
	}
	if (failed)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	printf("\n");
	printf("In case you always wanted to know what the size of a void pointer is...\n");
	printf("On your machine it is %d bytes.\n", sizeof( void* ));
	printf("Enjoy.\n");
	
	printf("\n");
	printf("The size of a `node' structure is %d bytes.\n", sizeof(struct node));
	
	printf("\n==================\n\n");
	printf("Checking `difference()'...\n");
	
	printf("The difference of two empty sets should be the empty set...");
	// empty set
	struct node emptySet;
	emptySet.next = 0;
	// difference set
	struct node differenceSet;
	differenceSet.next = 0;
	// call method
	difference(emptySet.next, emptySet.next, &differenceSet);
	// validate result
	if (differenceSet.next)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	
	printf("The difference of an empty set and a non-empty set should be empty...");
	// single-element set
	struct node nonEmptySet;
	struct node firstNode;
	firstNode.next = 0;
	nonEmptySet.next = &firstNode;
	// call method
	difference(emptySet.next, nonEmptySet.next, &differenceSet);
	// validate result
	if (differenceSet.next)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	
	printf("The difference of a non-empty set and an empty set should be non-empty...");
	// call method
	difference(nonEmptySet.next, emptySet.next, &differenceSet);
	// validate result
	if (differenceSet.next)
		printf("passed.\n");
	else
		printf("failed.\n");
	
	
	printf("The difference of {0} and {0} should be the empty set...");
	// left set
	struct node left;
	struct node node0;
	int node0data = 0;
	node0.next = 0;
	node0.data = (void*) &node0data;
	left.next = &node0;
	// right set
	struct node right;
	right.next = &node0;
	// reset difference set
	differenceSet.next = 0;
	// call method
	difference(left.next, right.next, &differenceSet);
	// validate result
	if (differenceSet.next)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	
	printf("The difference of {1} and {0} should be {1}...");
	// left set
	struct node node1;
	int node1data = 1;
	node1.next = 0;
	node1.data = (void*) &node1data;
	left.next = &node1;
	// reset difference set
	differenceSet.next = 0;
	// call method
	difference(left.next, right.next, &differenceSet);	
	// validate result
	if (!differenceSet.next)
		printf("failed.\n");
	else
		if (*((int*) differenceSet.next->data) == 1)
			printf("passed.\n");
		else
			printf("failed.\n");
		
		
	printf("The difference of {12, 227} and {227, 10043} should be {12}...");
	// data nodes
	struct node node12, node227Left, node227Right, node10043;
	int node12data = 12, node227data = 227, node10043data = 10043;
	node12.data = &node12data;
	node227Left.data = &node227data;
	node227Right.data = &node227data;
	node10043.data = &node10043data;
	// left set
	left.next = &node12;
	node12.next = &node227Left;
	node227Left.next = 0;
	// right set
	right.next = &node227Right;
	node227Right.next = &node10043;
	node10043.next = 0;
	// reset difference set
	differenceSet.next = 0;	
	// call method
	difference(left.next, right.next, &differenceSet);
	// validate result
	if (!differenceSet.next)
		printf("failed.\n");
	else
		if (*((int*) differenceSet.next->data) == 12)
			if (differenceSet.next->next)
				printf("failed.\n");
			else
				printf("passed.\n");
		else
			printf("failed.\n");
	
	printf("\n==================\n\n");
	printf("Checking `read()'...\n\n");
	
	printf("read should be able to read number of sets and elements from file...");
	struct problem problem_sc_6_1 = read("C:\\Users\\maxherrman\\coursera\\discrete_optimization\\week3\\setcover\\data\\sc_6_1");
	if ((problem_sc_6_1.numberOfSets == 9) && (problem_sc_6_1.numberOfElements == 6))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	return 0;
}