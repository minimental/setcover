#include <stdio.h>

#include "read.h"
#include "solution.h"
void setcover_greedy(struct problem* specificProblem, struct solution* specificSolution);

int main (int nargs, char** args) {
	if (nargs != 2) {
		printf("%s: exactly one argument needed.\n", args[0]);
		return -1;
	}
	
	char* path = args[1];
	struct problem specificProblem;
	struct solution specificSolution;
	
	readProblemDescription(path, &specificProblem);
	setcover_greedy(&specificProblem, &specificSolution);
	
	printf("%i/%i picked.\n", specificSolution.numberOfSetsPicked, specificSolution.numberOfSets);
	
	return 0;
}