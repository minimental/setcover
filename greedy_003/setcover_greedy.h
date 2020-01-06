#include <stdlib.h>
#include "read.h"
#include "solution.h"

void difference(struct set left, int leftIndex, struct set right, int rightIndex, struct set* differenceSet, int differenceSetIndex);

void union_of_sets(struct set left, int leftIndex, struct set right, int rightIndex, struct set* unionSet, int unionSetIndex);

// solves the set cover problem
void setcover_greedy(char* path, struct solution* specificSolution);