// Problem: Chapter 5 - Sort Strings
// Description
// Given a sequence of strings S1, S2, . . ., Sn. Sort the given sequence in non-decreasing order.

// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line i+1 (i = 1, 2, ..., n): contains Si

// Output
// Write in each line a string in the sorted sequence 

// Example
// Input 
// 10
// O0001
// Z002
// R003
// R00004
// P05
// P00006
// T0007
// X08
// N09
// I010

// Output 
// I010
// N09
// O0001
// P00006
// P05
// R00004
// R003
// T0007
// X08
// Z002

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(char **arr, int left, int right) {
    if (left >= right) return;

    char *pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (strcmp(arr[i], pivot) < 0) i++;
        while (strcmp(arr[j], pivot) > 0) j--;
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

    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", arr[i]);
    }

    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    
    return 0;
}