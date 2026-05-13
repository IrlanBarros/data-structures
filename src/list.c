#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

typedef struct node {
    int data;
    struct node* next;
} Node;

struct list {
    Node* head;
};

// Cria uma lista vazia
List* list_create() {
    List* l = (List*) malloc(sizeof(List));
    if (l != NULL) {
        l->head = NULL;
    }
    return l;
}

// Insere um elemento no início da lista O(1)
void list_insert_front(List* l, int val) {
    if (l == NULL) return;
    
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) return; // Falha na alocação
    
    new_node->data = val;
    new_node->next = l->head;
    l->head = new_node;
}

// Remove a primeira ocorrência de um valor O(n)
bool list_remove(List* l, int val) {
    if (l == NULL || l->head == NULL) return false;
    
    Node* current = l->head;
    Node* prev = NULL;
    
    while (current != NULL && current->data != val) {
        prev = current;
        current = current->next;
    }
    
    // Valor não encontrado
    if (current == NULL) return false;
    
    // Se for o primeiro nó
    if (prev == NULL) {
        l->head = current->next;
    } else {
        prev->next = current->next;
    }
    
    free(current);
    return true;
}

// Busca um valor na lista O(n)
bool list_search(List* l, int val) {
    if (l == NULL) return false;
    
    Node* current = l->head;
    while (current != NULL) {
        if (current->data == val) return true;
        current = current->next;
    }
    return false;
}

// Imprime a lista
void list_print(List* l) {
    if (l == NULL) return;
    
    Node* current = l->head;
    printf("Lista: ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Libera toda a memória alocada O(n)
void list_destroy(List* l) {
    if (l == NULL) return;
    
    Node* current = l->head;
    while (current != NULL) {
        Node* next_node = current->next;
        free(current);
        current = next_node;
    }
    free(l);
}