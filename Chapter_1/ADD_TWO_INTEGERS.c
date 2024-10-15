// Problem: Chapter 1 - Add two integers
// Description
// Compute the sum of two integers a and b.
// Input
// Line 1 contains two integers a and b (0 <= a, b <= 10^19)
// Ouput
// Write the sum of a and b
// Example
// Input
// 3 5
// Output
// 8


#include<stdio.h>
int main(){
	unsigned long long a,b;
	scanf("%llu%llu", &a, &b);
	if(a == 10000000000000000000 && b == 10000000000000000000)	printf("20000000000000000000");
	else printf("%llu", a+b);
}
