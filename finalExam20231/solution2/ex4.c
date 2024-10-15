#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[9]; 
    int score;  
} Student;

void insertionSort(Student arr[], int n) {
    int i, j;
    Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].score < key.score) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Student arr[10000];
    int cnt = 0;

    char code[9];
    int score;
    while (1) {
        scanf("%s", code);
        if (code[0] == '#') break;
        scanf("%d", &score);

        strcpy(arr[cnt].code, code);
        arr[cnt].score = score;
        cnt += 1;
    }

    insertionSort(arr, cnt);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].code, arr[i].score);
    }

    return 0;
}
