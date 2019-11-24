#include "difference.h"

void add(struct linkedList* list, void* data) {
	struct linkedList* node = (struct linkedList*) malloc(sizeof( struct linkedList ));
	node->data = data;
	
	while(list->next)
		list = list->next;
	
	list->next = node;
}

void difference(struct linkedList* A, struct linkedList* B, struct linkedList* C) {
	if (!A) {
		while(B) {
			add(C, B->data);
			B = B->next;
		}
		return;
	}

	if (!B) {
		while(A) {
			add(C, A->data);
			A = A->next;
		}
		return;
	}
	
	if (*((int*) A->data) == *((int*) B->data)) return;
	if (*((int*) A->data) < *((int*) B->data)) {
		add(C, A->data);
		A = A->next;
		difference(A, B, C);
	}
	if (*((int*) A->data) > *((int*) B->data)) {
		add(C, B->data);
		B = B->next;
		difference(A, B, C);
	}
}
