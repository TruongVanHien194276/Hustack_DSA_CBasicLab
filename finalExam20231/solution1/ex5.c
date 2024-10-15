#include <stdio.h>

char c;
int n, a[] = {1, 3, 5};
int res[5];

void Generate(int x) {
    for (int i = 0; i <= 2; i++) {
        res[x] = a[i];
        if (x == n) {
            printf("%c", c);
            for (int j = 1; j <= n; j++){
                printf("%d", res[j]);
            }
            printf("\n");
        } else Generate(x + 1);
    }
}

int main() {
    scanf("%c", &c);
    scanf("%d", &n);
    
    if (c != 'A'&& c != 'B'&& c != 'C' && c != 'D'&& c != 'E') {
        printf("Error");
        return 0;
    }
    Generate(1);

    return 0;
}