#include <time.h>
#include <stdio.h>
#include "setcover_greedy.h"

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

double evalCostEffectiveness(double cost, struct set S, struct set C) {

	// compute difference of S and C
	struct set differenceSet;
	int zeroElements[S.numberOfElements];
	differenceSet.numberOfElements = 0;
	differenceSet.elements = &(zeroElements[0]);
	
	difference(S, 0, C, 0, &differenceSet, 0);
	
	// compute cost effectiveness of set
	return cost / differenceSet.numberOfElements;
}

/*
   solves the set cover problem
   greedy algorithm acc. to V.V. Vazirani "Approximation Algorithms" 2003, 2e:
   Algorithm 2.2
*/
void setcover_greedy(struct problem* specificProblem, struct solution* specificSolution) {
	
	// overall number of elements and sets
	int M = specificProblem->numberOfSets;
	int N = specificProblem->numberOfElements;
	
	// create coverage
	struct set coverage, coverage_update;
	
	coverage.numberOfElements = 0;
	coverage_update.numberOfElements = 0;
	int zeroElements[N], zeroElements_update[N];
	coverage.elements = &(zeroElements[0]);
	coverage_update.elements = &(zeroElements_update[0]);
	
	// bit masks of picked sets; maximum set cost
	int pickedSets[M];
	double maximumCost = -1;
	for (int i = 0; i < M; ++i) {
		pickedSets[i] = 0;
		if (specificProblem->sets[i].cost > maximumCost)
			maximumCost = specificProblem->sets[i].cost;
	}
			
	// cost effectiveness per set
	double costEffectiveness, minimumCostEffectiveness = maximumCost;
	int minimumCostEffectiveSetIndex = 0;
	
	// loop until every element is covered
	while (coverage.numberOfElements != N) {
		
		for (int currentSetIndex = 0; currentSetIndex < M; ++currentSetIndex) {
			// skip set if already picked
			if (pickedSets[currentSetIndex]) continue;
			
			costEffectiveness = evalCostEffectiveness(specificProblem->sets[currentSetIndex].cost, specificProblem->sets[currentSetIndex], coverage);
			
			// find minimum cost effective set
			if (minimumCostEffectiveness >= costEffectiveness) {
				minimumCostEffectiveness = costEffectiveness;
				minimumCostEffectiveSetIndex = currentSetIndex;
			}

		}
		
		// reset minimum cost effectiveness
		minimumCostEffectiveness = maximumCost;
		
		// mark set as picked
		pickedSets[minimumCostEffectiveSetIndex] = 1;
		
		// compute union of coverage and minimum cost effective set
		union_of_sets(coverage, 0, specificProblem->sets[minimumCostEffectiveSetIndex], 0, &coverage_update, 0);
		
		coverage.numberOfElements = coverage_update.numberOfElements;
		// swap elements
		int* temp = coverage.elements;
		coverage.elements = coverage_update.elements;
		coverage_update.elements = temp;
		coverage_update.numberOfElements = 0;
	}
	// compute overall cost
	double cost = 0;
	for (int i = 0; i < M; ++i)
		if (pickedSets[i])
			cost += specificProblem->sets[0].cost;
		
	// fill solution struct
	specificSolution->numberOfSets = M;
	specificSolution->pickedSets = (int*) calloc(M, sizeof(int));
	for (int i = 0; i < M; ++i) {
		specificSolution->pickedSets[i] = pickedSets[i];
		if (pickedSets[i])
			specificSolution->numberOfSetsPicked++;
	}
		
	specificSolution->cost = cost;
}