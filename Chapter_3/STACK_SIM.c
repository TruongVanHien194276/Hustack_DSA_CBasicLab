// Problem: Chapter 3 - Simulation Stack
// Description
// Perform a sequence of operations over a stack, each element is an integer:
// PUSH v: push a value v into the stack
// POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
// Input
// Each line contains a command (operration) of type
// PUSH  v
// POP
// Output
// Write the results of POP operations (each result is written in a line)
// Example
// Input
// PUSH 1
// PUSH 2
// PUSH 3
// POP
// POP
// PUSH 4
// PUSH 5
// POP
// #
// Output
// 3
// 2
// 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Stack;

Stack* createNode(int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    if (!newNode) return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* push(Stack* head, int data) {
    Stack* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Stack* pop(Stack* head) {
    if (head == NULL) {
        printf("NULL\n");
        return head;
    }
    else {
        Stack* temp = head;
        head = head->next;
        printf("%d\n", temp->data);
        free(temp);
        return head;
    }
}

int main(int argc, char const *argv[]){
    Stack* head = NULL;
    char cmd[10];
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "PUSH") == 0) {
            int x;
            scanf("%d", &x);
            head = push(head, x);
        } else if (strcmp(cmd, "POP") == 0) {
            head = pop(head);
        } else break;
    }
    return 0;
}
