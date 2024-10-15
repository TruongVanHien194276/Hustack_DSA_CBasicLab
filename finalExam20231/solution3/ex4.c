#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student{
    char code[9];  
    int score;  
} Stu;

void swap(Stu *a, Stu *b) {
    Stu temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(Stu a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].score > a[max_idx].score) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(&a[i], &a[max_idx]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Stu a[10000];
    int m = 0;

    char code[9];
    int score;
    while (1) {
        scanf("%s", code);
        if (strcmp(code, "#") == 0) break;
        scanf("%d", &score);

        strcpy(a[m].code, code);
        a[m].score = score;
        m += 1;
    }

    selection_sort(a, m);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", a[i].code, a[i].score);
    }

    return 0;
}
