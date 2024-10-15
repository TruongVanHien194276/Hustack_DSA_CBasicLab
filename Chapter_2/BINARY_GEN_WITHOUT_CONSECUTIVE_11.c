// Problem: Chapter 2 - Binary sequences generation without consecutive 11
// Description
// Given an integer n, write a program that TRYs all binary sequences without consecutive 11 in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary sequences in a lexicographic order, each sequence in a line
// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 100
// 101

#include <stdio.h>

int n;
int a[20];

void print(){
    for (int i = 0; i < n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

void TRY(int i){
    if (i == n){
        print();
        return;
    }

    a[i] = 0;
    TRY(i + 1);
    if (i == 0 || a[i - 1] == 0){
        a[i] = 1;
        TRY(i + 1);
    }
}

int main(int argc, char const *argv[]){
    scanf("%d", &n);
    TRY(0);
    return 0;
}
