#include "union.h"

void union_of_sets(struct set left, struct set right, struct set* unionSet) {
	
	int leftIndex = 0, rightIndex = 0, unionSetIndex = 0;
	
	// loop over elements
	while (1) {
		
		// no more remaining elements in left operand; copy the remaining elements in right operand to union set
		if (leftIndex == left.numberOfElements) {		
			while(rightIndex != right.numberOfElements) {
				unionSet->elements[unionSetIndex++] = right.elements[rightIndex++];
				unionSet->numberOfElements++;
			}
			break;
		}

		// no more remaining elements in right operand; copy the remaining elements in left operand to union set
		if (rightIndex == right.numberOfElements) {		
			while(leftIndex != left.numberOfElements) {
				unionSet->elements[unionSetIndex++] = left.elements[leftIndex++];
				unionSet->numberOfElements++;
			}
			break;
		}
		
		// elements match
		if (left.elements[leftIndex] == right.elements[rightIndex]) {
			unionSet->elements[unionSetIndex++] = left.elements[leftIndex++];
			unionSet->numberOfElements++;
			rightIndex++;
			continue;
		}
		
		// left < right
		if (left.elements[leftIndex] < right.elements[rightIndex]) {
			unionSet->elements[unionSetIndex++] = left.elements[leftIndex++];
			unionSet->numberOfElements++;
			continue;
		}
		
		// left > right
		if (left.elements[leftIndex] > right.elements[rightIndex]) {
			unionSet->elements[unionSetIndex++] = right.elements[rightIndex++];
			unionSet->numberOfElements++;
		}		
		
	}		
	
}