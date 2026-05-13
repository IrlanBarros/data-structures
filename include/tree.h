#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct tree Tree;

Tree* tree_create();
void  tree_insert(Tree* t, int val);
bool  tree_search(Tree* t, int val);
void  tree_remove(Tree* t, int val);
void  tree_print_inorder(Tree* t); // Imprime em ordem crescente
void  tree_destroy(Tree* t);

#endif