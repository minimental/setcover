#include "difference.h"

void add(struct node* list, void* data) {
	// create a node, assign data, ...
	struct node* node = (struct node*) malloc(sizeof( struct node ));
	node->data = data;
	node->next = 0;
	
	// ...and append it to the list
	list->next = node;
}

void difference(struct node* A, struct node* B, struct node* C) {
	
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
		B = B->next;
		difference(A, B, C);
	}
}
