#include "difference.h"

void add(struct linkedList* list, void* data) {
	// create a node, assign data, ...
	struct linkedList* node = (struct linkedList*) malloc(sizeof( struct linkedList ));
	node->data = data;
	node->next = 0;
	
	// ...and append it to the list
	list->next = node;
}

void difference(struct linkedList* A, struct linkedList* B, struct linkedList* C) {
	
	// base case: No more remaining elements in A; nothing to do
	if (!A) return;

	// base case: No more remaining elements in B; copy the remaining elements in A to C
	if (!B) {
		while(A) {
			add(C, A->data);
			C = C->next;
			A = A->next;
		}
		return;
	}
	
	if (*((int*) A->data) == *((int*) B->data)) return;
	if (*((int*) A->data) < *((int*) B->data)) {
		add(C, A->data);
		C = C->next;
		A = A->next;
		difference(A, B, C);
	}
	if (*((int*) A->data) > *((int*) B->data)) {
		add(C, B->data);
		C = C->next;
		B = B->next;
		difference(A, B, C);
	}
}
