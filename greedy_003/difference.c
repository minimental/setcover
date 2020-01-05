#include "difference.h"
#include <stdio.h>

void difference(struct set left, int leftIndex, struct set right, int rightIndex, struct set differenceSet, int differenceSetIndex) {
	
	// base case: No more remaining elements in A; nothing to do
	if (leftIndex == left.numberOfElements) return;

	// base case: No more remaining elements in B; copy the remaining elements in A to C
	if (rightIndex == right.numberOfElements) {		
		while(leftIndex != left.numberOfElements) {
			differenceSet.elements[differenceSetIndex] = left.elements[leftIndex];
			
			// TODO: Remove; for debugging purposes only
			printf("\n[differenceSet.elements[%i] <- %i]\n", differenceSetIndex, left.elements[leftIndex]);			
			
			differenceSetIndex++;
			leftIndex++;
			differenceSet.numberOfElements = differenceSetIndex;
			
			// TODO: Remove; for debugging purposes only
			printf("\n[Set number of elements of difference set to %i.]\n", differenceSet.numberOfElements);
			
		}
		return;
	}
	
	// base case: elements match
	if (left.elements[leftIndex] == right.elements[rightIndex]) return;
	
	// recursion: left < right
	if (left.elements[leftIndex] < right.elements[rightIndex]) {
		differenceSet.elements[differenceSetIndex] = left.elements[leftIndex];
		differenceSetIndex++;
		leftIndex++;
		differenceSet.numberOfElements = differenceSetIndex;
		difference(left, leftIndex, right, rightIndex, differenceSet, differenceSetIndex);
	}
	
	// recursion: left > right
	if (left.elements[leftIndex] > right.elements[rightIndex]) {
		rightIndex++;
		difference(left, leftIndex, right, rightIndex, differenceSet, differenceSetIndex);
	}
}
