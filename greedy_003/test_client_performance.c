#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

#define LENGTH_OF_FILE_NAME 260
#define LENGTH_OF_NUMBER_OF_SETS_STRING 8

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

int extractNumber(char* string) {

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

	int numberOfFiles;
	char* fileNames;
	
	numberOfFiles = readFileNamesInDirectory("..\\data", &fileNames);
	sortFileNamesBySetNumbers(fileNames, numberOfFiles);
	
	int fileIndex = 0;
	for (int i = 0; i < numberOfFiles; ++i) {
		printf("\"%s\": %i\n", &(fileNames[fileIndex]), extractNumber(&(fileNames[fileIndex])));
		fileIndex += LENGTH_OF_FILE_NAME;
	}
	
	return 0;
}