// Problem: Chapter 1 - Black colums of 0-1 matrix
// Description
// Given a 0-1 matrix of size n (n rows and n columns). Compute the number Q of columns of the given matrix in which all the element of the column are 1.

// Input
// Line 1: contains a positive integer n (1 <= n <= 1000)
// Line i+1 (i = 1,...,n): contains the ith row of the given matrix

// Output
// Write the value Q

// Example
// Input
// 5
// 1 1 1 1 1 
// 1 1 1 1 0 
// 1 0 1 1 1 
// 1 1 1 1 1 
// 1 0 1 1 0 

// Output 
// 3

#include <stdio.h>

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    int A[n][n];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (A[i][j] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) cnt += 1;
    }
    printf("%d", cnt);
    return 0;
}