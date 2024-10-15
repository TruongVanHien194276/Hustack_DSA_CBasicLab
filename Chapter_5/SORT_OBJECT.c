// Problem: Chapter 5 - Sort candidates of a Contest
// Description
// A candidate of a contest has following information:
// code: string of length from 2 to 10
// score: integer from 0 to 1000000 (scores of candidates are distinct)

// Write a program to sort the list of candidates in non-increasing order of scores.

// Input
// Each line contains the information of a candidate (code and score: separated by a SPACE character)
// The input is terminated by a line containing #

// Ouput
// Write in each line the information of a candidate in the sorted list(code and score separated by a SPACE character)
 
// Example
// Input
// S00001 27412
// S00002 22981
// S00003 32561
// S00004 10915
// S00005 17566
// #

// Output 
// S00003 32561
// S00001 27412
// S00002 22981
// S00005 17566
// S00004 10915

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[11];
    int score;
} Candidate;

void swap(Candidate* c1, Candidate* c2) {
    Candidate temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int partition(Candidate arr[], int low, int high) {
    int pivot = arr[high].score;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].score >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Candidate arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[]){
    Candidate candidates[100010];
    int n = 0;

    while (1) {
        scanf("%s", candidates[n].code);
        if (candidates[n].code[0] == '#') break;

        scanf("%d", &candidates[n].score);
        n++;
    }

    quickSort(candidates, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", candidates[i].code, candidates[i].score);
    }

    return 0;
}

