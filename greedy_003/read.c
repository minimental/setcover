#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int* copyIntegerArray(int source[], int numberOfElements) {
	int* destination = (int*) calloc(numberOfElements, sizeof(int));
	for (int i = 0; i < numberOfElements; ++i)
		destination[i] = source[i];
	return destination;
}

void read(char* path, struct problem* specificProblem) {
	FILE* file = fopen(path, "r");
	// read header
	int numberOfSets, numberOfElements;
	fscanf(file, "%i %i", &numberOfElements, &numberOfSets);
	
	specificProblem->numberOfSets = numberOfSets;
	specificProblem->numberOfElements = numberOfElements;
	
	// instantiate sets
	struct set* sets = calloc(numberOfSets, sizeof(struct set));
	specificProblem->sets = sets;
	
	// instantiate elements array
	int elements[numberOfElements];
	
	int character;
	int lineIndex = 0;
	int numberOfElementsPerSet = 0;
	int isCost = 1;
	int characterIndex = 0;
	int terminatingCharacterReached = 0;
	char string[32];
	
	// skipping a line break followed by a call to `fscanf()'
	fgetc(file);
	
	// read file character-wise
	while ((character = fgetc(file)) != EOF) {
		// ignore 0xD (carriage return)
		if (character == 0xD) continue;
		// terminating character found
		if ((character == ' ') || (character == '\n')) {
			
			// handle mulitple white spaces and white space + line break			
			if (!terminatingCharacterReached) {
				if (isCost) {
					string[characterIndex] = 0;
					specificProblem->sets[lineIndex].cost = atof(&(string[0]));
					isCost = 0;
				}
				else {
					string[characterIndex] = 0;
					elements[numberOfElementsPerSet++] = atoi(&(string[0]));
				}				
			}
				
			// reset character index
			characterIndex = 0;
			// line break found
			if (character == '\n') {
				int* actualElements = copyIntegerArray(elements, numberOfElementsPerSet);
				
				specificProblem->sets[lineIndex].elements = actualElements;
				specificProblem->sets[lineIndex].numberOfElements = numberOfElementsPerSet;
				numberOfElementsPerSet = 0;
				isCost = 1;
				lineIndex++;
			}
			
			terminatingCharacterReached = 1;
			continue;
		}
		// append character to cost/element string
		string[characterIndex++] = (char) character;
		terminatingCharacterReached = 0;
	}
	
	// deal with file not ending with line break
	if (lineIndex < numberOfSets) {
		
		if (isCost) {
			string[characterIndex] = 0;
			specificProblem->sets[lineIndex].cost = atof(&(string[0]));
			isCost = 0;
		}
		else {
			string[characterIndex] = 0;
			elements[numberOfElementsPerSet++] = atoi(&(string[0]));
		}
		
		int* actualElements = copyIntegerArray(elements, numberOfElementsPerSet);
		specificProblem->sets[lineIndex].elements = actualElements;
		specificProblem->sets[lineIndex].numberOfElements = numberOfElementsPerSet;
		lineIndex++;
	}
	
	fclose(file);
	
}