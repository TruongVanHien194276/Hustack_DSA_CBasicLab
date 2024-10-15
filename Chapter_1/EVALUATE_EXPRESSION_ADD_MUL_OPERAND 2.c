// Problem: Chapter 1 - Evaluate expression contains + * operand
// Description
// Given a string representing a math expression including operator + and * and operands which are positive integers. Compute the value Q of this expression.
// Input
// Line 1: contains the string representing the expression (number of operators is upto 10000)
// Output
// Write the value Q modulo 10^9+7 if the expression is mathematically correct in term of the syntax, and write NOT_CORRECT, otherwise
// Example
// Input
// 5+7*3*10*10
// Output
// 2105
// Input
// 5*+ 7*3*10*10
// Output
// NOT_CORRECT

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int MOD = 1e9 + 7;

int main(int argc, char const *argv[]){
    char s[100000];
    fgets(s, 100000, stdin);

    for(int i = 0; i < strlen(s)-1; i++){
        if (!isdigit(s[i]) && !isdigit(s[i+1])){
			printf("NOT_CORRECT");
            return 0;
        }
    }
	
    int j = -1; 
    long long unsigned res = 0; 
    strcat(s, "+");
    for (int i = 0; i < strlen(s); i++){
    	if (s[i] == '+'){
		    char a[100];
			strncpy(a, &s[j+1], i-j-1);
			a[i-j-1] = '\0';
    	    j = i;   

    	    char *b = strtok(a, "*");
    	    long long unsigned d = 1;
			while (b != NULL){
    	    	long long unsigned c = atoi(b);
    	    	d = (d * c) % MOD;
    	    	b = strtok(NULL, "*");
			}
			res = (res + d) % MOD;
		}
	}
	printf("%llu", res % MOD);
    
    return 0;
}
