// Problem: Chapter 1 - Sum Array
// Description
// Given a sequence of integers a1, a2, ..., an. Compute the sum Q of elements of this sequence.
// Input
// Line 1: contains n (1 <= n <= 1000000)
// Line 2: contains a1, a2, ..., an (-10000 <= ai <= 10000)
// Output
// Write the value of Q
// Example
// Input
// 4
// 3 2 5 4
// Output
// 14

#include <stdio.h>

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        sum += a;
    }

    printf("%d", sum);
    return 0;
}