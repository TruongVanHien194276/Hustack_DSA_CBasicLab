// Problem: Chapter 2 - Permutation generation
// Description
// Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
// Example
// Input 
// 3
// Output
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Permuate(int arr[], int n) {
    printArray(arr, n);
    
    int k;
    while (1) {
        for (k = n - 2; k >= 0; k--) {
            if (arr[k] < arr[k + 1]) break;
        }
        
        if (k == -1) break;
        
        int l;
        for (l = n - 1; l > k; l--) {
            if (arr[k] < arr[l]) break;
        }
        
        swap(&arr[k], &arr[l]);
        
        int i = k + 1;
        int j = n - 1;
        while (i < j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
        
        printArray(arr, n);
    }
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    Permuate(arr, n);
    
    free(arr);
    
    return 0;
}
