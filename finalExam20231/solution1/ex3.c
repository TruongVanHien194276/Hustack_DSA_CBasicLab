// Thầy Hiếu rất nổi tiếng trong cộng đồng Aikido nên câu lạc bộ của thầy thường có nhiều bạn đăng kí học (tối thiểu 0 bạn, tối đa có thẻ lên đên 4000 bạn). Lần đăng k này thầy cho các bạn đăng kí xếp thành hai hàng, một bên là nam, một bên là nữ. Mỗi khi có một bạn nữ đến sẽ xếp vào cuối hàng nữ, có một bạn nam đến sẽ xếp vào cuối hàng nam. Tại một thời điểm sẽ có một bạn nam hoặc nữ ở đầu hàng đăng kí vào lớp và tên của bạn sẽ được hiển thị trên bảng điện tử chào mừng. Lưu ý, do các tên đẹp được nhiều bố mẹ chọn nên tên các bạn có thể trùng nhau.
// Input: nhận một trong các lệnh sau:
// • ENQUEUE X V: Xếp bạn V (xâu kí tự không chứa dấu cách có tối đa 20 kí tự) vào cuối hàng X (nhận một trong hai giá trị 0 (nam) và 1 (nữ)).
// • DEQUEUE X• Dang ki ban dau hang & vao ldp va hien thi ten ra stdout cing voi
// lời chào mừng "Welcome tên" (nếu hàng đã hết thì hiển thị NULL)
// •#: Kết thúc chương trình
// Ví dụ:
// INPUT:
// ENQUEUE 0 Long
// ENQUEUE 0 Hoang
// ENQUEUE 1 Hoa
// DEQUEUE 0
// DEQUEUE 1
// DEQUEUE 1
// ENQUEUE 0 Quyet
// #
// OUTPUT:
// Welcome Long
// Welcome Hoang
// NULL

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    char name[20];
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
} Queue;

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, char *name){
    Node *p = (Node*)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->next = NULL;
    if (q->head == NULL){
        q->head = p;
        q->tail = p;
    } else {
        q->tail->next = p;
        q->tail = p;
    }
}

void dequeue(Queue *q){
    if (q->head == NULL) printf("NULL\n");
    else {
        Node *tmp = q->head;
        q->head = q->head->next;
        printf("Welcome %s\n", tmp->name);
        free(tmp);
    }
}

int main(){
    Queue q[2];
    initQueue(&q[0]);
    initQueue(&q[1]);
    char cmd[20], name[20];

    int x;
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "ENQUEUE") == 0){
            scanf("%d %s", &x, name);
            enqueue(&q[x], name);
        } else if (strcmp(cmd, "DEQUEUE") == 0){
            scanf("%d", &x);
            dequeue(&q[x]);
        } else break;
    }
    
    return 0;
}
