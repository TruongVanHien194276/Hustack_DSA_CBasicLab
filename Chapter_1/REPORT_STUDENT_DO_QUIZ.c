// Problem: Chapter 1 - Report student doing quiz on date
// Description
// Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
// Input
// Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
// <yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>
// Kết thúc dữ liệu là 1 dòng chứa dấu *
// Output
// Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong ngày <yyyy-mm-dd>
// (chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)
// Example
// Input
// 2022-01-02 10:30:24 dungpq question1
// 2022-01-03 11:30:24 dungpq question1
// 2022-02-01 03:30:20 viettq question2
// 2022-02-01 03:35:20 viettq question1
// 2022-03-01 03:30:20 viettq question7
// 2022-01-02 11:20:24 viettq question2
// *
// Output
// 2022-01-02 2
// 2022-01-03 1
// 2022-02-01 2
// 2022-03-01 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[9];
    char user_id[20];
    char ques_id[20];
} Record;

int partition(Record arr[], int low, int high) {
    Record pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j].date, pivot.date) < 0) {
            i++;
            Record temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Record temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(Record arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[]) {
    int n = 0;
    Record records[100001];
    while (1) {
        scanf("%[^ \n]%*c", records[n].date);
        if (!strcmp(records[n].date, "*")) break;
        scanf("%[^ ]%*c", records[n].time);
        scanf("%[^ ]%*c", records[n].user_id);
        scanf("%[^\n]%*c", records[n].ques_id);
        n++;
    }

    quickSort(records, 0, n-1);

    int j = 0, cnt = 0; 
    for (int i = 0; i < n; i++) {
        if (!strcmp(records[j].date, records[i].date)) cnt += 1;
        else {
            printf("%s %d\n", records[j].date, cnt);
            j = i;
            i--;
            cnt = 0;
        }
    }
    printf("%s %d", records[j].date, cnt);

    return 0;
}