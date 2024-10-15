// Problem: Chapter 6 - Store & Search String
// Description
// A database contains a sequence of key k1, k2, ..., kn which are strings (1<=n<=100000). Perform a sequence of actions of two kinds:
// · find k: find and return 1 if k exists in the database, and return 0, otherwise
// · insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
// Note that the length of any key is greater than 0 and less than or equal to 50.
// Input
// Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = find or insert and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
// Output
// Each line contains the result (0 or 1) of the corresponding action.
// Example
// Input
// computer
// university
// school
// technology
// phone
// *
// find school
// find book
// insert book
// find algorithm
// find book
// insert book
// ***
// Output
// 1
// 0
// 1
// 0
// 1
// 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define MAX_LENGTH 51
#define HASH_SIZE 100003 // prime number 

typedef struct Node {
    char key[MAX_LENGTH];
    struct Node* next;
} Node;

// hash function
unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c 
    }

    return hash % HASH_SIZE;
}

Node* hash_table[HASH_SIZE];

int find_key(char* key) {
    unsigned long index = hash(key);
    Node* cur = hash_table[index];
    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) return 1;
        cur = cur->next;
    }
    return 0; 
}

int insert_key(char* key){
    if (find_key(key)) return 0; // key exists
    else {
        unsigned long index = hash(key);
        Node* newNode = (Node*)malloc(sizeof(Node));
        strcpy(newNode->key, key);
        newNode->next = hash_table[index];
        hash_table[index] = newNode;
        return 1;  // insert successfully
    }
}

int main(int argc, char const *argv[]){
    for (int i = 0; i < HASH_SIZE; i++) {
        hash_table[i] = NULL;
    }

    int n = 0;
    char key[MAX_LENGTH];
    while (1) {
        scanf("%s", key);
        if (strcmp(key, "*") == 0) break;
        insert_key(key);
        n++;
    }

    char cmd[MAX_LENGTH];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;

        scanf("%s", key);

        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", find_key(key));
        } else if (strcmp(cmd, "insert") == 0) {
            printf("%d\n", insert_key(key));
        }
    }

    // free memory
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = hash_table[i];
        while (cur != NULL) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }

    return 0;
}
