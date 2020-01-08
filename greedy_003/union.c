#include "union.h"

void union_of_sets(struct set left, int leftIndex, struct set right, int rightIndex, struct set* unionSet, int unionSetIndex) {
	
	// base case: No more remaining elements in left operand; copy the remaining elements in right operand to union set
	if (leftIndex == left.numberOfElements) {		
		while(rightIndex != right.numberOfElements) {
			unionSet->elements[unionSetIndex++] = right.elements[rightIndex++];
			unionSet->numberOfElements++;
		}
		return;
	}

	// base case: No more remaining elements in right operand; copy the remaining elements in left operand to union set
	if (rightIndex == right.numberOfElements) {		
		while(leftIndex != left.numberOfElements) {
			unionSet->elements[unionSetIndex++] = left.elements[leftIndex++];
			unionSet->numberOfElements++;
		}
		return;
	}
	
	// recursion: elements match
	if (left.elements[leftIndex] == right.elements[rightIndex]) {
		unionSet->elements[unionSetIndex++] = left.elements[leftIndex++];
		unionSet->numberOfElements++;
		rightIndex++;
		union_of_sets(left, leftIndex, right, rightIndex, unionSet, unionSetIndex);
		return;
	}
	
	// recursion: left < right
	if (left.elements[leftIndex] < right.elements[rightIndex]) {
		unionSet->elements[unionSetIndex++] = left.elements[leftIndex++];
		unionSet->numberOfElements++;
		union_of_sets(left, leftIndex, right, rightIndex, unionSet, unionSetIndex);
		return;
	}
	
	// recursion: left > right
	if (left.elements[leftIndex] > right.elements[rightIndex]) {
		unionSet->elements[unionSetIndex++] = right.elements[rightIndex++];
		unionSet->numberOfElements++;
		union_of_sets(left, leftIndex, right, rightIndex, unionSet, unionSetIndex);
	}
}
