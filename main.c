#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"
#include "src/lstack.h"

#define clear() printf("\033[H\033[J")

const char *menu[] = {
		" 1. Add element to stack.",
		" 2. Remove element from stack.",
		" 3. Return the value of the top element.",
		" 4. Display stack items.",
		" 5. Exit the program",
		NULL
};

int main(void) {
	top = -1; // stack counter
	struct stack *start;
	start = NULL;
	short op_status = 0;

	// Menu
	short opt;
	const short MINOPT = 1;
	const short MAXOPT = get_menu_length(menu);
	clear();
	display_menu(menu);

	opt = select_option(MINOPT, MAXOPT);

	while (1) {
		printf("You have selected: %d\n", opt);
		switch (opt) {
			case 1:
				clear();
				printf("Adding a new element to stack.\n");
				int value = enter_value(&op_status);
				start = push(start, value, &op_status);
				break;
			case 2:
				clear();
				printf("Removing an element from stack.\n");
				start = pop(start, &op_status);

				if (op_status == 1) {
					printf("Top element removed.\n");
				} else {
					printf("Failed to remove element from stack.\n");
				}
				break;
			case 3:
				clear();
				printf("Returning the value of the top element:\n");
				int top_value = get_top_value(start, &op_status);
				if (op_status==1) {
					printf("The value of the stack top element is %d.\n", top_value);
				}
				break;
			case 4:
				clear();
				printf("Displaying stack items.\n");
				display_stack(start);
				break;
			case 5:
				clear();
				printf("Exiting the program\n");
				// delete stack
				start = delete(start, &op_status);
				return 0;
		}
		// Asking user for further actions;
		display_menu(menu);
		opt = select_option(MINOPT, MAXOPT);
	}
	return 0;
}
