// Problem: Chapter 2 - Count number of Queen solutions with some specified queens
// Description
// Given a chess board N x N on which there are K being placed in some cells. Compute the number of solutions to place other N - K queens in other cells such that among N queens on the board, no two queens attack each other.
// A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.

// Input
// Line 1: contains a positive integer N (1 <= N <= 12)
// Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
// Output
// Write the number of solutions

// Example
// Input 
// 4
// 0 1 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 1 0
// Output
// 1


// Input 
// 5
// 0 1 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// Output 
// 2

#include <stdio.h>

int n, a[12][12];
int cnt = 0;
int row[12], col[12], diag1[24], diag2[24];

void TRY(int i) {
    if (row[i]){
        if (i == n - 1) cnt += 1;
        else TRY(i + 1);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!row[i] && !col[j] && !diag1[i + j] && !diag2[i - j + n - 1]) {
            if (i == n - 1) cnt += 1;
            else {
                row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = 1;
                TRY(i + 1);
                row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = 0;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                row[i] = col[j] = diag1[i + j] = diag2[i - j + n - 1] = 1;
            }
        }
    }

    TRY(0);
    printf("%d\n", cnt);
    return 0;
}