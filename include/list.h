#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct list List;

List* list_create();
void list_insert_front(List* l, int val);
bool list_remove(List* l, int val);
bool list_search(List* l, int val);
void list_print(List* l);
void list_destroy(List* l);

#endif