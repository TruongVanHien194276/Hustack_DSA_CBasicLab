// Problem: Chapter 3 - Simulation Queue
// Description
// Perform a sequence of operations over a queue, each element is an integer:
// PUSH v: push a value v into the queue
// POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
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
// 1
// 2
// 3

// Input
// PUSH 1
// POP
// POP
// PUSH 4
// POP
// #
// Output
// 1
// NULL
// 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Queue;

Queue* createNode(int data) {
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    if (!newNode) return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* push(Queue* head, int data) {
    Queue* newNode = createNode(data);
    if (head == NULL) return newNode;

    Queue* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Queue* pop(Queue* head) {
    if (head == NULL) {
        printf("NULL\n");
        return head;
    } else {
        Queue* temp = head;
        head = head->next;
        printf("%d\n", temp->data);
        free(temp);
        return head;
    }
}

int main(int argc, char const *argv[]){
    Queue* head = NULL;
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
