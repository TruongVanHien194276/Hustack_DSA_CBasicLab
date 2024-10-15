// Problem: Chapter 1 - Check Queen solution
// Description
// Given a chess board N x N on which there are N being placed in N different cells. 
// Write a program that check if there are two queen, that attacks each other.

// A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.
// Input
// Line 1: contains a positive integer T which is the number of test-cases (1 <= T <= 100)
// T following block, each block is the input of a test-case with the format:
// Line 1: contains a positive integer N (1 <= N <= 100)
// Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
// Output
// In each line t (t = 1, 2, ..., T), write 1 if in the test-case t, there are no two queen that attack each other, and write 0, otherwise 
// Example
// Input
// 2
// 4
// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0
// 4
// 0 1 0 0
// 0 0 0 0
// 1 0 0 1
// 0 0 1 0
// Output
// 1
// 0

#include<stdio.h>

const int MAX_N = 100;

int checkQueens(int board[MAX_N][MAX_N], int N) {
    int i, j, k, l;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                for (k = 0; k < N; k++) {
                    if (k != j && board[i][k] == 1) {
                        return 0; 
                    }
                }

                for (l = 0; l < N; l++) {
                    if (l != i && board[l][j] == 1) {
                        return 0;
                    }
                }
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                for (k = i - 1, l = j - 1; k >= 0 && l >= 0; k--, l--) {
                    if (board[k][l] == 1) {
                        return 0; 
                    }
                }

                for (k = i - 1, l = j + 1; k >= 0 && l < N; k--, l++) {
                    if (board[k][l] == 1) {
                        return 0;
                    }
                }

                for (k = i + 1, l = j - 1; k < N && l >= 0; k++, l--) {
                    if (board[k][l] == 1) {
                        return 0; 
                    }
                }

                for (k = i + 1, l = j + 1; k < N && l < N; k++, l++) {
                    if (board[k][l] == 1) {
                        return 0; 
                    }
                }
            }
        }
    }

    return 1; 
}

int main(int argc, char const *argv[]){
    int board[MAX_N][MAX_N];
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        if (checkQueens(board, N)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}