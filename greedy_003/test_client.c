#include "test_client.h"

// test suite for functions in `setcover_greedy'
int main(int nargs, char** args) {
	
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
	
	printf("\n==================\n\n");
	printf("Checking `difference()'...\n");
	
	printf("The difference of two empty sets should be the empty set...");
	// empty set
	struct set emptySet;
	emptySet.numberOfElements = 0;
	// difference set
	struct set differenceSet;
	differenceSet.numberOfElements = 0;
	// call method
	difference(emptySet, 0, emptySet, 0, &differenceSet, 0);
	// validate result
	if (differenceSet.numberOfElements)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	
	printf("The difference of an empty set and a non-empty set should be empty...");
	// non-empty set
	struct set nonEmptySet;
	int elements[] = {1003, -32, 477};
	nonEmptySet.numberOfElements = 3;
	nonEmptySet.elements = &(elements[0]);
	// call method
	difference(emptySet, 0, nonEmptySet, 0, &differenceSet, 0);
	// validate result
	if (differenceSet.numberOfElements)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	
	printf("The difference of a non-empty set and an empty set should be non-empty...");
	// change capacity of difference set
	differenceSet.numberOfElements = 0;
	int zeroElements[] = {0, 0, 0};
	differenceSet.elements = &(zeroElements[0]);
	// call method
	difference(nonEmptySet, 0, emptySet, 0, &differenceSet, 0);
	// validate result
	int testSucceeded = 1;
	testSucceeded &= differenceSet.elements[0] == 1003;
	testSucceeded &= differenceSet.elements[1] == -32;
	testSucceeded &= differenceSet.elements[2] == 477;
	if (testSucceeded)
		printf("passed.\n");
	else
		printf("failed.\n");
	
	
	printf("The difference of {0} and {0} should be the empty set...");
	// left set
	struct set zeroSet;
	zeroSet.numberOfElements = 1;
	int zero = 0;
	zeroSet.elements = &zero;
	// reset difference set
	int differenceSetElements[4];
	differenceSet.numberOfElements = 0;
	differenceSet.elements = &(differenceSetElements[0]);
	// call method
	difference(zeroSet, 0, zeroSet, 0, &differenceSet, 0);
	// validate result
	if (differenceSet.numberOfElements != 0)
		printf("failed.\n");
	else
		printf("passed.\n");
	
	
	printf("The difference of {1} and {0} should be {1}...");
	// left set
	struct set oneSet;
	oneSet.numberOfElements = 1;
	int one = 1;
	oneSet.elements = &one;
	// reset difference set
	differenceSet.numberOfElements = 0;
	// call method
	difference(oneSet, 0, zeroSet, 0, &differenceSet, 0);
	// validate result
	if ((differenceSet.numberOfElements == 1) && (differenceSet.elements[0] == 1))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	
	printf("The difference of {12, 227} and {227, 10043} should be {12}...");
	// left operand
	struct set left;
	int leftElements[] = {12, 227};
	left.numberOfElements = 2;
	left.elements = &(leftElements[0]);
	// right operand
	struct set right;
	int rightElements[] = {227, 10043};
	right.numberOfElements = 2;
	right.elements = &(rightElements[0]);
	// reset difference set
	differenceSet.numberOfElements = 0;	
	// call method
	difference(left, 0, right, 0, &differenceSet, 0);
	// validate result
	testSucceeded = 1;
	testSucceeded &= differenceSet.numberOfElements == 1;
	testSucceeded &= differenceSet.elements[0] == 12;
	if (testSucceeded)
		printf("passed.\n");
	else
		printf("failed.\n");	

		
	printf("\n==================\n\n");
	printf("Checking `copyIntegerArray()'...\n\n");
    printf("`copyIntegerArray()' should copy the specified number of elements into a newly allocated array...");
	// define test array and destination pointer
	int someIntegerArray[] = {89, 101, -76, 4};
	int* destination;
	// call method
	destination = copyIntegerArray(someIntegerArray, 3);
	// validate result
	testSucceeded = 1;
	testSucceeded &= (destination[0] == 89);
	testSucceeded &= (destination[1] == 101);
	testSucceeded &= (destination[2] == -76);
	if (testSucceeded)
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("\n==================\n\n");
	printf("Checking `read()'...\n\n");
	
	printf("`read()' should read number of sets and elements from file...");
	struct problem problem_sc_6_1 = read("..\\data\\sc_6_1");
	if ((problem_sc_6_1.numberOfSets == 6) && (problem_sc_6_1.numberOfElements == 9))
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("`read()' should allow access to the first set encoded in the file (cost = 1, elements = {0, 3})...");
	problem_sc_6_1 = read("..\\data\\sc_6_1");
	testSucceeded = 1;
	testSucceeded &= (problem_sc_6_1.sets[0].cost == 1.0);
	testSucceeded &= (problem_sc_6_1.sets[0].numberOfElements == 2);
	testSucceeded &= (problem_sc_6_1.sets[0].elements[0] == 0);
	testSucceeded &= (problem_sc_6_1.sets[0].elements[1] == 3);
	if (testSucceeded)
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("`read()' should allow access to all of the sets encoded and header information in the file...");
	struct problem problem_sc_25_0 = read("..\\data\\sc_25_0");
	testSucceeded = 1;
	testSucceeded &= (problem_sc_25_0.numberOfSets == 25);
	testSucceeded &= (problem_sc_25_0.numberOfElements == 12);
	testSucceeded &= (problem_sc_25_0.sets[0].cost == 4.0);
	testSucceeded &= (problem_sc_25_0.sets[0].numberOfElements == 6);
	testSucceeded &= (problem_sc_25_0.sets[0].elements[0] == 0);
	testSucceeded &= (problem_sc_25_0.sets[0].elements[1] == 2);
	testSucceeded &= (problem_sc_25_0.sets[0].elements[2] == 4);
	testSucceeded &= (problem_sc_25_0.sets[0].elements[3] == 6);
	testSucceeded &= (problem_sc_25_0.sets[0].elements[4] == 8);
	testSucceeded &= (problem_sc_25_0.sets[0].elements[5] == 10);
	testSucceeded &= (problem_sc_25_0.sets[1].cost == 4.0);
	testSucceeded &= (problem_sc_25_0.sets[1].numberOfElements == 5);
	testSucceeded &= (problem_sc_25_0.sets[1].elements[0] == 1);
	testSucceeded &= (problem_sc_25_0.sets[1].elements[1] == 3);
	testSucceeded &= (problem_sc_25_0.sets[1].elements[2] == 5);
	testSucceeded &= (problem_sc_25_0.sets[1].elements[3] == 7);
	testSucceeded &= (problem_sc_25_0.sets[1].elements[4] == 9);
	testSucceeded &= (problem_sc_25_0.sets[2].cost == 3.0);
	testSucceeded &= (problem_sc_25_0.sets[2].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[2].elements[0] == 8);
	testSucceeded &= (problem_sc_25_0.sets[2].elements[1] == 9);
	testSucceeded &= (problem_sc_25_0.sets[2].elements[2] == 10);
	testSucceeded &= (problem_sc_25_0.sets[2].elements[3] == 11);
	testSucceeded &= (problem_sc_25_0.sets[3].cost == 3.0);
	testSucceeded &= (problem_sc_25_0.sets[3].numberOfElements == 3);
	testSucceeded &= (problem_sc_25_0.sets[3].elements[0] == 7);
	testSucceeded &= (problem_sc_25_0.sets[3].elements[1] == 8);
	testSucceeded &= (problem_sc_25_0.sets[3].elements[2] == 9);
	testSucceeded &= (problem_sc_25_0.sets[4].cost == 3.0);
	testSucceeded &= (problem_sc_25_0.sets[4].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[4].elements[0] == 5);
	testSucceeded &= (problem_sc_25_0.sets[4].elements[1] == 7);
	testSucceeded &= (problem_sc_25_0.sets[5].cost == 3.0);
	testSucceeded &= (problem_sc_25_0.sets[5].numberOfElements == 1);
	testSucceeded &= (problem_sc_25_0.sets[5].elements[0] == 2);
	testSucceeded &= (problem_sc_25_0.sets[6].cost == 3.0);
	testSucceeded &= (problem_sc_25_0.sets[6].numberOfElements == 5);
	testSucceeded &= (problem_sc_25_0.sets[6].elements[0] == 0);
	testSucceeded &= (problem_sc_25_0.sets[6].elements[1] == 5);
	testSucceeded &= (problem_sc_25_0.sets[6].elements[2] == 6);
	testSucceeded &= (problem_sc_25_0.sets[6].elements[3] == 7);
	testSucceeded &= (problem_sc_25_0.sets[6].elements[4] == 8);
	testSucceeded &= (problem_sc_25_0.sets[7].cost == 2.0);
	testSucceeded &= (problem_sc_25_0.sets[7].numberOfElements == 1);
	testSucceeded &= (problem_sc_25_0.sets[7].elements[0] == 11);	
	testSucceeded &= (problem_sc_25_0.sets[8].cost == 2.0);
	testSucceeded &= (problem_sc_25_0.sets[8].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[8].elements[0] == 0);
	testSucceeded &= (problem_sc_25_0.sets[8].elements[1] == 7);
	testSucceeded &= (problem_sc_25_0.sets[9].cost == 2.0);
	testSucceeded &= (problem_sc_25_0.sets[9].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[9].elements[0] == 2);
	testSucceeded &= (problem_sc_25_0.sets[9].elements[1] == 6);
	testSucceeded &= (problem_sc_25_0.sets[9].elements[2] == 7);
	testSucceeded &= (problem_sc_25_0.sets[9].elements[3] == 8);
	testSucceeded &= (problem_sc_25_0.sets[10].cost == 2.0);
	testSucceeded &= (problem_sc_25_0.sets[10].numberOfElements == 3);
	testSucceeded &= (problem_sc_25_0.sets[10].elements[0] == 4);
	testSucceeded &= (problem_sc_25_0.sets[10].elements[1] == 5);
	testSucceeded &= (problem_sc_25_0.sets[10].elements[2] == 8);
	testSucceeded &= (problem_sc_25_0.sets[11].cost == 2.0);
	testSucceeded &= (problem_sc_25_0.sets[11].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[11].elements[0] == 0);
	testSucceeded &= (problem_sc_25_0.sets[11].elements[1] == 1);
	testSucceeded &= (problem_sc_25_0.sets[12].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[12].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[12].elements[0] == 2);
	testSucceeded &= (problem_sc_25_0.sets[12].elements[1] == 3);
	testSucceeded &= (problem_sc_25_0.sets[13].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[13].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[13].elements[0] == 3);
	testSucceeded &= (problem_sc_25_0.sets[13].elements[1] == 4);
	testSucceeded &= (problem_sc_25_0.sets[14].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[14].numberOfElements == 3);
	testSucceeded &= (problem_sc_25_0.sets[14].elements[0] == 1);
	testSucceeded &= (problem_sc_25_0.sets[14].elements[1] == 2);
	testSucceeded &= (problem_sc_25_0.sets[14].elements[2] == 3);
	testSucceeded &= (problem_sc_25_0.sets[15].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[15].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[15].elements[0] == 6);
	testSucceeded &= (problem_sc_25_0.sets[15].elements[1] == 7);
	testSucceeded &= (problem_sc_25_0.sets[15].elements[2] == 8);
	testSucceeded &= (problem_sc_25_0.sets[15].elements[3] == 9);
	testSucceeded &= (problem_sc_25_0.sets[16].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[16].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[16].elements[0] == 9);
	testSucceeded &= (problem_sc_25_0.sets[16].elements[1] == 10);
	testSucceeded &= (problem_sc_25_0.sets[17].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[17].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[17].elements[0] == 5);
	testSucceeded &= (problem_sc_25_0.sets[17].elements[1] == 6);
	testSucceeded &= (problem_sc_25_0.sets[17].elements[2] == 7);
	testSucceeded &= (problem_sc_25_0.sets[17].elements[3] == 8);
	testSucceeded &= (problem_sc_25_0.sets[18].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[18].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[18].elements[0] == 8);
	testSucceeded &= (problem_sc_25_0.sets[18].elements[1] == 9);
	testSucceeded &= (problem_sc_25_0.sets[19].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[19].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[19].elements[0] == 0);
	testSucceeded &= (problem_sc_25_0.sets[19].elements[1] == 4);
	testSucceeded &= (problem_sc_25_0.sets[19].elements[2] == 8);
	testSucceeded &= (problem_sc_25_0.sets[19].elements[3] == 9);
	testSucceeded &= (problem_sc_25_0.sets[20].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[20].numberOfElements == 3);
	testSucceeded &= (problem_sc_25_0.sets[20].elements[0] == 3);
	testSucceeded &= (problem_sc_25_0.sets[20].elements[1] == 5);
	testSucceeded &= (problem_sc_25_0.sets[20].elements[2] == 7);
	testSucceeded &= (problem_sc_25_0.sets[21].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[21].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[21].elements[0] == 1);
	testSucceeded &= (problem_sc_25_0.sets[21].elements[1] == 5);
	testSucceeded &= (problem_sc_25_0.sets[21].elements[2] == 8);
	testSucceeded &= (problem_sc_25_0.sets[21].elements[3] == 9);
	testSucceeded &= (problem_sc_25_0.sets[22].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[22].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[22].elements[0] == 2);
	testSucceeded &= (problem_sc_25_0.sets[22].elements[1] == 3);
	testSucceeded &= (problem_sc_25_0.sets[22].elements[2] == 6);
	testSucceeded &= (problem_sc_25_0.sets[22].elements[3] == 7);
	testSucceeded &= (problem_sc_25_0.sets[23].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[23].numberOfElements == 2);
	testSucceeded &= (problem_sc_25_0.sets[23].elements[0] == 3);
	testSucceeded &= (problem_sc_25_0.sets[23].elements[1] == 6);
	testSucceeded &= (problem_sc_25_0.sets[24].cost == 1.0);
	testSucceeded &= (problem_sc_25_0.sets[24].numberOfElements == 4);
	testSucceeded &= (problem_sc_25_0.sets[24].elements[0] == 4);
	testSucceeded &= (problem_sc_25_0.sets[24].elements[1] == 8);
	testSucceeded &= (problem_sc_25_0.sets[24].elements[2] == 9);
	testSucceeded &= (problem_sc_25_0.sets[24].elements[3] == 10);
	if (testSucceeded)
		printf("passed.\n");
	else
		printf("failed.\n");
	
	printf("\n==================\n\n");
	printf("Checking `union_of_sets()'...\n\n");
	
	printf("The union of {12, 227} and {227, 10043} should be {12, 227, 10043}...");
	// create union set
	struct set unionSet;
	unionSet.numberOfElements = 0;
	int threeElements[3];
	unionSet.elements = &(threeElements[0]);
	// call method
	union_of_sets(left, 0, right, 0, &unionSet, 0);
	// validate result
	testSucceeded = 1;
	testSucceeded &= unionSet.numberOfElements == 3;
	printf("\n[Expected number of elements in union set: 3. Actual number of elements in union set: %i.]\n", unionSet.numberOfElements);
	testSucceeded &= unionSet.elements[0] == 12;
	testSucceeded &= unionSet.elements[1] == 227;
	testSucceeded &= unionSet.elements[2] == 10043;
	if (testSucceeded)
		printf("passed.\n");
	else
		printf("failed.\n");
	
	
	printf("\n==================\n\n");
	printf("Checking `setcover_greedy()'...\n\n");
	
	return 0;
}