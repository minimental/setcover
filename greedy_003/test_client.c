#include <stdio.h>
#include "setcover_greedy.h"
#include "difference.h"

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
	struct node differenceList;
	differenceList.next = 0;
	difference((struct node*) 0, (struct node*) 0, &differenceList);
	if (differenceList.next)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	printf("The difference of an empty set and a non-empty set should be empty...");
	struct node nodeThatRepresentsAOneElementSet;
	struct node nodeThatRepresentsAnElementOfASet;
	nodeThatRepresentsAOneElementSet.next = &nodeThatRepresentsAnElementOfASet;
	nodeThatRepresentsAnElementOfASet.next = 0;
	difference((struct node*) 0, &nodeThatRepresentsAOneElementSet, &differenceList);
	if (differenceList.next)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	printf("The difference of a single-element set and the empty set should be the set containing the element...");
	/* left set: single element */
	struct node singleElementSet;
	singleElementSet.next = 0;
	nodeThatRepresentsAnElementOfASet.data = (void*) &(data[1]);
	/* difference set */
	struct node differenceSet;
	differenceSet.next = 0;
	/* call difference */
	difference(&singleElementSet, &emptySet, &differenceSet);
	/* check if the difference set has any element at all */
	if (!differenceSet.next) {
		printf("failed.\nThe difference set is the empty set.\n");
		return -1;
	}
	else 
		printf("The difference set contains at least one element.\n");
	/* validate result */
	if (*((int*) differenceSet.next->data) == data[1])
		printf("passed.\n");
	else
		printf("failed.\n");
	
	return 0;
}