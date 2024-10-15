// Problem: Chapter 1 - Multiplication of 2 matrices
// Description
// Given two matrices A_nxk and B_kxm. Each element of the two matrices are integers from 1 to 50. Compute the product matrix C = A x B.
 
// Input
// Line 1 contains two positive integers n and k (1 <= n, k <= 100)
// Line i+1 (i = 1,2, ..., n): contains the i-th row of A (elements are separated by a SPACE character)
// Line n+2: contains two positive integers k and m (1 <= k,m <= 100)
// Line i+n+2 (i= 1, 2, ..., k): contains the i-th row of B (elements are separated by a SPACE character)

// Output
// Line i (i = 1,...,n) contains the i-th row of the resulting matrix (elements are separated by a SPACE character)

// Example
// Input
// 2 3
// 1 2 3
// 4 5 6
// 3 4
// 1 1 1 1
// 2 2 2 2
// 3 3 3 3

// Output
// 14 14 14 14
// 32 32 32 32

#include <stdio.h>

int n, k, m;
int A[100][100], B[100][100], C[100][100];

int main(int argc, char const *argv[]){
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    scanf("%d %d", &k, &m);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
            for (int t = 0; t < k; t++) {
                C[i][j] += A[i][t] * B[t][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
