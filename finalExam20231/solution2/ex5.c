// Đế quản lý các nhân viên mật vụ, một cơ quan quy ước dánh số định danh cho tùmg nhân viên mật vụ như sau:
// : Ký tự đầu tên là một chữ cát in hoa trong số các chữ cái: A, B, C, D, B
// • Theo sau đó là n chứ số, mỗi chữ số troận giá trị là một trong các ký số: 1, 3,5
// Hấy Viết chương trình C, đọc vào từ bàn phím một chữ cái và số nguyên dương n, sau đó hệt kô ra màn hình toàn bộ các từ bàp ph tinh đanh theo thứ tự từ điển, mỗi tổ hợp trên một dòng. Nếu chữ cát đã cho không phải chữ in hoa liệt kê ở trên thì hiển thị
// "Error" và kết thúc chương trình.
// Ví dụ:
// INPUT:
// A
// 2
// OUTPUT:
// A11
// A13
// A15
// A31
// A33
// A35
// A51
// A53
// A55

#include <stdio.h>

char c;
int n, ans[10];
int num[3] = {1, 3, 5};

void TRY(int u) {
    for (int i = 0; i <= 2; i++) {
        ans[u] = num[i];
        if (u == n) {
            printf("%c", c);
            for (int j = 1; j <= n; j++) printf("%d", ans[j]);
            printf("\n");
        } else TRY(u+1);
    }
}

int main() {
    scanf("%c", &c);
    scanf("%d", &n);
    
    if (c != 'A'&& c != 'B'&& c != 'C' && c != 'D'&& c != 'E') {
        printf("Error");
        return 0;
    }
    TRY(1);

    return 0;
}