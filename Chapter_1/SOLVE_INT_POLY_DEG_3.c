// Problem: Chapter 1 - Find integer solutions to Polynomial Degree 3
// Description
// Given 3 integers a, b, c (c != 0). Write a program that find distinct integers solution s1, s2, . . ., sk) such that x^3 + ax^2 + bx + c 
// can be rewritten under the form (x-s1)^m1 (x-s2)^m2 . . . (x-sk)^mk   
// in which m1, m2,  . . ., mk are call multipliers.

// Input
// Line 1 contains 3 integers a, b, c (-10000000 <= a, b, c <= 10000000)
// Output
// In case that no solution found, then write NO SOLUTION to stdout. Otherwise, write the solution under the format: 
// s1 m1
// s2 m2
// s3 m3
// . . .
// in which s1, s2, s3, ... are solution sorted in an increasing order and m1, m2, m3, ... are respectively the multipliers of s1, s2, s3, ...

// Example
// Input
// -1  -1  -2
// Output
// NO SOLUTION

// Input 
// -6 11 -6
// Output 
// 1 1
// 2 1
// 3 1

// Input 
// 8  5  -50
// Output 
// -5  2
// 2   1

#include <stdio.h>
#include <stdlib.h>

int a, b, c;

int f(int x){
    return x*x*x + a*x*x + b*x + c;
}

int main(int argc, char const *argv[]){
    int i = 0;
    int e[3];
    scanf("%d%d%d", &a, &b, &c);

    for (int x = 1; x <= abs(c)/2; x++){
        if (c % x == 0){
            if (f(x) == 0){
                e[i] = x; 
                i++;
            } else if(f(-x) == 0){
                e[i] = -x;
                i++;
            }
        }
        if (i > 3) break;
    }

    for (int j = 0; j < i-1; j++){
        for (int k= j+1; k < i; k++){
            if (e[j] > e[k]){
                int tmp = e[j];
                e[j] = e[k];
                e[k] = tmp;
            }
        }
    }

    switch(i){
        case 0: 
            printf("NO SOLUTION"); 
            break;
        case 1: 
            printf("%d 3", e[0]);
            break;
        case 2:
            if (e[0]*e[0]*e[1] == -c) printf("%d 2\n%d 1", e[0], e[1]);
            else printf("%d 1\n%d 2", e[0], e[1]);
            break;
        case 3: 
            printf("%d 1\n%d 1\n%d 1", e[0], e[1], e[2]); 
            break;
    }
    
    return 0;
}