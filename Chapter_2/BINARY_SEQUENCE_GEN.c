// Problem: Chapter 2 - Binary sequence generation
// Description
// Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary sequences in a lexicographic ordder, eac sequence in a line

// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

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
    a[i] = 1;
    TRY(i + 1);
}

int main(int argc, char const *argv[]){
    scanf("%d", &n);
    TRY(0);
    return 0;
}