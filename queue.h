#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue q_create(void);
void q_destroy(Queue q);
void q_makeEmpty(Queue q);
bool q_isEmpty(Queue q);
bool q_isFull(Queue q);
void q_add(Queue q, Item i);
Item q_peek(Queue q);
Item q_remove(Queue q);

#endif
