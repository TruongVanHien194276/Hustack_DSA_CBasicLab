// Problem: Chapter 6 - Word Frequency in Text
// Description
// Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
// Write a program to frequent the number of occurrences o(w) of each word w of the given TEXT.
// Input
// The TEXT (each word of the TEXT has length <= 20)

// Output
// Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

// Example
// Input
// abc  def abc 
// abc abcd def 

// Output 
// abc 3
// abcd 1
// def 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
    char key[15];
    int frequent;
    struct node* left;
    struct node* right;
} Node;

Node* root = NULL;

Node *createNode(char *key){
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->key, key);
    p->frequent = 1;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node *insertNode(Node *r, char *key){
    if (r == NULL) return createNode(key);
    if (strcmp(r->key, key) == 0){
        r->frequent += 1;
        return r;
    }
    if (strcmp(r->key, key) > 0) r->left = insertNode(r->left, key);
    else r->right = insertNode(r->right, key);
    return r;
}

void inOrder(Node *r){
    if (r == NULL) return;
    inOrder(r->left);
    printf("%s %d\n", r->key, r->frequent);
    inOrder(r->right);
}

void Word_Frequency(char *text){
    int j = -1;
    char word[21];
    for (int i = 0; i < strlen(text); i++){
        if (isalpha(text[i]) || isdigit(text[i])){
            j++;
            word[j] = text[i];
        } else{
            if (j != -1){
                word[j + 1] = '\0';
                root = insertNode(root, word);
                j = -1;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    char text[1000];
    while (1){
        fgets(text, sizeof(text), stdin);
        if (feof(stdin)) break;
        Word_Frequency(text);
    }
    inOrder(root);
    return 0;
}
