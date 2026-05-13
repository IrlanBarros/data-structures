#include <stdio.h>
#include "../include/list.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/tree.h"

int main() {
    // Testes de estrutura lista encadeada
    printf("Iniciando testes da Lista Encadeada...\n");
    
    List* my_list = list_create();
    
    list_insert_front(my_list, 10);
    list_insert_front(my_list, 20);
    list_insert_front(my_list, 30);
    
    list_print(my_list); // Esperado: [30] -> [20] -> [10] -> NULL
    
    printf("Buscando 20: %s\n", list_search(my_list, 20) ? "Encontrado" : "Não encontrado");
    
    printf("Removendo 20...\n");
    list_remove(my_list, 20);
    list_print(my_list); // Esperado: [30] -> [10] -> NULL
    
    list_destroy(my_list);
    printf("Testes finalizados com sucesso.\n");

    // Testes de estrutura pilha
    printf("Iniciando testes da Pilha...\n");
    
    Stack* my_stack = stack_create();
    
    stack_push(my_stack, 10);
    stack_push(my_stack, 20);
    stack_push(my_stack, 30);
    
    stack_print(my_stack); // Esperado: [30] -> [20] -> [10] -> NULL
    
    printf("Recuperando valor do topo: %d\n", stack_peek(my_stack));
    
    printf("Removendo valor...\n");
    stack_pop(my_stack);
    stack_print(my_stack); // Esperado: [10] -> [20] -> NULL
    
    stack_destroy(my_stack);
    printf("Testes finalizados com sucesso.\n");

    // Testes de estrutura fila
    printf("\nIniciando testes da Fila...\n");
    Queue* q = queue_create();

    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);

    queue_print(q); // Esperado: Inicio -> [1] [2] [3] <- Fim

    printf("Atendendo (removendo) o primeiro...\n");
    queue_dequeue(q);
    queue_print(q); // Esperado: Inicio -> [2] [3] <- Fim

    queue_destroy(q);

    // Testes da estrutura árvore (BST)
    printf("\nIniciando testes da Arvore (BST)...\n");
    Tree* my_tree = tree_create();

    tree_insert(my_tree, 50);
    tree_insert(my_tree, 30);
    tree_insert(my_tree, 70);
    tree_insert(my_tree, 20);
    tree_insert(my_tree, 40);

    tree_print_inorder(my_tree); // Esperado: 20 30 40 50 70

    printf("Buscando 40: %s\n", tree_search(my_tree, 40) ? "Encontrado" : "Nao encontrado");

    printf("Removendo 30...\n");
    tree_remove(my_tree, 30);
    tree_print_inorder(my_tree);

    tree_destroy(my_tree);
    
    return 0;
}