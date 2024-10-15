// Problem: Chapter 1 - Array Equality
// Description
// Given two sequence a=a1,..,an and b=b1,...,bm. Check if these sequences are equal.
// Input
// Line 1: contains a positive integer T (1≤T≤10^2) represents number of tests
// Follow are T tests, each of which has the following format
// Line 1: n and m (1≤n,m≤1000)
// Line 2: a=a1,..,an
// Line 3: b=b1,...,bm


// Output
// Write to stdout T lines, each line t contains 1 if the sequences of the t-th test are equal, and write 0, otherwise.
// Example
// Input
// 3
// 3 3
// 1 2 3
// 1 2 3
// 4 2
// 1 2 3 4
// 1 2
// 3 3
// 2 4 1
// 2 3 1
// Output
// 1
// 0
// 0

#include<stdio.h>

int main(int argc, char const *argv[]){
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++){
        int n, m;
        scanf("%d%d", &n, &m);

        int a[n], b[m];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%d", &b[i]);

        if (n != m){
            printf("0\n");
            continue;
        }

        int equal = 1;
        for (int i = 0; i < n; i++){
            if (a[i] != b[i]){
                equal = 0;
                break;
            }
        }
        printf("%d\n", equal);
    }
    return 0;
}