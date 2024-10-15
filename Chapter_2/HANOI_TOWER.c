// Problem: Chapter 2 - Hanoi Tower
// Description
// Given n disks of different radiuss and 3 piles A, B, C. Find the way to move n disks from pile A to pile B (use pile C as an intermediate pile):
// Each step move only 1 disk on top of a pile to the top of another pile 
// Situation that "smaller disk is under a larger disk on a pile" is forbidden

// Input
// One line contains 4 positive integers n, A, B, C (1 <= n <= 20, 1 <= A, B, C <= 100)

// Output
// Line 1: contains a positive integer m which is the number of steps
// Line i+1 (i = 1, 2, ..., m): contains 2 positive integers X and Y: move a disk from pile X to pile Y

// Example
// Input 
// 2 10 20 30

// Output
// 3
// 10 30
// 10 20
// 30 20

#include <stdio.h>
#include <string.h>

void hanoi(int n, int A, int B, int C){
    if (n == 1){
        printf("%d %d\n", A, B);
        return;
    }
    hanoi(n-1, A, C, B);
    printf("%d %d\n", A, B);
    hanoi(n-1, C, B, A);
}

int main(int argc, char const *argv[]){
    int n, A, B, C;
    scanf("%d %d %d %d", &n, &A, &B, &C);
    
    printf("%d\n", (1<<n) - 1);  // 2^n - 1
    hanoi(n, A, B, C);

    return 0;
}