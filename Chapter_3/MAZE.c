// Problem: Chapter 3 - Maze
// Description
// Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.

// Input
// Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
// Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A

// Output
// Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.

// Ví dụ

// Input
// 8 12 5 6
// 1 1 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 1 1 0 1 0 0 1 1
// 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 0 0 1 0 1
// 1 0 0 1 0 0 0 0 0 1 0 0
// 1 0 1 0 1 0 0 0 1 0 1 0
// 0 0 0 0 1 0 1 0 0 0 0 0
// 1 0 1 1 0 1 1 1 0 1 0 1

// Output
// 7

#include <stdio.h>
#include <stdlib.h>

const int MAXN = 1007;

int a[MAXN][MAXN];
int n, m, r, c;
int ix []= {-1,1,0,0};
int iy []= {0,0,-1,1};
int ok = 0;
int check[MAXN][MAXN];
int d[MAXN][MAXN];
int res = MAXN;

typedef struct {
    int first;
    int second;
} pair;

typedef struct {
    pair* data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (pair*)malloc(MAXN * MAXN * sizeof(pair));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, pair p) {
    q->rear = (q->rear + 1) % (MAXN * MAXN);
    q->data[q->rear] = p;
    q->size++;
}

pair dequeue(Queue* q) {
    pair item = q->data[q->front];
    q->front = (q->front + 1) % (MAXN * MAXN);
    q->size--;
    return item;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void solve(int u, int v){
    Queue* q = createQueue();
    pair p = {u, v};
    enqueue(q, p);
    check[u][v] = 1;
    while (!isEmpty(q)){
        pair rc = dequeue(q);
        int r = rc.first;
        int c = rc.second;

        if (r < 1 || r > n || c < 1 || c > m){
            if (res > d[r][c] ){
                res = d[r][c];
            }
            ok = 1;
            return;
        }

        for (int i = 3; i >= 0; i--){
            int x = r + ix[i];
            int y = c + iy[i];
            if (a[x][y] == 1) continue;
            if (!check[x][y]){
                d[x][y] = d[r][c] + 1;
                check[x][y] = 1;
                pair p = {x, y};
                enqueue(q, p);
            }
        }
    }
}

int main(int argc, char const *argv[]){
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for (int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            check[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j<= m; j++){
            scanf("%d", &a[i][j]);
        }
    }

    solve(r, c);
    if (ok) printf("%d", res);
    else printf("-1");

    return 0;
}