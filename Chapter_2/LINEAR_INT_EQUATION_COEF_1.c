// Problem: Chapter 2 - Linear Integer Equation - coefficent 1
// Description
// Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M
// Input
// Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)
// Output
// Write in each line X1, X2, ..., Xn separated by a SPACE character
// Example
// Input
// 3  5
// Output
// 1 1 3
// 1 2 2
// 1 3 1
// 2 1 2
// 2 2 1
// 3 1 1

#include <stdio.h>

int n, M;
int a[10];

void Print() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void TRY(int i) {
    for (int j = 1; j <= M; j++) {
        a[i] = j;
        M -= j;
        if (i == n) {
            if (M == 0) Print();
        } else {
            TRY(i + 1);
        }
        M += j;
    }
}

int main(int argc, char const *argv[]){   
    scanf("%d%d", &n, &M);
    TRY(1);
    return 0;
}