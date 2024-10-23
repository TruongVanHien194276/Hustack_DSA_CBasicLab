// Problem: Chapter 1 - Count words
// Description
// Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

// Input
// The Text

// Output
// Write the number Q of words

// Example
// Input
// Hanoi University Of Science and Technology
// School of Information and Communication Technology


// Output
// 12

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    char text[1000];
	int cnt = 0;
	while (fgets(text, sizeof(text), stdin) != NULL){
		int cnt_down = 0;
		for (int i = 0; i < strlen(text); i++) {
			if(text[i] != ' ' &&  text[i] != '\n') cnt_down = 1;
			else {
				cnt += cnt_down;
				cnt_down=0;
			}
		}
	}
	printf("%d", cnt);
    return 0;
}
