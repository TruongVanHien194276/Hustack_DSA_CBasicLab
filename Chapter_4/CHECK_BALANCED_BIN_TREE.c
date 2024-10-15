// Problem: Chapter 4 - Check balanced binary tree and compute the height
// Description
// Each node of a binary tree has a field id which is the identifier of the node. Build a binary tree and check if the tree is a balanced tree, compute the height of the given tree (the number of nodes of the tree can be upto 50000)
// Input
// Line 1 contains MakeRoot u: make the root of the tree having id = u
// Each subsequent line contains: AddLeft or AddRightcommands with the format
// AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
// AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
// The last line contains * which marks the end of the input
// Output
// Write two integers z and h (separated by a SPACE character) in which h is the height (the number of nodes of the longest path from the root to a leaf) and z = 1 if the tree is balanced and z = 0, otherwise

// Example
// Input
// MakeRoot 1
// AddLeft 2 1
// AddRight 3 1
// AddLeft 9 2
// AddRight 4 2
// AddLeft 6 3
// AddRight 5 3
// AddLeft 7 4
// AddRight 8 4
// *
// Output
// 1 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *left;
    struct Node *right;
} Tree;

Tree *root = NULL;
Tree *nodes[50010]; 

Tree *makeNode(int v) {
    Tree *p = (Tree *)malloc(sizeof(Tree));
    p->id = v;
    p->left = NULL;
    p->right = NULL;
    nodes[v] = p;  
    return p;
}

Tree *findNode(int v) {
    return nodes[v];  
}

void insertNode(int u, int v, char c) {
    Tree *r = findNode(v);
    if (r == NULL) return;

    Tree *p = makeNode(u);
    if (c == 'L' && r->left == NULL) r->left = p;
    if (c == 'R' && r->right == NULL) r->right = p;
}

int height(Tree *r) {
    if (r == NULL) return 0;
    int left = height(r->left);
    int right = height(r->right);
    return left > right ? left + 1 : right + 1;
}

int isBalanced(Tree *r) {
    if (r == NULL) return 1;
    int left = height(r->left);
    int right = height(r->right);
    if (abs(left - right) <= 1 && isBalanced(r->left) && isBalanced(r->right)) return 1;
    return 0;
}

int main(int argc, char const *argv[]){
    char cmd[10];
    int u, v;
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "MakeRoot") == 0){
            scanf("%d", &u);
            root = makeNode(u);
        }
        else if (strcmp(cmd, "AddLeft") == 0){
            scanf("%d %d", &u, &v);
            insertNode(u, v, 'L');
        }
        else if (strcmp(cmd, "AddRight") == 0){
            scanf("%d %d", &u, &v);
            insertNode(u, v, 'R');
        }
        else {
            int z = isBalanced(root);
            int h = height(root);
            printf("%d %d", z, h);
            break;
        }
    }
    return 0;
}
