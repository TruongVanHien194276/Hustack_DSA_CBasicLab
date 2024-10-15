// Problem: Chapter 6 - BST with insertion and removal operations
// Description
// Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
// Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
// insert k: insert a new node having key = k into T (do nothing if the node having key = k exists)
// remove k: remove the node having key = k from T (in case the root is removed, then replace the root by the smallest-key node of the right sub-tree) 
// preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
// postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

// Input
// Each line contains a command of three above format
// The input is terminated by a line containing #

// Output
// Write the information of preorder, postorder commands described above

// Example
// Input 
// insert 3
// insert 4
// remove 4
// preorder
// postorder
// insert 5
// insert 1
// insert 8
// remove 1
// preorder
// postorder
// #

// Output 
// 3
// 3
// 3 5 8
// 8 5 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    struct node *right;
    struct node *left;
} Node;

Node *root = NULL;

Node *createNode(int key){
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->right = NULL;
    p->left = NULL;
    return p;
}

Node *insertNode(Node *r, int key){
    if (r == NULL) return createNode(key);
    if (r->key == key) return r;
    if (r->key > key) r->left = insertNode(r->left, key);
    else r->right = insertNode(r->right, key);
    return r;
}

Node *removeRoot(Node *r){
    if (r == NULL) return NULL;
    if (r->right == NULL){
        Node *tmp = r;
        r = r->left;
        free(tmp);
        return r;
    }
    Node *p = r->right;
    if (p->left == NULL){
        Node *tmp = p;
        r->key = p->key;
        r->right = p->right;
        free(tmp);
        return r;
    }
    Node *u;
    while (p->left != NULL){
        u = p;
        p = p->left;
    }
    u->left = p->right;
    r->key = p->key;
    free(p);
    return r;
}

Node *removeNode(Node *r, int key){
    if (r == NULL) return NULL;
    if (r->key == key) return removeRoot(r);
    if (r->key > key) r->left = removeNode(r->left, key);
    else r->right = removeNode(r->right, key);
    return r;
}

void preOrder(Node *r){
    if (r == NULL) return;
    printf("%d ", r->key);
    preOrder(r->left);
    preOrder(r->right);
}

void postOrder(Node *r){
    if (r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ", r->key);
}

int main(int argc, char const *argv[]){
    char cmd[10];
    int x;

    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        else if (strcmp(cmd, "insert") == 0){
            scanf("%d", &x);
            root = insertNode(root, x);
        } else if (strcmp(cmd, "preorder") == 0){
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "postorder") == 0){
            postOrder(root);
            printf("\n");
        } else{
            scanf("%d", &x);
            root = removeNode(root, x);
        }
    }
    return 0;
}
