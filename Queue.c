#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
	Item data;
	struct node* next;
};

struct queue_type {
	struct node* rear;
	struct node* front;
};

static void terminate(const char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Queue q_create(void)
{
	Queue q = malloc(sizeof(struct queue_type));
	if (q == NULL) {
		terminate("Error in q_create: could not create queue.");
	}
	q->rear = NULL;
	q->front = NULL;
	return q;
}

void q_destroy(Queue q)
{
	q_makeEmpty(q);
	free(q);
}

void q_makeEmpty(Queue q)
{
	if (!q_isEmpty(q)) {
		q_remove(q);
	}
}

bool q_isEmpty(Queue q)
{
	return q->rear == NULL && q->front == NULL;
}

bool q_isFull(Queue q)
{
	return false;
}

void q_add(Queue q, Item i)
{
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		terminate("Error in q_add: could not add to queue.");
	}
	new_node->data = i;
	if (q_isEmpty(q)) {
		q->front = new_node;
		q->rear = new_node;
	} else {
		(q->rear)->next = new_node;
		q->rear = new_node;
	}
}

Item q_peek(Queue q)
{
	if (q_isEmpty(q)) {
		terminate("Error in q_peek: queue is empty.");
	}
	return (q->front)->data;
}

Item q_remove(Queue q)
{
	struct node* current;
	Item data;
	if (q_isEmpty(q)) {
		terminate("Error in q_remove: queue is empty.");
	}
	current = q->front;
	data = current->data;
	if (q->front == q->rear) {
		q->front = q->rear = NULL;
	} else {
		q->front = current->next;
	}
	free(current);
	return data;
}
