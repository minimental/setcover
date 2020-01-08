#include "difference.h"
#include <stdio.h>

void difference(struct set left, int leftIndex, struct set right, int rightIndex, struct set* differenceSet, int differenceSetIndex) {
	
	// TODO: remove; for debugging purposes only
	printf("\n[Call to difference()]\n");
	
	// base case: No more remaining elements in A; nothing to do
	if (leftIndex == left.numberOfElements) return;

	// base case: No more remaining elements in B; copy the remaining elements in A to C
	if (rightIndex == right.numberOfElements) {		
		while(leftIndex != left.numberOfElements) {
			differenceSet->elements[differenceSetIndex++] = left.elements[leftIndex++];
			differenceSet->numberOfElements++;
		}
		return;
	}
	
	// recursion: elements match
	if (left.elements[leftIndex] == right.elements[rightIndex]){
		difference(left, ++leftIndex, right, ++rightIndex, differenceSet, differenceSetIndex);
		return;
	}
	
	// recursion: left < right
	if (left.elements[leftIndex] < right.elements[rightIndex]) {
		differenceSet->elements[differenceSetIndex++] = left.elements[leftIndex++];
		differenceSet->numberOfElements++;
		difference(left, leftIndex, right, rightIndex, differenceSet, differenceSetIndex);
		return;
	}
	
	// recursion: left > right
	if (left.elements[leftIndex] > right.elements[rightIndex]) {
		rightIndex++;
		difference(left, leftIndex, right, rightIndex, differenceSet, differenceSetIndex);
	}
}
