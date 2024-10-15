// Problem: Chapter 1 - Replace characters in string
// Description
// Write a function that gets a string and two chars as arguments. The functions scans the string and replaces every occurrence of the first char with the second one.
// Write a program to test the above function. The program should read a string from the user (no spaces) and two characters, then call the function with the input, and print the result.
// For example
// - input: “papa”, ‘p’, ‘m’
// - output: “mama”

#include <stdio.h>
#include <string.h>

void replaceChar(char *str, char c1, char c2) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c1) {
            str[i] = c2;
        }
    }
}

int main(int argc, char const *argv[]){
    char str[100], c1, c2;
    scanf("%s", str);
    scanf(" %c %c", &c1, &c2);
    replaceChar(str, c1, c2);
    printf("%s\n", str);
    return 0;
}