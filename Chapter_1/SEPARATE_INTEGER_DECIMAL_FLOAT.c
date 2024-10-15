// Problem: Chapter 1 - Separate the integer and decimal parts of a float
// Description
// Given a float number A, the integer part I is defined to be the largest integer that is less than or equal to A, and the decimal part D is defined to be A - I. Compute the integer and decimal parts of A.
// Input
// The float number A
// Output
// Write the integer and decimal parts of A (separated by a SPACE character) (the decimal part is written with 2 digits after the decimal point)

// Example
// Input 
// 2.57902
// Output 
// 2 0.58

// Input 
// -4.3456
// Output 
// -5 0.65 

#include <stdio.h>

int main(int argc, char const *argv[]){
    float A;
    scanf("%f", &A);

    int I;
    if (A >= 0){
        I = (int) A;
    } else {
        I = (int)A - 1;
    }
    float D = A - I;

    printf("%d %.2f", I, D);
    return 0;
}