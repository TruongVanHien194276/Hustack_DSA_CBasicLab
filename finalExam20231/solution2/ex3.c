#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char s[100];
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
} Queue;

void start_queue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void ENQUEUE(Queue *q, char *s){
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->s, s);
    p->next = NULL;
    if (q->head == NULL){
        q->head = p;
        q->tail = p;
    } else {
        q->tail->next = p;
        q->tail = p;
    }
}

void DEQUEUE(Queue *q){
    if (q->head == NULL) printf("NULL\n");
    else {
        Node *cur = q->head;
        q->head = q->head->next;
        printf("Welcome %s\n", cur->s);
        free(cur);
    }
}

int main(){
    Queue q[2];
    start_queue(&q[0]);
    start_queue(&q[1]);
    char cmd[100], s[100];

    int x;
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "DEQUEUE") == 0){
            scanf("%d", &x);
            DEQUEUE(&q[x]);
        } else if (strcmp(cmd, "ENQUEUE") == 0){
            scanf("%d %s", &x, s);
            ENQUEUE(&q[x], s);
        } else break;
    }
    
    return 0;
}
