// Một kỳ thi tuyển sinh có tối đa 100 000 thí sinh tham dự. Mỗi thí sinh có 2 thông tin:
// • code: la ma thi sinh (xau key tu; co do dai toi da la 8 ky tur khing c6 thi sinh nao
// trùng mã với nhau)
// • score: điểm số (số nguyên từ 0 đến 100 000, giả sử không có hai thí sinh bất kỳ nào bằng điểm nhau)
// Kỳ thi này cần chọn lấy n thí sinh có điểm số cao nhất từ trên xuống. Hãy viết chương trình C hiển thị ra màn hình thông tin code và score của n thí sinh đó.
// Dữ liệu đầu vào:
// Dòng đầu chứa số tự nhiên n là số thí sinh có điểm cao nhất cần hiển thị.
// Các dòng tiếp theo, mỗi dòng chứa 2 thông tin là code và score của từng thí sinh, cách nhau bởi phím cách.
// Dữ liệu đầu vào kết thúc bởi dòng chứa #
// Kết quả đầu ra:
// Hiến thị thông tin n thí sinh có điểm cao nhất cuộc thi, mỗi thí sinh trên một dòng, code và score cách nhau bởi phím cách, lần lượt từ thí sinh có điểm cao nhất đến thấp dần.

// INPUT:
// 3
// 20235883 23567
// 20235887 25671
// 20235889 33456
// 20285893 72193
// 20235895 55231
// 20235899 66128
// #
// OUTPUT:
// 20235893 72193
// 20235899 66128
// 20235895 55231

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[10];  
    int score; 
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].score;
    int i = low - 1;  

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].score >= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Student students[10000];
    int cnt = 0;

    while (1) {
        char code[10];
        int score;
        scanf("%s", code);
        if (code[0] == '#') break;
        scanf("%d", &score);

        strcpy(students[cnt].code, code);
        students[cnt].score = score;
        cnt++;
    }

    quickSort(students, 0, cnt-1);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].code, students[i].score);
    }

    return 0;
}
