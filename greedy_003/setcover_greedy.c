// function that checks if the passed array contains at least one -1 element
int isEveryItemCovered(int array[], int numberOfElements) {
	int i = 0;
	int maximumIndex = numberOfElements - 1;
	while(array[i] != -1) {
		if (i == maximumIndex)
			return 1;
		++i;
	}
	return 0;
}

int main(int nargs, char** args) {
	
	// number of items that need to be covered by the sets
	int numberOfItems = 9;
	
	// initialize an array with the same number of element than there are items
	int C[numberOfItems];
	for (int i = 0; i < numberOfItems; ++i)
		C[i] = -1;
	
	return 0;
}