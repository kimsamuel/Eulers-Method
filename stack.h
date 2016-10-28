#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack s_create(void);
void s_destroy(Stack s);
void s_makeEmpty(Stack s);
bool s_isEmpty(Stack s);
bool s_isFull(Stack s);
void s_push(Stack s, Item i);
Item s_pop(Stack s);

#endif
