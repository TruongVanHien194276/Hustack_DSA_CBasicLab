// Problem: Chapter 2 - Greatest Common Divisor
// Description
// Given 2 positive integers a and b. Compute the greatest common divisor of a and b.
// Input
// Line 1 contains 2 integers a, b (1 <= a, b <= 100000)
// Output
// Write the greatest common divisor of a and b.

// Example
// Input 
// 16 24

// Output 
// 8

#include <stdio.h>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[]){
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", gcd(a, b));

    return 0;
}