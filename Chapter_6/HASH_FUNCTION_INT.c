// Problem: Chapter 6 - Hash Over Integers
// Description
// A database contains a sequence of key k1, k2, ..., kn which are integers (1<=n<=100000). Perform a sequence of actions of two kinds:
// · find k: find and return 1 if k exists in the database, and return 0, otherwise
// · insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
// Note that the value of any key is greater than or equal to 0 and less than or equal to 10
// 17
// .
// Input
// Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = "find" or "insert" and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
// Output
// Each line contains the result (0 or 1) of the corresponding action.
// Example
// Input
// 4
// 5
// 2
// *
// find 3
// insert 4
// find 2
// insert 3
// find 3
// ***
// Output
// 0
// 0
// 1
// 1
// 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE  1000003 // prime number

typedef struct Node{
    char key[20];
    struct Node *next;
} Node;

Node *hashTable[HASH_SIZE] = {NULL};

int hash(char *key){
    unsigned long hash = 5381;
    int c;

    while(c = *key++){
        hash = ((hash << 5) + hash) + c;
    }

    return hash % HASH_SIZE;
}

Node *createNode(char *key){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->next = NULL;
    return newNode;
}

int find(char *key){
    int h = hash(key);
    Node *cur = hashTable[h];

    while(cur != NULL){
        if(strcmp(cur->key, key) == 0){
            return 1;
        }
        cur = cur->next;
    }

    return 0;
}

int insert(char *key){
    if (find(key) == 1){
        return 0;
    } else {
        int h = hash(key);
        Node *newNode = createNode(key);
        newNode->next = hashTable[h];
        hashTable[h] = newNode;
        return 1;
    }
}

int main(int argc, char const *argv[]){
    char key[20];
    while(scanf("%s", key) != EOF){
        if(strcmp(key, "*") == 0) break;
        insert(key);
    }

    char cmd[10];
    while(scanf("%s", cmd) != EOF){
        if (strcmp(cmd, "***") == 0) break;

        scanf("%s", key);
        if(strcmp(cmd, "find") == 0){
            printf("%d\n", find(key));
        } else if(strcmp(cmd, "insert") == 0){
            printf("%d\n", insert(key));
        }
    }
    
    return 0;
}
