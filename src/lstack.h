#ifndef LSTACK_H
#define LSTACK_H

// Global variables
long top; // top element of the stack

struct stack {
	int data;
	struct stack *next;
};

// Display stack
void display_stack(struct stack *start);

// Add new item to stack
struct stack *push(struct stack *start, int value, short *op_status);

// Remove element from stack
struct stack *pop(struct stack *start, short *op_status);

// Delete stack
struct stack *delete(struct stack *start, short *op_status);

// Return top item value
int get_top_value(struct stack *start, short *op_status);

#endif
