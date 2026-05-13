#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack Stack;

Stack* stack_create();
void stack_push(Stack* s, int val);
bool stack_pop(Stack* s);
int  stack_peek(Stack* s);
bool stack_is_empty(Stack* s);
void stack_print(Stack* s);
void stack_destroy(Stack* s);

#endif