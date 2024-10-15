// Problem: Chapter 5 - Classification of students based on grades
// Description
// Given the profiles of n students, each profile has the following information:
// studentID: string (length from 1 to 10) representing the student identifier (id)
// totalGrade: int (grades of students are distinct)
// Compute the position of each student based on the total grade (the number of students having smaller grades).

// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line i+1 (i = 1, 2, ..., n): contains a string <studentID> and a positive integer <grade> in which <grade> is the total grade of student <studentID>

// Output
// Each line is the student id and his position (sorted by student id)

// Example
// Input
// 5
// S000003 3
// S000002 6
// S000005 5
// S000004 10
// S000001 8

// Output 
// S000001 3
// S000002 2
// S000003 0
// S000004 4
// S000005 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Std{
    char id[10];
    int grade;
    int position;
} Std;

Std* createStudent(char id[], int grade){
    Std *std = (Std *)malloc(sizeof(Std));
    strcpy(std->id, id);
    std->grade = grade;
    std->position = 0;
    return std;
}

void swap(Std *std1, Std *std2){
    Std temp = *std1;
    *std1 = *std2;
    *std2 = temp;
}

void quickSortGrade(Std *std, int left, int right){
    if(left >= right) return;

    int i = left;
    int j = right;
    int pivot = std[(left + right) / 2].grade;

    while (i <= j){
        while (std[i].grade < pivot) i++;
        while (std[j].grade > pivot) j--;
        if (i <= j){
            swap(&std[i], &std[j]);
            i++;
            j--;
        }
    }

    quickSortGrade(std, left, j);
    quickSortGrade(std, i, right);
}

void quickSortId(Std *std, int left, int right) {
    if (left >= right) return;

    Std pivot = std[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (strcmp(std[i].id, pivot.id) < 0) i++;
        while (strcmp(std[j].id, pivot.id) > 0) j--;
        if (i <= j) {
            swap(&std[i], &std[j]);
            i++;
            j--;
        }
    }

    quickSortId(std, left, j);
    quickSortId(std, i, right);
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    Std *std = (Std *)malloc(n * sizeof(Std));
    for (int i = 0; i < n; i++){
        char id[10];
        int grade;
        scanf("%s %d", id, &grade);
        std[i] = *createStudent(id, grade);
    }

    quickSortGrade(std, 0, n - 1);

    // compute position
    for (int i = 0; i < n; i++){
        std[i].position = i;
    }

    quickSortId(std, 0, n - 1);

    for (int i = 0; i < n; i++){
        printf("%s %d\n", std[i].id, std[i].position);
    }
    
    free(std);
    return 0;
}

