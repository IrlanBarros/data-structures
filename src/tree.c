#include <stdio.h>
#include <stdlib.h>
#include "../include/tree.h"

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

struct tree {
    Node* root;
};

Tree* tree_create() {
    Tree* t = (Tree*) malloc(sizeof(Tree));
    if (t) t->root = NULL;
    return t;
}

// Funções auxiliares recursivas (estáticas para ficarem presas ao .c)
static Node* create_node(int val) {
    Node* n = (Node*) malloc(sizeof(Node));
    if (n) {
        n->data = val;
        n->left = n->right = NULL;
    }
    return n;
}

static Node* insert_recursive(Node* root, int val) {
    if (root == NULL) return create_node(val);

    if (val < root->data)
        root->left = insert_recursive(root->left, val);
    else if (val > root->data)
        root->right = insert_recursive(root->right, val);

    return root;
}

void tree_insert(Tree* t, int val) {
    if (t) t->root = insert_recursive(t->root, val);
}

static bool search_recursive(Node* root, int val) {
    if (root == NULL) return false;
    if (root->data == val) return true;

    if (val < root->data)
        return search_recursive(root->left, val);
    return search_recursive(root->right, val);
}

bool tree_search(Tree* t, int val) {
    if (!t) return false;
    return search_recursive(t->root, val);
}

// Encontra o menor nó de uma subárvore (usado na remoção)
static Node* find_min(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

static Node* remove_recursive(Node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data)
        root->left = remove_recursive(root->left, val);
    else if (val > root->data)
        root->right = remove_recursive(root->right, val);
    else {
        // Caso 1 e 2: Sem filhos ou apenas um filho
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Caso 3: Dois filhos. Pega o sucessor (menor da subárvore direita)
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = remove_recursive(root->right, temp->data);
    }
    return root;
}

void tree_remove(Tree* t, int val) {
    if (t) t->root = remove_recursive(t->root, val);
}

static void print_inorder_recursive(Node* root) {
    if (root != NULL) {
        print_inorder_recursive(root->left);
        printf("[%d] ", root->data);
        print_inorder_recursive(root->right);
    }
}

void tree_print_inorder(Tree* t) {
    if (!t || !t->root) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("BST (In-Order): ");
    print_inorder_recursive(t->root);
    printf("\n");
}

static void destroy_recursive(Node* root) {
    if (root != NULL) {
        destroy_recursive(root->left);
        destroy_recursive(root->right);
        free(root);
    }
}

void tree_destroy(Tree* t) {
    if (t) {
        destroy_recursive(t->root);
        free(t);
    }
}