// Problem: Chapter 5 - Max Cardinality Common Subset of 2 Sets
// Description
// Given 2 sets of integers A = {a1, a2, . . ., an} and B = {b1, b2, . . ., bn}. Find the common subset of A and B having highest cardinality.
// Input
// Line 1 contains 2 positive integers n and m (1 <= n,m <= 100000)
// Line 2: contains n positive integers a1, a2, . . ., an (1 <= ai <= 1000000)
// Line 3: contains m positive integers b1, b2, . . ., bm (1 <= ai <= 1000000)

// Output
// Write the cardinalnity of the subset found.

// Example
// Input
// 6 6
// 7 3 10 1 2 8 
// 6 2 8 10 5 7 

// Output 
// 4

// Explanation. The max-cardinality common subset of A and B is {2, 8, 10, 7}

#include <stdio.h>
#include <stdlib.h>

int SOLVE(int n, int m, int A[], int B[]) {
    int *set_A = (int*)calloc(1000001, sizeof(int));
    int max_card = 0;

    for (int i = 0; i < n; i++) {
        set_A[A[i]] = 1;
    }

    for (int i = 0; i < m; i++) {
        if (set_A[B[i]] == 1) {
            max_card++;
        }
    }

    free(set_A);

    return max_card;
}

int main(int argc, char const *argv[]){
    int n, m;
    scanf("%d %d", &n, &m);

    int *A = (int*)malloc(n * sizeof(int));
    int *B = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);
    }

    printf("%d", SOLVE(n, m, A, B));

    free(A);
    free(B);

    return 0;
}
