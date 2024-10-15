// Problem: Chapter 6 - BST Creation and Query about PreOrder and PostOrder Traversal
// Description
// Each node of a Binary Search Tree (BST) T has a key (keys of nodes must be all different).
// Perform a sequence of operations on a Binary Search Tree T (starting from empty BST) including:
// insert k: insert a new node having key = k into T
// preorder: print (in a new line) the sequence of keys of nodes of T visited by a Pre-Order traversal (elements are separated by a SPACE character)
// postorder: print (in a new line) the sequence of keys of nodes of T visited by a Post-Order traversal (elements are separated by a SPACE character)

// Input
// Each line contains a command of three above format
// The input is terminated by a line containing #
// Output
// Write the information of preorder, postorder commands described above

// Example
// Input
// insert 5
// insert 9
// insert 2
// insert 1
// preorder
// insert 8
// insert 5
// insert 3
// postorder
// #

// Output
// 5 2 1 9
// 1 3 2 8 9 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BST;

BST *createNode(int key) {
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST *insert(BST *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(BST *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BST *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->key);
}

int main(int argc, char const *argv[]){
    BST *root = NULL;
    char cmd[10];
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "insert") == 0) {
            int key;
            scanf("%d", &key);
            root = insert(root, key);
        } else if (strcmp(cmd, "preorder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "postorder") == 0) {
            postOrder(root);
            printf("\n");
        } else break;
    }
    return 0;
}
