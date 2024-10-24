// Problem: Chapter 6 - Check Existence in a Set
// Description
// Cho dãy số nguyên A1, A2, . . . , An với mỗi số nguyên Ai kiểm tra xem có số Aj nào bằng Ai hay không với j<i.
// Input
// Dòng đầu chứa số n (1≤n≤100,000)
// Dòng hai chứa nn số nguyên A1, A2, ..., An (1≤Ai≤1000,000,000)
// Output
// Ghi ra n dòng, dòng thứ i in ra 1 nếu tồn tại Aj=Ai với j<i, ngược lại in ra 0.
// Example
// input
// 5
// 1 4 3 1 4
// output
// 0
// 0
// 0
// 1
// 1

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 1000003 // prime number 

int hashTable[HASH_SIZE];

int hash(int key){
    return key % HASH_SIZE;
}

int find(int key){
    int h = hash(key);
    while (hashTable[h] != 0){
        if (hashTable[h] == key) return 1;
        h = (h + 1) % HASH_SIZE;
    }
    return 0;
}

void insert(int key){
    int h = hash(key);
    while (hashTable[h] != 0){
        h = (h + 1) % HASH_SIZE;
    }
    hashTable[h] = key;
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);

        if (find(x)) printf("1\n");
        else {
            printf("0\n");
            insert(x);
        }
    }
    
    return 0;
}
