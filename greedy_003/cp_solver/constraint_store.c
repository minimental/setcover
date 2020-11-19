/*
 * The function `constraint_store' returns 1 if the set cover constraint is satisfied, 0 otherwise.
 *
 * This is a C implementation of the MiniZinc statement
 *
 *    constraint forall (i in 1..N) (sum (s in 1..M where (i-1) in problem_sets[s]) (choose_set[s]) >= 1);
 *
 * provided by Carleton Coffrin in the directory `minizinc_001' in the Git repository of the Coursera course `Discrete Optimization':
 *  
 */
 
#include "search_engine.h"

int constraint_store(const struct problem *specific_problem, const struct solution *specific_solution) {
	
	int M, N, set_index;
	int element_included;
	
	N = specific_problem->number_of_elements;
	
	// every element needs to be included in at least one set
	for (int e = 0; e < N; ++e) {
		
		// number of sets that include element e
		M = specific_problem->element_value_table[e].size;
		element_included = 0;
		
		for (int s = 0; s < M; ++s) {
			
			// get set that includes element e
			set_index = specific_problem->element_value_table[e].data[s].set_index;
			
			// at least one set includes e; exit loop
			if (specific_solution->mask_of_picked_sets[set_index]) {
				element_included = 1;
				break;
			}
				
		}
		
		// element e is not included in any set
		if (!element_included)
			return 0;
		
	}
	
	return 1;
	
}