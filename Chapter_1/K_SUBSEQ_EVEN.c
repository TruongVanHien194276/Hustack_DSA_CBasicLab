// Problem: Chapter 1 - k-Subsequence even
// Description
// Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
// Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
// Input
// Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
// Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
// Output
// Write the value Q
// Example
// Input
// 6  3
// 2 4 5 1 1 2 
// Output
// 2

#include <stdio.h>

const int MAX_N = 100000;

int main(int argc, char const *argv[]){
    int n, k;
    int a[MAX_N], prefix[MAX_N];

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        prefix[i] = (i > 0 ? prefix[i - 1] : 0) + a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n - k + 1; i++) {
        int sum = prefix[i + k - 1] - (i > 0 ? prefix[i - 1] : 0);
        if (sum % 2 == 0) cnt += 1;
    }

    printf("%d", cnt);

    return 0;
}