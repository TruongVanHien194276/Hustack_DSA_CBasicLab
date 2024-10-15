// Problem: Chapter 6 - BST - Insertion and PreOrder Traversal
// Description
// Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
// insert k: insert a key k into the BST (do not insert if the key k exists)
// Input
// •Each line contains command under the form: “insert k”
// •The input is terminated by a line containing #
// Output
// •Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
// Example
// Input
// insert 20
// insert 10
// insert 26
// insert 7
// insert 15
// insert 23
// insert 30
// insert 3
// insert 8
// #
// Output
// 20 10 7 3 8 15 26 23 30

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} BST;

BST *insert(BST *root, int key) {
    if (root == NULL) {
        BST *newNode = (BST *)malloc(sizeof(BST));
        newNode->key = key;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preOrder(BST *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main(int argc, char const *argv[]){
    BST *root = NULL;
    char cmd[10];
    int key;
    while (1) {
        scanf("%s", cmd);
        if (cmd[0] == '#') break;

        scanf("%d", &key);
        root = insert(root, key);
    }
    preOrder(root);
    return 0;
}
