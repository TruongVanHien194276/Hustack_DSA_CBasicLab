// Problem: Chapter 2- Subset sum of elements equal to B
// Description
// Given a sequence of n integers a1, a2, ..., an, and a positive integer b. Compute the number Q of way to select some elements from the given sequence such that the sum of selected elements is equal to b.
// Input
// Line 1: contains 2 integers n and b (1 <= n <= 50, 1 <= b <= 100)
// Line 2: contains n positive integer a1, a2, ..., an (1 <= ai <= 100)
// Output
// Write the value Q

// Example
// Input 
// 5 6
// 1 2 3 4 5
// Output
// 3

#include <stdio.h>

int n, b;
int a[50];
int dp[51][10001];

int counting(int i, int sum) {
    if (sum > b) return 0;
    if (i == n) return sum == b;
    if (dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = counting(i + 1, sum) + counting(i + 1, sum + a[i]);
}

int main(int argc, char const *argv[]){
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= b; j++) {
            dp[i][j] = -1;
        }
    }

    printf("%d", counting(0, 0));
    return 0;
}