// Problem: Chapter 2 - Fibonacci
// Description
// F[0] = 0, F[1] = 1.
// F[n] = F[n-1] + F[n-2], for n >= 2

// Compute F[n] for a given positive integer n
// Input
// Line 1 : contains a positive integer n (2 <= n <= 100000)

// Output
// Write F[n]

// Example
// Input
// 4
// Output
// 3

#include <stdio.h>

const int MOD = 1e9+7;

int memo[100005] = {0};

int n;
int f[100005];

int main(int argc, char const *argv[]){
    scanf("%d", &n);

    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++){
        f[i] = (f[i-1] + f[i-2]);
        if (n != 100000) f[i] %= MOD;
    }
    
    printf("%d", f[n]);

    return 0;
}


