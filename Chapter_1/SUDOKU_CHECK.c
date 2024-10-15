// Problem: Chapter 1 - Check Sudoku
// Description
// A matrix 9 x 9 is called a sudoku solution if it satisfies following constraints
// Each element is an integer from 1 to 9
// Elements on each row are distinct
// Elements on each column are distinct
// Elements on each sub-square 3x3 are distinct (the matrix is divided into 9 distinct subsquares of size 3x3) 

// Write a program that checks whether or not a given matrix is a sudoku solution 
// Input
// Line 1: contains a positive integer T which is the number of matrix 9x9
// Subsequent lines are blocks, each block contains a matrix 9x9 with the following format
// Line i (i = 1, 2, ..., 9) contains the i
// th
//  line of the matrix

// Output
// Contains T lines, each line i (i = 1, 2, ..., T) contains 1 if the ith matrix is a sudoku solution, and contains 0, otherwise

// Example
// Input
// 2
// 1 2 3 4 5 6 7 8 9 
// 4 5 6 7 8 9 1 2 3 
// 7 8 9 1 2 3 4 5 6 
// 2 1 4 3 6 5 8 9 7 
// 3 6 5 8 9 7 2 1 4 
// 8 9 7 2 1 4 3 6 5 
// 5 3 1 6 7 8 9 4 2 
// 9 7 2 5 4 1 6 3 8 
// 6 4 8 9 3 2 5 7 1 
// 1 2 3 4 5 6 7 8 9 
// 4 5 6 7 8 9 1 2 3 
// 7 8 9 1 2 3 4 5 6 
// 2 1 4 3 6 5 8 9 7 
// 3 6 5 8 9 7 2 1 4 
// 8 9 7 2 1 4 3 6 5 
// 5 3 1 6 7 8 9 4 2 
// 9 7 8 5 4 2 6 3 1 
// 4 4 2 9 3 1 5 7 8 

// Output
// 1
// 0


#include <stdio.h>

#define N 9

int isValid(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return 0;
        }
    }
    return 1;
}

int isSudokuSolution(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        int rowCheck[N] = {0};
        int colCheck[N] = {0};
        for (int j = 0; j < N; j++) {
            // Check row
            if (grid[i][j] < 1 || grid[i][j] > 9 || rowCheck[grid[i][j] - 1]) {
                return 0;
            }
            rowCheck[grid[i][j] - 1] = 1;

            // Check column
            if (grid[j][i] < 1 || grid[j][i] > 9 || colCheck[grid[j][i] - 1]) {
                return 0;
            }
            colCheck[grid[j][i] - 1] = 1;
        }
    }

    // Check each 3x3 subgrid
    for (int i = 0; i < N; i += 3) {
        for (int j = 0; j < N; j += 3) {
            int subgridCheck[N] = {0};
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    if (grid[k][l] < 1 || grid[k][l] > 9 || subgridCheck[grid[k][l] - 1]) {
                        return 0;
                    }
                    subgridCheck[grid[k][l] - 1] = 1;
                }
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[]){
    int T;
    scanf("%d", &T); 
    
    while (T--) {
        int grid[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        
        if (isSudokuSolution(grid)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    
    return 0;
}

