// Problem: Chapter 6 - BST: Build the BST from pre-order sequence of nodes
// Description
// Given a binary search tree T in which the keys of nodes are distinct positive integers. The sequence of keys visited when traversing T in a pre-order principle is a1, a2, ..., an. Compute the sequence of keys visited when traversing T in a post-order principal.

// Input
// Line 1: contains a positive integer n (1 <= n <= 50000)
// Line 2: contains a sequence of distinct positive integer a1, a2, ..., an (1 <= ai <= 1000000)

// Output
// Write the sequence of keys visited when traversing T in a post-order principal (elements are separated by a SPACE character) if the binary search tree exists, and write NULL, otherwise.

// Example
// Input
// 11
// 10 5 2 3 8 7 9 20 15 18 40
// Output
// 3 2 7 9 8 5 18 15 40 20 10


// Example
// Input 
// 11
// 10 5 2 3 8 7 9 20 15 18 4
// Output 
// NULL 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} BST;

BST *createNode(int key) {
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST *constructBST(int pre[], int *preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size) return NULL;

    BST *root = NULL;

    if (key > min && key < max) {
        root = createNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size) {
            root->left = constructBST(pre, preIndex, pre[*preIndex], min, key, size);
            root->right = constructBST(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }

    return root;
}

void postOrder(BST *node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->key);
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);

    int pre[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    int preIndex = 0;
    BST *root = constructBST(pre, &preIndex, pre[0], INT_MIN, INT_MAX, n);

    if (root == NULL || preIndex < n) {
        printf("NULL");
    } else {
        postOrder(root);
    }

    return 0;
}
