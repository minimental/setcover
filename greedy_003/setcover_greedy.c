#include "setcover_greedy.h"

// function returns 1 if all elements are 1; 0 otherwise
int isEveryItemCovered(int array[], int numberOfElements) {
	for (int i = 0; i < numberOfElements; ++i)
		if (!array[i]) return 0;
	return 1;
}

int integerCompare(const void* arg1, const void* arg2) {
	if (*((int*) arg1) > *((int*) arg2)) return 1;
	if (*((int*) arg1) < *((int*) arg2)) return -1;
	return 0;
}

// function returns number of elements in set1 which are not in set2
int numberOfDistinctElements(int set1[], int numberOfElementsInSet1, int set2[], int numberOfElementsInSet2) {
	int numberOfDistinctElements = 0;
	// sort both sets
	qsort(&(set1[0]), numberOfElementsInSet1, sizeof(int), integerCompare);
	qsort(&(set2[0]), numberOfElementsInSet2, sizeof(int), integerCompare);
	
	// for every element in set1, test if it is included in set2
	for (int i = 0; i < numberOfElementsInSet1; ++i)
		for (int j = 0; j < numberOfElementsInSet2; ++j) {
			if (set2[j] > set1[i]) {
				++numberOfDistinctElements;
				break;
			}
			if (set1[i] == set2[j])
				break;
			if (j == numberOfElementsInSet2 - 1)
				++numberOfDistinctElements;
		}
	
	return numberOfDistinctElements;
}

int findCoverage() {
	
	// number of items that need to be covered by the sets
	int numberOfItems = 9;
	// number of sets available for coverage
	int numberOfSets = 6;
	// initialize cost for every set
	int cost[6] = {1, 1, 1, 1, 1, 1};
	// instantiate cost-effectiveness for every set
	int costEffectiveness[numberOfSets];
	// instantiate pointers to sets
	int* sets[numberOfSets];
	// initialize sets
	int sizesOfSets[6] = {2, 6, 5, 3, 5, 4};
	int set0[2] = {0, 3};
	sets[0] = &(set0[0]);
	int set1[6] = {0, 1, 2, 5, 6, 8};
	sets[1] = &(set1[0]);
	int set2[5] = {1, 2, 5, 6, 8};
	sets[2] = &(set2[0]);
	int set3[3] = {6, 7, 8};
	sets[3] = &(set3[0]);
	int set4[5] = {0, 3, 4, 5, 6};
	sets[4] = &(set4[0]);
	int set5[4] = {1, 2, 7, 8};
	sets[5] = &(set5[0]);
	
	// instantiate coverage struct
	struct coverage* c;
	c = (struct coverage*) calloc(numberOfItems + 2, sizeof(int));
	
	for (int i = 0; i < numberOfItems; ++i)
		c->items[i] = -1;
	
	// test if coverage equals universe
	if (!isEveryItemCovered(c->items, numberOfItems)) {
		for (int i = 0; i < numberOfSets; ++i)
			costEffectiveness[i] = cost[i]/numberOfDistinctElements(sets[i], sizesOfSets[i], c->items, c->size);
	}
		
	
	return 0;
}

/*
   solves the set cover problem
   greedy algorithm acc. to V.V. Vazirani "Approximation Algorithms" 2003, 2e:
   Algorithm 2.2
*/
void setcover_greedy(char* path) {
	// read problem description from file
	struct problem specificProblem = read(path);
	// overall number of elements and sets
	int M = specificProblem.numberOfSets;
	int N = specificProblem.numberOfElements;
	// bit masks of covered sets and coverage
	int coveredSets[M], coverage[N];
	for (int i = 0; i < M; ++i)
		coveredSets[i] = 0;
	for (int i = 0; i < N; ++i)
		coverage[i] = 0;
	// cost effectiveness per set
	double costEffectiveness, minimumCostEffectiveness = specificProblem.sets[0].cost;
	int minimumCostEffectiveSetIndex = 0;
	// loop until every element is covered
	while (!isEveryItemCovered(coverage, N)) {
		for (int currentSetIndex = 0; currentSetIndex < M; ++currentSetIndex) {
			// skip set if already picked
			if (coveredSets[currentSetIndex]) continue;
			costEffectiveness = evalCostEffectiveness(specificProblem.sets[currentSetIndex].cost, specificProblem.sets[currentSetIndex], coverage);
			if (minimumCostEffectiveness > costEffectiveness) {
				minimumCostEffectiveness = costEffectiveness;
				minimumCostEffectiveSetIndex = currentSetIndex;
			}			
		}
		// flag element indices in coverage that are covered by minimum cost effectiveness set
		struct set minimumCostEffectiveSet = specificProblem.sets[minimumCostEffectiveSetIndex];
		for (int i = 0; i < minimumCostEffectiveSet.numberOfElements; ++i)
			coverage[minimumCostEffectiveSet.elements[i]] = 1;		
	}

}