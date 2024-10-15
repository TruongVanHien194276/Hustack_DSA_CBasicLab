// Problem: Chapter 1 - Basic queries on array
// Description
// Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
// find-max: return the maximum element of the given sequence
// find-min: return the minimum element of the given sequence 
// sum: return the sum of the elements of the given sequence 
// find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

// Input
// The first block contains the information about the given sequence with the following format:
// Line 1: contains a positive integer n (1 <= n <= 10000)
// Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
// The first block is terminated by a character *
// The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

// Output
// Write the result of each query in a corresponding line
 
// Example
// Input
// 5
// 1 4 3 2 5
// *
// find-max
// find-min
// find-max-segment 1 3
// find-max-segment 2 5
// sum
// ***

// Output
// 5
// 1
// 4
// 5
// 15

#include <stdio.h>
#include <string.h>

int n;
int arr[10000];

int find_max(){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int find_min(){
    int min = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int find_max_segment(int i, int j){
    int max = arr[i];
    for (int k = i; k <= j; k++){
        if (arr[k] > max) max = arr[k];
    }
    return max;
}

int find_sum(){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char const *argv[]){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    char s[20];
    while (1){
        scanf("%s", s);
        if (strcmp(s, "*") == 0) continue;
        else if (strcmp(s, "find-max") == 0){
            printf("%d\n", find_max());
        }
        else if (strcmp(s, "find-min") == 0){
            printf("%d\n", find_min());
        }
        else if (strcmp(s, "find-max-segment") == 0){
            int i, j;
            scanf("%d %d", &i, &j);
            printf("%d\n", find_max_segment(i-1, j-1));
        }
        else if (strcmp(s, "sum") == 0){
            printf("%d\n", find_sum());
        }
        else if (strcmp(s, "***") == 0){
            break;
        }
    }
    return 0;
}
