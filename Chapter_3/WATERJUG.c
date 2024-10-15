// Problem: Chapter 3 - WATER JUGS
// Description
// There are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
// Input
//    Line 1: contains positive integers a, b, c  (1 <= a, b, c <= 900)
// Output
//   write the number of steps or write -1 (if no solution found)
// Example

// Input
// 6  8  4
// Output
// 4


#include <stdio.h>

int gcd(int x, int y){
    if (y == 0) return x;
    return gcd(y, x%y);
}
 
int pour(int fromCap, int toCap, int d){
    int from = fromCap;
    int to = 0;
    int step = 1;
 
    while (from != d && to != d){
        int temp = (from < toCap - to) ? from : toCap - to;
        to += temp;
        from -= temp;
        step++;

        if (from == d || to == d) break;
        if (from == 0){
            from = fromCap;
            step++;
        }
        if (to == toCap){
            to = 0;
            step++;
        }
    }
    return step;
}

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
 
int minSteps(int a, int b, int c){
    if (a > b) swap(a, b);
    if (c > b) return -1;
    if (c % gcd(b, a) != 0) return -1;

    return pour(b, a, c) < pour(a, b, c) ? pour(b, a, c) : pour(a, b, c); 
}
 
int main(int argc, const char** argv) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", minSteps(a, b, c));
    return 0;
}