#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "..\greedy_with_LUT\types.h"
#include "..\greedy_with_LUT\functions.h"

#define LENGTH_OF_FILE_NAME 260
#define LENGTH_OF_NUMBER_OF_SETS_STRING 8
#define MAXIMUM_NUMBER_OF_PROBLEM_SETS 1100000

// reads all files contained in the given directory
int readFileNamesInDirectory(char* directoryString, char** fileNames) {
	
	DIR* directory;
	struct dirent* directoryEntry;
	directory = opendir(directoryString);
	
	// first run: number of files included
	int numberOfFiles = 0;
	while ((directoryEntry = readdir(directory)) != NULL) ++numberOfFiles;
	
	// second run: persist file names
	rewinddir(directory);
	*fileNames = calloc(numberOfFiles, LENGTH_OF_FILE_NAME);
	int fileNamesIndexOffset = 0, characterIndex = 0;
	while ((directoryEntry = readdir(directory)) != NULL) {
		while(directoryEntry->d_name[characterIndex]) {
			(*fileNames)[fileNamesIndexOffset + characterIndex] = directoryEntry->d_name[characterIndex];
			++characterIndex;
		}
		// terminate file name string
		(*fileNames)[fileNamesIndexOffset + characterIndex] = 0;
		characterIndex = 0;
		fileNamesIndexOffset += LENGTH_OF_FILE_NAME;
	}
	
	return numberOfFiles;
	
}

int extractNumberOfSets(char* string) {

	// find the first occurence of '_' in string
	char* numberOfSetsStartString = strchr((char*) string, '_');
	// file name does not fit convention
	if (!numberOfSetsStartString)
		return -1;
	numberOfSetsStartString += 1;
	
	// find the last occurence of '_' in string
	char* numberOfSetsEndString = strchr(numberOfSetsStartString, '_');
	// file name does not fit convention
	if (!numberOfSetsEndString)
		return -1;
	numberOfSetsEndString -= 1;
	
	// extract number-of-sets string and convert it into an integer
	char numberOfSetsString[LENGTH_OF_NUMBER_OF_SETS_STRING];
	char* numberIndex = numberOfSetsStartString;
	int i = 0;
	while (!(numberIndex > numberOfSetsEndString)) {
		numberOfSetsString[i] = *numberIndex;
		++numberIndex;
		++i;
	}
	// terminate number string
	numberOfSetsString[i] = 0;

	return atoi(numberOfSetsString);

}

// compare two file names by extracting number of sets
int compareTwoFiles(const void* string1, const void* string2) {
	
	// determine number of sets contained in the file name
	int numberOfSets1, numberOfSets2;
	
	numberOfSets1 = extractNumberOfSets((char*) string1);
	numberOfSets2 = extractNumberOfSets((char*) string2);
	
	// entries that do not match the file naming convention should be placed at end
	if (numberOfSets1 < 0)
		return 1;
	if (numberOfSets2 < 0)
		return -1;
	
	if (numberOfSets1 > numberOfSets2)
		return 1;
	
	if (numberOfSets1 < numberOfSets2)
		return -1;
	
	return 0;
}

void sortFileNamesBySetNumbers(char* fileNames, int numberOfFiles) {
	qsort((void*) fileNames, (size_t) numberOfFiles, (size_t) LENGTH_OF_FILE_NAME, compareTwoFiles);
}

int main() {

	int numberOfFiles, numberOfSets;
	char* fileNames;
	struct timespec solverStart, solverEnd;
	
	numberOfFiles = readFileNamesInDirectory("..\\..\\data", &fileNames);
	sortFileNamesBySetNumbers(fileNames, numberOfFiles);
	
	printf("Number of sets | Elapsed time [sec] | Constant |\n");
	printf("---------------+--------------------------------\n");
	
	int fileIndex = 0;
	for (int i = 0; i < numberOfFiles; ++i) {
		
		// if problem size exceeds a given limit, stop
		if ((numberOfSets = extractNumberOfSets(&(fileNames[fileIndex]))) >= MAXIMUM_NUMBER_OF_PROBLEM_SETS)
			break;
		
		// set path
		char path[LENGTH_OF_FILE_NAME + 8];
		sprintf(path, "..\\..\\data\\%s", &(fileNames[fileIndex]));
		
		// TODO: remove; for debugging purposes only
		if (!strcmp(&(path[0]), "..\\..\\data\\sc_8661_1")) {
			printf("Ignoring `sc_8661_1'...\n");
			fileIndex += LENGTH_OF_FILE_NAME;
			continue;
		}
		
		// create problem struct to access number of elements
		struct problem specific_problem;
		read_problem_description_from_file(path, &specific_problem);
		
		// create pointer for output string
		char* output;
		
		// call solver with timing
		// timing snippet taken from 21.4.1 "CPU Time Inquiry" of glibc documentation
		clock_t start, end;
		double cpu_time_used, time_per_computation_unit;

		start = clock();
			greedy_with_LUT(path, &output);
		end = clock();
		
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		
		// time per computation unit
		int M = numberOfSets;
		int N = specific_problem.number_of_elements;
		time_per_computation_unit = cpu_time_used / ((1. * M) * N) ;
		
		// print statistics
		printf("%14i | %19e | %19e \n", numberOfSets, cpu_time_used, time_per_computation_unit);
		
		// free resources
		free(specific_problem.element_value_table);
		free(specific_problem.sets);
		
		// go to next file name
		fileIndex += LENGTH_OF_FILE_NAME;
		
	}
	
	return 0;
}