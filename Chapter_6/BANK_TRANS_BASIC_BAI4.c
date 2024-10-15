// Problem: Chapter 6 - BANK - Query Total transaction from
// Description
// The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
// <from_account>   <to_account>   <money>   <time_point>   <atm>
// In which:
// •	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
// •	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
// •	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
// •	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
// •	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
// Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds)
// A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
// Write a program that process the following queries:
// ?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>
// Input (stdin)
// The input consists of 2 blocks of information: the data block and the query block
// •	The data block consists of lines:
// o	Each line contains the information about a transaction described above
// o	The data is terminated by a line containing #
// •	The query block consists of lines:
// o	Each line is a query described above
// o	The query block is terminated by a line containing #
// Output (stdout)
// •	Print to stdout (in each line) the result of each query described above
// Example
// Input
// T000010010 T000010020 1000 10:20:30 ATM1
// T000010010 T000010030 2000 10:02:30 ATM2
// T000010010 T000010040 1500 09:23:30 ATM1
// T000010020 T000010030 3000 08:20:31 ATM1
// T000010030 T000010010 4000 12:40:00 ATM2
// T000010040 T000010010 2000 10:30:00 ATM1
// T000010020 T000010040 3000 08:20:31 ATM1
// T000010040 T000010030 2000 11:30:00 ATM1
// T000010040 T000010030 1000 18:30:00 ATM1
// #
// ?total_money_transaction_from T000010010
// ?total_money_transaction_from T000010030
// #
// Output
// 4500
// 4000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100003 // Prime number 
#define MAX_LENGTH 100

typedef struct {
    char from_account[21];
    char to_account[21];
    int money;
    char time_point[9];
    char atm[11];
} Transaction;

typedef struct Node {
    Transaction transaction;
    struct Node* next;
} Node;

typedef struct {
    Node* table[HASH_SIZE];
} HashTable;

// hash function
unsigned long hash(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c 
    }
    return hash % HASH_SIZE;
}

void insert(HashTable* ht, Transaction t) {
    unsigned long index = hash(t.from_account);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);

    newNode->transaction = t;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int totalMoney(HashTable* ht, char* account) {
    unsigned long index = hash(account);
    int total_money = 0;
    Node* cur = ht->table[index];
    while (cur != NULL) {
        if (strcmp(cur->transaction.from_account, account) == 0) {
            total_money += cur->transaction.money;
        }
        cur = cur->next;
    }
    return total_money;
}

int main(int argc, char const *argv[]){
    HashTable ht = {{NULL}}; 
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '#') break;
        Transaction t;
        sscanf(line, "%s %s %d %s %s", t.from_account, t.to_account, &t.money, t.time_point, t.atm);
        insert(&ht, t);
    }

    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '#')
            break;
        if (line[0] == '?') {
            char account[21];
            sscanf(line, "?total_money_transaction_from %s", account);
            printf("%d\n", totalMoney(&ht, account));
        }
    }

    // free memory
    for (int i = 0; i < HASH_SIZE; ++i) {
        Node* cur = ht.table[i];
        while (cur != NULL) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }

    return 0;
}
