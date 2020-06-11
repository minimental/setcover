#include <stdio.h>
#include <stdlib.h>

#include "types.h"

int* copyIntegerArray(int source[], int number_of_elements) {
	int* destination = (int*) calloc(number_of_elements, sizeof(int));
	for (int i = 0; i < number_of_elements; ++i)
		destination[i] = source[i];
	return destination;
}

void read_problem_description_from_file(char* path, struct problem* specific_problem) {
	FILE* file = fopen(path, "r");
	// read header
	int number_of_sets, number_of_elements;
	fscanf(file, "%i %i", &number_of_elements, &number_of_sets);
	
	specific_problem->number_of_sets = number_of_sets;
	specific_problem->number_of_elements = number_of_elements;
	
	// instantiate elements array
	int elements[number_of_elements];
	
	int character;
	int lineIndex = 0;
	int number_of_elementsPerSet = 0;
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
					// specific_problem->sets[lineIndex].cost = atof(&(string[0]));
					isCost = 0;
				}
				else {
					string[characterIndex] = 0;
					elements[number_of_elementsPerSet++] = atoi(&(string[0]));
				}				
			}
				
			// reset character index
			characterIndex = 0;
			// line break found
			if (character == '\n') {
				int* actualElements = copyIntegerArray(elements, number_of_elementsPerSet);
				
				// specific_problem->sets[lineIndex].elements = actualElements;
				// specific_problem->sets[lineIndex].number_of_elements = number_of_elementsPerSet;
				number_of_elementsPerSet = 0;
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
	if (lineIndex < number_of_sets) {
		
		if (isCost) {
			string[characterIndex] = 0;
			// specific_problem->sets[lineIndex].cost = atof(&(string[0]));
			isCost = 0;
		}
		else {
			string[characterIndex] = 0;
			elements[number_of_elementsPerSet++] = atoi(&(string[0]));
		}
		
		int* actualElements = copyIntegerArray(elements, number_of_elementsPerSet);
		// specific_problem->sets[lineIndex].elements = actualElements;
		// specific_problem->sets[lineIndex].number_of_elements = number_of_elementsPerSet;
		lineIndex++;
	}
	
	fclose(file);
	
}