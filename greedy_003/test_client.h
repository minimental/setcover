#include <stdio.h>
#include <stdlib.h>
#include "problem.h"
#include "node.h"

void difference(struct set left, int leftIndex, struct set right, int rightIndex, struct set* differenceSet, int differenceSetIndex);

int* copyIntegerArray(int source[], int numberOfElements);

struct problem read(char* path);

struct coverage {
	int size;
	int numberOfSetItems;
	int items[];
};

// function that checks if the passed array contains at least one -1 element
int isEveryItemCovered(int array[], int numberOfElements);

// function returns number of elements in set1 which are not in set2
int numberOfDistinctElements(int set1[], int numberOfElementsInSet1, int set2[], int numberOfElementsinSet2);

int findCoverage();