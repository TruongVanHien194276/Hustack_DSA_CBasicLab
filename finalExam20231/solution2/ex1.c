// Viết một chương trình C đọc vào từ bàn phím một số nguyên dương n, hiển thị ra màn hình tất cả các số nguyên dương chẵn thuộc [1, n], mỗi số trên một dòng, lần lượt từ số nhỏ đến số lớn.
// Vị dụ:
// INPUT:
// 8
// OUTPUT:
// 2 
// 4
// 6
// 8

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        if (i % 2 == 0) printf("%d\n", i);
    }
    return 0;
}
