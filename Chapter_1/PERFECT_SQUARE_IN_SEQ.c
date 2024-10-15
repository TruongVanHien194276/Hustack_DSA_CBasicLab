// Problem: Chapter 1 - Find all perfect square in a sequence
// Description
// Given a sequence of n integers a1, a2, . . ., an. Compute the number Q of perfect squares (the number of type a^2) of that sequence.
// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Linw 2: contains n positive integer a1, a2, . . ., an (1 <= ai <= 1000000)

// Output
// Write the value Q

// Example
// Input
// 5
// 3 2 4 7 9

// Output
// 2

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);

    int cnt = 0;
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (sqrt(a[i]) == (int)sqrt(a[i])) cnt += 1;
    }

    printf("%d", cnt);
    return 0;
}
