// Problem: Chapter 1 - Convert a TEXT to Upper-Case
// Description
// Given a TEXT, write a program that converts the TEXT to upper-case. 

// Input
// The TEXT

// Output
// The TEXT in which characters are converted into upper-case

// Example 
// Input 
// Hello John,
// How are you?

// Bye,

// Output 
// HELLO JOHN,
// HOW ARE YOU?

// BYE, 

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[]){
    char text[1000];
    while(fgets(text, 1000, stdin) != NULL){
        for(int i = 0; i < strlen(text); i++){
            if(text[i] >= 'a' && text[i] <= 'z'){
                text[i] = text[i] - 32;
            }
        }
        printf("%s", text);
    }

    return 0;
}
