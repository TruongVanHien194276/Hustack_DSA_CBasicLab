// Problem: Chapter 2 - TSP
// Description
// There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
// Input
// Line 1: a positive integer n (1 <= n <= 20)
// Linr i+1 (i = 1, . . ., n): contains the i-th row of the distance matrix x (elements are separated by a SPACE character)
// Output
// Write the total travel distance of the optimal itinerary found.
// Example
// Input
// 4
// 0 1 1 9
// 1 0 9 3
// 1 9 0 2
// 9 3 2 0
// Output
// 7

#include <stdio.h>

const int INF = 1e9;
const int MAX = 20;
const int flag = 1;

int n;
int c[MAX][MAX];
int dp[MAX][1 << MAX];

int TSP(int pos, int visited) {
    if (visited == (flag << n) - 1) {
        return c[pos][0] ? c[pos][0] : INF;
    }

    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }

    int res = INF;
    for (int i = 0; i < n; i++) {
        if (c[pos][i] == 0 || (visited & (flag << i))) continue;
        int min = c[pos][i] + TSP(i, visited | (flag << i));
        res = (res < min) ? res : min;
    }

    return dp[pos][visited] = res;
}

int main(int argc, char const *argv[]){
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++) {
            dp[i][j] = -1;
        }
    }

    printf("%d", TSP(0, 1));
    return 0;
}