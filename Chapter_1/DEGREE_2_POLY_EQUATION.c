// Problem: Chapter 1 - Solve degree-2 polynomial equation
// Description
// Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
// Input
// Line 1 contains 3 integers a, b, c 
// Output
// Write NO SOLUTION if the given equation has no solution 
// Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
// Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 

// Example
// Input 
// 1 1 8
// Output 
// NO SOLUTION 


// Input 
// 1 -2 1
// Output
// 1.00

// Input 
// 1 -7 10
// Output 
// 2.00 5.00

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("NO SOLUTION");
            } else {
                printf("NO SOLUTION");
            }
        } else {
            printf("%.2f", (float)-c / b);
        }
    } else {
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("NO SOLUTION");
        } else if (delta == 0) {
            printf("%.2f", (float)-b / (2 * a));
        } else {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            if (x1 > x2) {
                float tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            printf("%.2f %.2f", x1, x2);
        }
    }
    return 0;
}