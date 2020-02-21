#include <stdio.h>
#include "..\read.h"
void difference(struct set left, struct set right, struct set* differenceSet);


int main() {
	struct problem problem_sc_405_0;
	readProblemDescription("..\\..\\data\\sc_405_0", &problem_sc_405_0);
	struct set differenceSet;
	int differenceSetElements[problem_sc_405_0.numberOfElements];
	differenceSet.elements = &(differenceSetElements[0]);
	differenceSet.numberOfElements = 0;
	
	struct set leftSet, rightSet;
	int leftSetElements[problem_sc_405_0.numberOfElements];
	leftSet.elements = &(leftSetElements[0]);
	leftSet.numberOfElements = problem_sc_405_0.numberOfElements;
	
	int rightSetElements[problem_sc_405_0.numberOfElements];
	rightSet.elements = &(rightSetElements[0]);
	rightSet.numberOfElements = problem_sc_405_0.numberOfElements;	
	
	difference(leftSet, rightSet, &differenceSet);
	
	printf("Done.\n");
	
	return 0;
}