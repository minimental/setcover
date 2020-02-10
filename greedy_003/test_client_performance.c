#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LENGTH_OF_FILE_NAME 260

/*
	The name of a file is "sc_"<number of sets>"_"<some other integer>
*/
int compareTwoFiles(const void* string1, const void* string2) {
	
	// find the first occurence of '_' in string 1
	printf("First string: %s\n", (char*) string1);
	char* numberOfSetsStartString1 = strchr((char*) string1, '_') + 1;
	// find the last occurence of '_' in string 1
	char* numberOfSetsEndString1 = strchr(numberOfSetsStartString1, '_') - 1;
	
	printf("Number of sets encoded in string 1: ");
	char* index = numberOfSetsStartString1;
	while (index != numberOfSetsEndString1 + 1)
		printf("%c", *index++);
	printf("\n");
	
	return 0;
}

void sortFileNamesBySetNumbers(char* fileNames, int numberOfFiles) {
	qsort((void*) fileNames, (size_t) numberOfFiles, (size_t) LENGTH_OF_FILE_NAME, compareTwoFiles);
}

int main() {
	char fileNames[2 * LENGTH_OF_FILE_NAME];
	
	char* fileName1String = "sc_105_0";
	char* fileName2String = "sc_3023_3";
	
	int fileNameIndex = 0, fileNamesIndex = 0;
	char character;
	while ((character = fileName1String[fileNameIndex]) != 0) {
		fileNames[fileNamesIndex] = fileName1String[fileNameIndex];
		++fileNameIndex;
		++fileNamesIndex;
	}
	// terminate string
	fileNames[fileNamesIndex] = 0;
	
	fileNameIndex = 0; fileNamesIndex = LENGTH_OF_FILE_NAME;
	while ((character = fileName2String[fileNameIndex]) != 0) {
		fileNames[fileNamesIndex] = fileName2String[fileNameIndex];
		++fileNameIndex;
		++fileNamesIndex;
	}
	// terminate string
	fileNames[fileNamesIndex] = 0;
	
	sortFileNamesBySetNumbers(&(fileNames[0]), 2);
	
	return 0;
}