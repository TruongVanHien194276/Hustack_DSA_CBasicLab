// Problem: Chapter 6 - Count number of pairs of sequence of distinct integer sum equal to Q
// Description
// Given a sequence of distinct integers a1, a2, …, an and an integer Q. Count number M of pairs (i, j) such that 1 ≤ i< j ≤ n and ai + aj = Q
// Input
// •Line 1: contains two integers nand Q (1 <= n,Q<= 106)
// •Line 2: contains a1, a2, …, an
// Ouput
// •Write the value of M
// Example
// Input
// 5 8
// 4 6 5 3 2
// Output
// 2

#include <stdio.h>
#include <stdlib.h>

int *a;
int count[1000003];

int countPair(int n, int Q) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x = Q - a[i];
        if (x >= 0) {
            cnt += count[x];
        }
        count[a[i]] += 1;
    }
    return cnt;
}

int main(int argc, char const *argv[]){
    int n, Q;
    scanf("%d %d", &n, &Q);
    
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d", countPair(n, Q));

    return 0;
}

