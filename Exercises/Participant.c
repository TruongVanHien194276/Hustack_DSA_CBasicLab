// Description
// Imagine you are organizing a large-scale competition where each participant is identified by a unique code and has a score based on their performance. Your task is to rank all participants in descending order of their scores so that you can display the leaderboard.


// Problem Statement:
// Given a list of participants, where each participant has a unique code (a string of characters with a length from 2 to 10) and a score (an integer from 0 to 1000000). The scores of all participants are different. Write a program to sort participants in descending order of their scores.


// Input Format:
// Each line contains two pieces of information: the code and score of a participant.
// The input data ends with a line containing #.
// Output Format:
// For each participant, print their code and score in the sorted order (descending by score), separated by a space.
// Example:
// Input:
// abc123 45000
// xyz456 95000
// def789 67000
// #
// Output:
// xyz456 95000
// def789 67000
// abc123 45000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[11];
    int score;
} Participant;

void swap(Participant* c1, Participant* c2) {
    Participant temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int partition(Participant arr[], int low, int high) {
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

void quickSort(Participant arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const *argv[]){
    Participant arr[100010];
    int n = 0;

    while (1) {
        scanf("%s", arr[n].code);
        if (arr[n].code[0] == '#') break;

        scanf("%d", &arr[n].score);
        n++;
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].code, arr[i].score);
    }

    return 0;
}

