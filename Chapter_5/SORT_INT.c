// Problem: Chapter 5 - Sort a sequence of integers
// Description
// Given a sequence of integers a1, a2,..., an. Sort the sequence in a non-deccreasing order.
// Input
// Line 1: contains an integer n (1 <= n <= 1000000)
// Line 2: a1, a2,..., an. (0 <= ai <= 100000)
// Output
// Write the sorted sequence, elements are separated by a SPACE chharacter.
// Example
// Input
// 4
// 1 3 4 2
// Output
// 1 2 3 4

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int *arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
