#include <stdio.h>
#include <stdlib.h>
#include "lstack.h"

void display_stack(struct stack *start){
	struct stack *ptr;
	ptr = NULL;
	long int top_item = top;

	if (start == NULL) {
		printf("Empty stack.\n");
		return;
	}

	ptr = start;
	while (ptr != NULL) {
		printf("Element id: %ld, address: %p, value: %d\n", top_item, ptr, ptr->data);
		top_item--;
		ptr = ptr->next;
	}
}

// Add element
struct stack *push(struct stack *start, int val, short *op_status) {
	*op_status = 0;
	struct stack *new_item;
	new_item = (struct stack *) malloc(sizeof(struct stack));
	new_item->data = val;
	new_item->next = NULL;

	if (new_item == NULL) {
		printf("Memory failure: Unable to add a new node.\n");
		return start;
	}

	if (start == NULL) {
		start = new_item;
	}
	else {
		new_item->next = start;
		start = new_item;
	}
	top++;
	*op_status = 1;
	return start;
}

// Remove element
struct stack *pop(struct stack *start, short *op_status){
	*op_status = 0;

	// stack is empty
	if (start == NULL) {
		return start;
	}

	// stack is not empty
    struct stack *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    *op_status = 1;
    top--;

	return start;
}

// Delete stack
struct stack *delete(struct stack *start, short *op_status) {
	while (start != NULL) {
		start = pop(start, op_status);
	}
	return NULL;
}

// Get the value of the top element
int get_top_value(struct stack *start, short *op_status) {
	*op_status = 0;
	int val = 0;

	if (start == NULL) {
		printf("The stack is empty.\n");
		return val;
	}

	*op_status = 1;
	val = start->data;
	return val;
}


