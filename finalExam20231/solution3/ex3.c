#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char str[50];
    struct node *next;
} node;

typedef struct Queue {
    node *head;
    node *tail;
} Queue;

void createQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, char *str) {
    node *p = (node *)malloc(sizeof(node));
    strcpy(p->str, str);
    p->next = NULL;
    if (q->head == NULL) {
        q->head = p;
        q->tail = p;
    } else {
        q->tail->next = p;
        q->tail = p;
    }
}

void dequeue(Queue *q) {
    if (q->head == NULL)
        printf("NULL\n");
    else {
        node *p = q->head;
        q->head = q->head->next;
        printf("Welcome %s\n", p->str);
        free(p);
    }
}

int main() {
    Queue q[2];
    createQueue(&q[0]);
    createQueue(&q[1]);

    char query[50], str[50];
    int u;
    while (scanf("%s", query) == 1) {
        if (!strcmp(query, "ENQUEUE")) {
            scanf("%d %s", &u, str);
            enqueue(&q[u], str);
        } else if (!strcmp(query, "DEQUEUE")) {
            scanf("%d", &u);
            dequeue(&q[u]);
        } else break;
    }

    return 0;
}
