#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/queue.h"

typedef struct node {
    int data;
    struct node* next;
} Node;

struct queue {
    Node* head;
    Node* tail;
};

Queue* queue_create() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q) {
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

bool queue_is_empty(Queue* q) {
    return (!q || !q->head);
}

// Inserção O(1) graças ao ponteiro tail
void queue_enqueue(Queue* q, int val) {
    if (!q) return;

    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = val;
    new_node->next = NULL;

    if (queue_is_empty(q)) {
        q->head = new_node;
    } else {
        q->tail->next = new_node;
    }
    
    q->tail = new_node; // O novo nó passa a ser o fim da fila
}

// Remoção O(1) sempre no head
bool queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) return false;

    Node* temp = q->head;
    q->head = q->head->next;

    // Se a fila ficou vazia, o tail não pode apontar para o lixo
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return true;
}

int queue_front(Queue* q) {
    if (queue_is_empty(q)) return INT_MIN;
    return q->head->data;
}

void queue_print(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Fila vazia.\n");
        return;
    }

    Node* current = q->head;
    printf("Inicio -> ");
    while (current) {
        printf("[%d] ", current->data);
        current = current->next;
    }
    printf("<- Fim\n");
}

void queue_destroy(Queue* q) {
    if (!q) return;
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
    free(q);
}