// Problem: Chapter 2 - Convert integer to binary string
// Description
// Given a positive integer N, write a program that converts N into a binary string (ignore left-most bit 0).

// Input
// Line 1:contains a positive integer N(0 <= N <= 20000000)

// Output
// Write the binary string representing N

// Example
// Input 
// 20

// Output 
// 10100

#include <stdio.h>

void convertToBinary(int n){
    if (n == 0) return;
    convertToBinary(n / 2);
    printf("%d", n % 2);
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);

    if (n == 0) printf("0");
    else convertToBinary(n);

    return 0;
}