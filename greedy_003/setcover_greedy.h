#include <stdlib.h>
#include "read.h"
#include "solution.h"

void difference(struct set left, struct set right, struct set* differenceSet);

void union_of_sets(struct set left, struct set right, struct set* unionSet);

// solves the set cover problem
void setcover_greedy(struct problem* specificProblem, struct solution* specificSolution);