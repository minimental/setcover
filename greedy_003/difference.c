#include "difference.h"

void difference(struct set left, struct set right, struct set* differenceSet) {
	
	int leftIndex = 0, rightIndex = 0, differenceSetIndex = 0;
	
	// loop over elements
	int elementsLeft = 1;
	while (elementsLeft) {

		// no more remaining elements in A; nothing to do
		if (leftIndex == left.numberOfElements) {
			elementsLeft = 0;
			continue;
		}

		// no more remaining elements in B; copy the remaining elements in A to C
		if (rightIndex == right.numberOfElements) {		
			while(leftIndex != left.numberOfElements) {
				differenceSet->elements[differenceSetIndex++] = left.elements[leftIndex++];
				differenceSet->numberOfElements++;
			}
			elementsLeft = 0;
			continue;
		}
		
		// elements match
		if (left.elements[leftIndex] == right.elements[rightIndex]){
			++leftIndex;
			++rightIndex;
			continue;
		}
		
		// left < right
		if (left.elements[leftIndex] < right.elements[rightIndex]) {
			differenceSet->elements[differenceSetIndex++] = left.elements[leftIndex++];
			differenceSet->numberOfElements++;
			continue;
		}
		
		// left > right
		if (left.elements[leftIndex] > right.elements[rightIndex])
			rightIndex++;
		
	}	

}
