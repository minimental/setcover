#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "problem.h"
#include "solution.h"

void difference(struct set left, struct set right, struct set* differenceSet);

void union_of_sets(struct set left, struct set right, struct set* unionSet);

int* copyIntegerArray(int source[], int numberOfElements);

void readProblemDescription(char* path, struct problem* specificProblem);

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

void setcover_greedy(struct problem* specificProblem, struct solution* specificSolution);

void setcover_bruteforce(struct problem* specificProblem, struct solution* specificSolution);