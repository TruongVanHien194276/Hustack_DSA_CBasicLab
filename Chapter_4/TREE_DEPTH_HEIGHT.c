// Problem: Chapter 4 - Tree manipulation query depth - height
// Description
// Mỗi nút trên 1 cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
// Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
// · MakeRoot u: Tạo ra nút gốc u của cây
// · Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không thêm mới)
// · Height u:  Tính và trả về độ cao của nút u
// · Depth u: Tính và trả về độ sâu của nút u
// Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
// · Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
// · Kết quả: ghi ra mỗi dòng kết quả của các lệnh Height và Depth tương ứng đọc được từ đầu vào
// Ví dụ:
// Dữ liệu
// MakeRoot 10
// Insert 11 10
// Insert 1 10
// Insert 3 10
// Insert 5 11
// Insert 4 11
// Height 10
// Depth 10
// Insert 8 3
// Insert 2 3
// Insert 7 3
// Insert 6 4
// Insert 9 4
// Height 10
// Depth 10
// Depth 3
// *
// Kết quả
// 3
// 1
// 4
// 1
// 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int id;
    struct Node* leftMostChild;
    struct Node* rightSibling;
}Tree;

Tree* root = NULL;

Tree* makeNode(int v){
    Tree* p = (Tree*)malloc(sizeof(Tree));
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Tree* findNode(Tree* r, int v){
    if (r == NULL) return NULL;
    if (r->id == v) return r;
    Tree* p = r->leftMostChild;
    while (p != NULL){
        Tree* q = findNode(p, v);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

void insertNode(int u, int v){
    Tree* r = findNode(root, v);

    Tree* p = makeNode(u);
    if (r->leftMostChild == NULL){
        r->leftMostChild = p;
    } else {
        Tree* h = r->leftMostChild;
        while (h->rightSibling != NULL){
            h = h->rightSibling;
        }
        h->rightSibling = p;
    }
}

int height(Tree* r){
    if (r == NULL) return 0;
    Tree* p = r->leftMostChild;
    int max = 0;
    while (p != NULL){
        int h = height(p);
        if (h > max) max = h;
        p = p->rightSibling;
    }
    return max + 1;
}

int depth(Tree* r, int v){
    if (r == NULL) return -1;
    if (r->id == v) return 1; 
    Tree* p = r->leftMostChild;
    while (p != NULL){
        int d = depth(p, v);
        if (d != -1) return d + 1;
        p = p->rightSibling;
    }
    return -1;
}

int main(int argc, char const *argv[]){
    char cmd[10];
    int u, v;
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "MakeRoot") == 0){
            scanf("%d", &u);
            root = makeNode(u);
        } else if (strcmp(cmd, "Insert") == 0){
            int u, v;
            scanf("%d%d", &u, &v);
            insertNode(u, v);
        } else if (strcmp(cmd, "Height") == 0){
            scanf("%d", &u);
            printf("%d\n", height(findNode(root, u)));
        } else if (strcmp(cmd, "Depth") == 0){
            scanf("%d", &u);
            printf("%d\n", depth(root, u));
        } else break;
    }
    return 0;
}
