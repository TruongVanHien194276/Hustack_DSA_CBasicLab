// Problem: Chapter 3 - Parenthesis
// Description
// Given a string containing only characters (, ), [, ] {, }. Write a program that check whether the string is correct in expression. 
// Example:
// ([]{()}()[]): correct
// ([]{()]()[]): incorrect
// Input
// One line contains the string (the length of the string is less than or equal to 10^6)
// Output
// Write 1 if the sequence is correct, and write 0, otherwise
// Example:
// input
// (()[][]{}){}{}[][]({[]()})
// output
// 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StackNode {
    char c; 
    struct StackNode* next;
} Node;

Node* makeNode(char c) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = c;
    p->next = NULL;
    return p;
}

Node* top = NULL; 

void push(char c) {
    Node* p = makeNode(c);
    p->next = top;
    top = p;
}

char pop() { 
    if (top == NULL) return NULL;
    char c = top->c;
    Node* temp = top;
    top = top->next;
    free(temp); 
    return c;
}

int is_empty() { 
    return top == NULL;
}

int match(char o, char c) {
    if(o == '(' && c == ')') return 1;
    if(o == '(' && c == ')') return 1;
    if(o == '(' && c == ')') return 1;
    return 0;
}

int check(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        }
        else {
            if (is_empty() == 1) return 0;
            char o = pop(); 
            if (match(o, s[i] == 0)) return 0;
        }
    }
    return is_empty();
}

int main(int argc, char const *argv[]){
    char s[1000001];
    scanf("%s", s);
    printf("%d", check(s));
}