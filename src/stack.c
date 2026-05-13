#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/stack.h"

typedef struct node {
    int data;
    struct node* next;
} Node;

struct stack {
    Node* head;
};

// Cria uma pilha vazia
Stack* stack_create() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s != NULL) {
        s->head = NULL;
    }
    return s;
}

bool stack_is_empty(Stack* s) {
    if (!s || !s->head) return true;

    return false;
}

// Inserção na pilha O(1)
void stack_push(Stack* s, int val) {
    if (s == NULL) return;

    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) return;

    new_node->data = val;
    new_node->next = s->head;

    s->head = new_node;
}

bool stack_pop(Stack* s) {
    if (stack_is_empty(s)) return false;

    Node* current = s->head;
    Node* new_head = current->next;
    
    s->head = new_head;

    free(current);
    return true;
}

int stack_peek(Stack* s) {
    if (stack_is_empty(s)) return INT_MIN;
    return s->head->data;
}

void stack_print(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Pilha vazia.\n");
        return;
    }

    Node* current = s->head;
    printf("Topo -> ");
    while (current != NULL) {
        printf("[%d] ", current->data);
        current = current->next;
    }
    printf("\n");
}

void stack_destroy(Stack* s) {
    if (s == NULL) return;
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
    free(s);
}