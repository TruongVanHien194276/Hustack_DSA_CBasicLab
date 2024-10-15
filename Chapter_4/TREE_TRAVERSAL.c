// Problem: Chapter 4 - Binary Tree Manipulation & Traversal
// Description
// Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau). Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)
// MakeRoot u: tạo một nút gốc có id bằng u
// AddLeft u v: tạo một nút có id = u và chèn vào vị trí con trái của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con trái rồi)
// AddRight u v: tạo một nút có id = u và chèn vào vị trí con phải của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con phải rồi)
// PreOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự trước (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
// InOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự giữa (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
// PostOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự sau (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
 
// Input
// Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). Kết thúc của dữ liệu input là dòng chứa duy nhất ký tự *

// Output
// Ghi ra trên 1 dòng kết quả của 1 trong số 3 thao tác InOrder, PreOrder, PostOrder mô tả ở trên

// Example
// Input
// MakeRoot 1
// AddLeft 2 1
// AddRight 3 1
// AddLeft 4 3
// AddRight 5 2
// PreOrder
// AddLeft 6 5
// AddRight 7 5
// InOrder
// *

// Output
// 1 2 5 3 4
// 2 6 5 7 1 4 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int id;
    struct Node* left;
    struct Node* right;
}Tree;

Tree* root = NULL;

Tree* makeNode(int v){
    Tree* p = (Tree*)malloc(sizeof(Tree));
    p->id = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Tree* findNode(Tree* r, int v){
    if (r == NULL) return NULL;
    if (r->id == v) return r;
    Tree* p = findNode(r->left, v);
    if (p == NULL) p = findNode(r->right, v);
    return p;
}

void insertNode(int u, int v, char c){
    Tree* r = findNode(root, v);
    if (r == NULL) return;

    Tree* p = makeNode(u);
    if (c == 'L' && r->left == NULL) r->left = p;
    if (c == 'R' && r->right == NULL) r->right = p;
}

void preOrder(Tree* r){
    if (r == NULL) return;
    printf("%d ", r->id);
    preOrder(r->left);
    preOrder(r->right);
}

void inOrder(Tree* r){
    if (r == NULL) return;
    inOrder(r->left);
    printf("%d ", r->id);
    inOrder(r->right);
}

void postOrder(Tree* r){
    if (r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ", r->id);
}

int main(int argc, char const *argv[]){
    char cmd[10];
    int u, v;
    while (1){
        scanf("%s", cmd);
        if (strcmp(cmd, "MakeRoot") == 0){
            scanf("%d", &u);
            root = makeNode(u);
        } else if (strcmp(cmd, "AddLeft") == 0){
            scanf("%d %d", &u, &v);
            insertNode(u, v, 'L');
        } else if (strcmp(cmd, "AddRight") == 0){
            scanf("%d %d", &u, &v);
            insertNode(u, v, 'R');
        } else if (strcmp(cmd, "PreOrder") == 0){
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "InOrder") == 0){
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "PostOrder") == 0){
            postOrder(root);
            printf("\n");
        } else break;
    }
    return 0;
}
