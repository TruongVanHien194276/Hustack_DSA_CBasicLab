// Organizing a Corporate Hierarchy
// Imagine you are the head of a large corporation, and you need to structure your company’s management hierarchy. Each employee is identified by a unique ID, and you need to ensure that this hierarchy is well-balanced for efficient communication and management. You also want to know the depth of the hierarchy, which is the longest path from the CEO to any employee.


// Problem Statement:
// Given the following operations:


// MakeRoot u: This creates the root of the hierarchy with employee ID u.
// AddLeft u v: This adds an employee with ID u as a direct subordinate (left child) of the employee with ID v.
// AddRight u v: This adds an employee with ID u as a direct subordinate (right child) of the employee with ID v.
// You need to:


// Build the hierarchy based on these operations.
// Determine if the hierarchy is balanced. A balanced hierarchy means that for every employee, the difference in depth between their left and right subordinates is at most 1.
// Compute the depth of the hierarchy, which is the longest path from the CEO to any employee.
// Input Format:
// The first line contains MakeRoot u, where u is the ID of the root (CEO) of the hierarchy.
// Each subsequent line contains either AddLeft u v or AddRight u v commands, adding employees as left or right subordinates respectively.
// The last line contains *, marking the end of the input.
// Output Format:
// Print two integers z and h separated by a space:
// h is the depth of the hierarchy.
// z is 1 if the hierarchy is balanced, and 0 otherwise.
// Example:
// Input:
// MakeRoot 1
// AddLeft 2 1
// AddRight 3 1
// AddLeft 4 2
// AddRight 5 2
// *
// Output:
// 1 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;
Node *nodes[50010]; 

Node *createNode(int v) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = v;
    p->left = NULL;
    p->right = NULL;
    nodes[v] = p;  
    return p;
}

Node *findNode(int v) {
    return nodes[v];  
}

void insertNode(int u, int v, char c) {
    Node *r = findNode(v);
    if (r == NULL) return;

    Node *p = createNode(u);
    if (c == 'L' && r->left == NULL) r->left = p;
    if (c == 'R' && r->right == NULL) r->right = p;
}

int height(Node *r) {
    if (r == NULL) return 0;
    int left = height(r->left);
    int right = height(r->right);
    return 1 + (left > right ? left : right);
}

int isBalanced(Node *r) {
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
            root = createNode(u);
        } else if (strcmp(cmd, "AddLeft") == 0){
            scanf("%d %d", &u, &v);
            insertNode(u, v, 'L');
        } else if (strcmp(cmd, "AddRight") == 0){
            scanf("%d %d", &u, &v);
            insertNode(u, v, 'R');
        } else break;
    }

    int z = isBalanced(root);
    int h = height(root);
    printf("%d %d", z, h);

    return 0;
}


