/*
 * Stack implementation using linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* default node: data and pointer to next node. */
struct node {
	Item data;
	struct node *next;
};

/* stack: linked list */
struct stack_type {
	struct node *top;
};

/* Error message if malloc fails */
static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

/* creates an empty stack */
Stack s_create(void)
{
	Stack s = malloc(sizeof(struct stack_type));
	if (s == NULL) {
		terminate("Error in create: stack could not be created.");
	}
	s->top = NULL;
	return s;
}

/* destroys the stack while freeing any Items inside the stack */
void s_destroy(Stack s) 
{
	s_makeEmpty(s);
	free(s);
}

/* removes all Items from the stack while retaining the stack */
void s_makeEmpty(Stack s)
{
	while (!s_isEmpty(s))
		s_pop(s);
}

/* checks if stack is empty; returns true if empty, false if not */
bool s_isEmpty(Stack s)
{
	return s->top == NULL;
}

/* checks if stack is full; returns true if full, false if not */
bool s_isFull(Stack s)
{
	return false;
}

/* adds an item to the stack; terminates the program if fails */
void s_push(Stack s, Item i)
{
	struct node *new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		terminate("Error in push: Could not push item.");
	}
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

/* 
 * removes the top element of the stack and returns the data in the
 * element.
 */
Item s_pop(Stack s)
{
	struct node *current;
	Item data;

	if (s_isEmpty(s)) {
		terminate("Error in pop: stack is empty.");
	}

	current = s->top;
	data = current->data;
	s->top = current->next;
	free(current);
	return data;
}
