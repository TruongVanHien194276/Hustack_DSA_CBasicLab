// Problem: Chapter 5 - Sort vectors in a lexicographic order
// Description
// Given a sequence of n vectors A[1], A[2], ..., A[n] of length m. Sort these vector in a non-decreasing order.
// Input
// Line 1 contains 2 positive integers n and m (1 <= n <= 100000, 1 <= m <= 10)
// Line i+1 (i = 1, 2, ..., n): contains m integers which are items of vector A[i] (items are vary from 1 to 100)

// Output
// Line i (i = 1, 2, ..., n): write the items of vector A[i] after sorting (after each item, there is a SPACE character)

// Example
// Input 
// 6 3
// 10 9 7 
// 5 10 2 
// 10 9 1 
// 4 7 3 
// 7 5 10 
// 7 9 3

// Output 
// 4 7 3
// 5 10 2
// 7 5 10
// 7 9 3
// 10 9 1
// 10 9 7

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int length;
} Vector;

void swap(Vector* vt1, Vector* vt2) {
    Vector temp = *vt1;
    *vt1 = *vt2;
    *vt2 = temp;
}

int compare(Vector vt1, Vector vt2) {
    for (int i = 0; i < vt1.length; i++) {
        if (vt1.data[i] != vt2.data[i]) {
            return vt1.data[i] - vt2.data[i];
        }
    }
    return 0;
}

int partition(Vector* arr, int low, int high) {
    Vector pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Vector* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[]){
    int n, m;
    scanf("%d %d", &n, &m);

    Vector* vt = (Vector*)malloc(n * sizeof(Vector));

    for (int i = 0; i < n; i++) {
        vt[i].data = (int*)malloc(m * sizeof(int));
        vt[i].length = m;
        for (int j = 0; j < m; j++) {
            scanf("%d", &vt[i].data[j]);
        }
    }

    quickSort(vt, 0, n - 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", vt[i].data[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(vt[i].data);
    }
    free(vt);

    return 0;
}
