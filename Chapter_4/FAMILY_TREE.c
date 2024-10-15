// Problem: Chapter 4 - Family Tree
// Description
// Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
// descendants <name>: return number of descendants of the given <name>
// generation <name>: return the number of generations of the descendants of the given <name>

// Note that: the total number of people in the family is less than or equal to 10
// 4
// Input
// Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
// Output
// Each line is the result of a corresponding query.
// Example
// Input
// Peter Newman
// Michael Thomas
// John David
// Paul Mark
// Stephan Mark
// Pierre Thomas
// Mark Newman
// Bill David
// David Newman
// Thomas Mark
// ***
// descendants Newman
// descendants Mark
// descendants David
// generation Mark
// ***
// Output
// 10
// 5
// 2
// 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_NODES = 1010;

typedef struct Node{
    char name[20];
    struct Node *parent;
    struct Node *child[100];
    int num_child;
} Node;

Node* createNode(char *name){
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->parent = NULL;
    node->num_child = 0;
    return node;
}

Node* findNode(Node *root[], char *name, int *num_nodes){
    for(int i = 0; i < *num_nodes; i++){
        if(strcmp(root[i]->name, name) == 0){
            return root[i];
        }
    }
    Node *newNode = createNode(name);
    root[*num_nodes] = newNode;
    (*num_nodes)++;
    return newNode;
}

void addChild(Node *parent, Node *child) {
    parent->child[parent->num_child++] = child;
    child->parent = parent;
}

int cnt_Des(Node *node) {
    int cnt = 0;
    for (int i = 0; i < node->num_child; i++) {
        cnt += 1 + cnt_Des(node->child[i]);
    }
    return cnt;
}

int cnt_Gen(Node *node) {
    if (node == NULL)
        return -1; // Node not found

    int max_gen = 0;
    for (int i = 0; i < node->num_child; i++) {
        int child_gen = cnt_Gen(node->child[i]);
        if (child_gen > max_gen) {
            max_gen = child_gen;
        }
    }

    return max_gen + 1; // Add 1 for the current generation
}


int main(int argc, char const *argv[]){
    Node *root[MAX_NODES];
    int num_nodes = 0;

    char input[20];
    char name1[20], name2[20];

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "***\n") == 0) break;
        sscanf(input, "%s %s", name1, name2);

        Node *child = findNode(root, name1, &num_nodes);
        Node *parent = findNode(root, name2, &num_nodes);
        addChild(parent, child);
    }

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "***\n") == 0) break;
        sscanf(input, "%s %s", name1, name2);

        Node *node = NULL;
        for (int i = 0; i < num_nodes; i++) {
            if (strcmp(root[i]->name, name2) == 0) {
                node = root[i];
                break;
            }
        }

        if (strcmp(name1, "descendants") == 0) {
            printf("%d\n", cnt_Des(node));
        } else if (strcmp(name1, "generation") == 0) {
            Node *node = findNode(root, name2, &num_nodes);
            printf("%d\n", cnt_Gen(node)-1); 
        }
}

    for (int i = 0; i < num_nodes; i++) {
        free(root[i]);
    }

    return 0;
}