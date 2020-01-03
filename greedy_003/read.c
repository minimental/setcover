#include <stdio.h>
#include "read.h"

struct problem read(char* path) {
	FILE* file = fopen(path, "r");
	// read header
	int numberOfSets, numberOfElements;
	fscanf(file, "%i %i", &numberOfSets, &numberOfElements);
	
	// instantiate problem struct
	struct problem specificProblem;
	specificProblem.numberOfSets = numberOfSets;
	specificProblem.numberOfElements = numberOfElements;
	
	int character;
	int line = 1;
	while ((character = fgetc(file)) != EOF) {
		// TODO: extract problem description
	}
	
	fclose(file);
	
	return specificProblem;
}