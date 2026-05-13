#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue Queue;

Queue* queue_create();
void queue_enqueue(Queue* q, int val); 
bool queue_dequeue(Queue* q);          
int  queue_front(Queue* q);
bool queue_is_empty(Queue* q);
void queue_print(Queue* q);
void queue_destroy(Queue* q);

#endif