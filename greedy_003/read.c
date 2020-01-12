#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int* copyIntegerArray(int source[], int numberOfElements) {
	int* destination = (int*) calloc(numberOfElements, sizeof(int));
	for (int i = 0; i < numberOfElements; ++i)
		destination[i] = source[i];
	return destination;
}

void read(char* path, struct problem** _specificProblem) {
	FILE* file = fopen(path, "r");
	// read header
	int numberOfSets, numberOfElements;
	fscanf(file, "%i %i", &numberOfElements, &numberOfSets);
	
	// instantiate problem struct
	struct problem* specificProblem = (struct problem*) malloc(sizeof(struct problem));
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
	// test for carriage return (0xD)
	if ((character = fgetc(file)) == 0xD) {
		
		// TODO: remove; for debugging purposes only
		printf("\n[found 0xD after call to `fscanf()']\n");
		
		// assume CR + LF
		fgetc(file);
	} else 
		if (character == 0xA)
			printf("\n[found 0xA after call to `fscanf()']\n");
	
	// read file character-wise
	while ((character = fgetc(file)) != EOF) {
		// ignore 0xD (carriage return)
		if (character == 0xD) continue;
		// terminating character found
		if ((character == ' ') || (character == '\n')) {
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
				
				// TODO: remove; for debugging purposes only
				for (int i = 0; i < numberOfElementsPerSet; ++i)
					printf("actualElements[%i] = %i ", i, actualElements[i]);
				
				specificProblem->sets[lineIndex].elements = actualElements;
				specificProblem->sets[lineIndex].numberOfElements = numberOfElementsPerSet;
				numberOfElementsPerSet = 0;
				isCost = 1;
				// flag required to deal with multiple terminating characters
				terminatingCharacterReached = 0;
				lineIndex++;
			}
			else {
				// flag required to deal with multiple terminating characters
				terminatingCharacterReached = 1;			
			}
			continue;
		}
		// append character to cost/element string
		string[characterIndex++] = (char) character;
		// flag required to deal with multiple terminating characters
		terminatingCharacterReached = 0;
	}
	
	// deal with file not ending with line break
	if (!terminatingCharacterReached) {
		if (isCost) {
			string[characterIndex] = 0;
			specificProblem->sets[lineIndex].cost = atof(&(string[0]));
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
	
	*_specificProblem = specificProblem;
}