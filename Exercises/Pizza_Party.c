// Description
// Sharing a Pizza Party Budget
// Imagine you and a group of friends are planning a pizza party. You have a total budget of $M, and you want to split the budget into exactly n portions, one for each person, ensuring everyone gets at least $1. You want to find all possible ways to distribute the budget among your friends in a fair manner, listing the possible distributions in lexicographic order.


// Problem Statement:
// Given:


// n friends
// A total budget of $M
// You need to list all possible ways to split the budget such that the sum of all individual portions is exactly $M.


// Example:
// If you have 3 friends and a budget of $5, you need to find all possible sets (X1, X2, X3) such that
// 𝑋1+𝑋2+𝑋3=5
// X1+X2+X3=5.
// Constraints:
// 2 ≤ n ≤ 10 (number of friends)
// 1 ≤ M ≤ 20 (total budget in dollars)
// Output:
// Each line should list a possible distribution of the budget in lexicographic order.

#include <stdio.h>
 
int n, M;
int a[10];
int sum = 0;
 
void print() {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
void TRY(int i, int p) {
    if (i == n-1) {
        a[i] = M - p;
        if (a[i] >= 1) print();
        return;
    }
    for (int j = 1; j <= M - p -(n-i-1); j++) {
        a[i] = j;
        TRY(i + 1, p + j);
    }
}
 
int main() {
    scanf("%d %d", &n, &M);
    TRY(0, 0);
    return 0;
}