#include <stdio.h>
#include "..\read.h"
#include "..\solution.h"

void setcover_greedy(struct problem* specificProblem, struct solution* specificSolution);


int main() {
	struct problem problem_sc_405_0;
	readProblemDescription("..\\..\\data\\sc_405_0", &problem_sc_405_0);

	struct solution solution_sc_405_0;
	
	setcover_greedy(&problem_sc_405_0, &solution_sc_405_0);
	
	printf("Done.\n");
	
	return 0;
}