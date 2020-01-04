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
	
	// instantiate sets
	struct set sets[numberOfSets];
	specificProblem.sets = sets;
	
	// instantiate elements array
	int elements[numberOfElements];
	
	int character;
	int line = 1;
	int numberOfElementsPerSet = 0;
	int isCost = 1;
	int characterIndex = 0;
	char cost[64];
	char element[32];
	struct set* currentSet;
	struct set** sets;
	while ((character = fgetc(file)) != EOF) {
		// line break found
		if (character == '\n') {
			int actualElements[numberOfElementsPerSet];
			numberOfElementsPerSet = 0;
			line++;
		}
		// blank found
		if (character == ' ')
			// reset character index
			characterIndex = 0;
			if (isCost) {
				cost[characterIndex] = 0;
				currentSet.cost = atof(&(cost[0]));
				isCost = 0;
			}
			else {
				element[characterIndex] = 0;
				elements[numberOfElementsPerSet++] = atoi(&(element[0]));
			}
		// append character
		if (isCost)
			cost[characterIndex++] = (char) character;
		else
			element[characterIndex++] = (char) character;
	}
	
	fclose(file);
	
	return specificProblem;
}