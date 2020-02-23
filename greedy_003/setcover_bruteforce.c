#include "setcover_bruteforce.h"

void setcover_bruteforce(struct problem* specificProblem, struct solution* specificSolution) {
		
	// extract number of sets and elements
	int M = specificProblem->numberOfSets;
	int N = specificProblem->numberOfElements;
	
	// create coverage and associated data
	struct set coverage, coverage_update;
	int coverageElements[N], coverageUpdateElements[N];
	coverage.numberOfElements = 0;
	coverage_update.numberOfElements = 0;
	coverage.elements = &(coverageElements[0]);
	coverage_update.elements = &(coverageUpdateElements[0]);
	
	double maximumCost = 0.0;
	// evaluate maximum cost
	for (int i = 0; i < M; ++i)
		maximumCost = maximumCost += specificProblem->sets[i].cost;
	
	// loop: determine if permutation of sets covers the problem set, and if so, evaluate cost
	int numberOfPossiblePermutations = (1 << M);
	int* temp;
	
	int testBit = 1, testIndex = 0, minimumCostPermutation = 0, numberOfSetsPicked = 0, minimumCostNumberOfSetsPicked = 0;
	double cost = 0.0, minimumCost = maximumCost;
	for (int permutation = 0; permutation < numberOfPossiblePermutations; ++permutation) {
		
		for (int setIndex = 0; setIndex < M; ++setIndex) {		
			if ((permutation & testBit) > 0) {
				// add picked set to coverage
				union_of_sets(specificProblem->sets[testIndex], coverage, &coverage_update);
				// swap coverage and coverage update elements
				coverage.numberOfElements = coverage_update.numberOfElements;
				temp = coverage.elements;
				coverage.elements = coverage_update.elements;
				coverage_update.elements = temp;
				coverage_update.numberOfElements = 0;
				// update
				cost += specificProblem->sets[testIndex].cost;
				numberOfSetsPicked += 1;			
			}
			// update test index and bit
			testIndex++;
			testBit = testBit << 1;
		}
		
		// if permutation covers all elements of the problem set, test if it is a solution candidate
		if (coverage.numberOfElements == N) {
			if (minimumCost > cost) {
				minimumCost = cost;
				minimumCostPermutation = permutation;
				minimumCostNumberOfSetsPicked = numberOfSetsPicked;
			}			
		}
			
		// reset iteration values
		testIndex = 0;
		testBit = 1;
		cost = 0.0;
		numberOfSetsPicked = 0;
		coverage.numberOfElements = 0;
	}
	
	// fill solution struct
	specificSolution->numberOfSets = M;
	
	int* minimumCostSetsPicked = calloc(M, sizeof(int));
	testBit = 1;
	for (int i = 0; i < M; ++i) {
		if ((minimumCostPermutation & testBit) > 0)
			minimumCostSetsPicked[i] = 1;
		else
			minimumCostSetsPicked[i] = 0;
		// update test bit
		testBit = testBit << 1;
	}
		
	specificSolution->numberOfSetsPicked = minimumCostNumberOfSetsPicked;
	specificSolution->pickedSets = minimumCostSetsPicked;
	specificSolution->cost = minimumCost;
	
}