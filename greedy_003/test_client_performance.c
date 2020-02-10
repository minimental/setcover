#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LENGTH_OF_FILE_NAME 260
#define LENGTH_OF_NUMBER_OF_SETS_STRING 8

int extractNumber(char* string) {

	// find the first occurence of '_' in string
	char* numberOfSetsStartString = strchr((char*) string, '_') + 1;
	// find the last occurence of '_' in string
	char* numberOfSetsEndString = strchr(numberOfSetsStartString, '_') - 1;
	
	// file name does not fit convention
	if (numberOfSetsStartString == 0 || numberOfSetsEndString == 0)
		return -1;
	
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
	
	numberOfSets1 = extractNumber((char*) string1);
	numberOfSets2 = extractNumber((char*) string2);
	
	// entries that does not match the file naming convention should be placed at end
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
	char fileNames[3 * LENGTH_OF_FILE_NAME];
	
	char* fileName1String = "sc_105_0";
	char* fileName2String = "sc_3023_3";
	char* fileName3String = "sc_1600_1";
	
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
	
	fileNameIndex = 0; fileNamesIndex = 2 * LENGTH_OF_FILE_NAME;
	while ((character = fileName3String[fileNameIndex]) != 0) {
		fileNames[fileNamesIndex] = fileName3String[fileNameIndex];
		++fileNameIndex;
		++fileNamesIndex;
	}
	// terminate string
	fileNames[fileNamesIndex] = 0;	
	
	sortFileNamesBySetNumbers(&(fileNames[0]), 3);
	
	printf("main: 1st file name: %s\n", &(fileNames[0]));
	printf("main: 2nd file name: %s\n", &(fileNames[LENGTH_OF_FILE_NAME]));
	printf("main: 3rd file name: %s\n", &(fileNames[2 * LENGTH_OF_FILE_NAME]));
	
	return 0;
}