// Problem: Chapter 1 - Text Replacement
// Description
// Cho văn bản T và 2 mẫu P1, P2 đều là các xâu ký tự (không chứa ký tự xuống dòng, độ dài không vượt quá 1000). Hãy thay thế các xâu P1 trong T bằng xâu P2.
// Dữ liệu
// · Dòng 1: xâu P1
// · Dòng 2: xâu P2
// · Dòng 3: văn bản T
// Kết quả:
// · Ghi văn bản T sau khi thay thế
// Ví dụ
// Dữ liệu
// AI
// Artificial Intelligence
// Recently, AI is a key technology. AI enable efficient operations in many fields.
// Kết quả
// Recently, Artificial Intelligence is a key technology. Artificial Intelligence enable efficient operations in many fields.

#include <stdio.h>
#include <string.h>

void replace_strings(char *P1, char *P2, char *T) {
    char *ptr;
    int len_P1 = strlen(P1);
    int len_P2 = strlen(P2);
    int len_T = strlen(T);

    while ((ptr = strstr(T, P1)) != NULL) {
        int index = ptr - T;
        memmove(ptr + len_P2, ptr + len_P1, len_T - index - len_P1 + 1);
        strncpy(ptr, P2, len_P2);
        len_T = strlen(T);
    }
}

int main(int argc, char const *argv[]){
    char P1[1001], P2[1001], T[1001];

    fgets(P1, sizeof(P1), stdin);
    fgets(P2, sizeof(P2), stdin);
    fgets(T, sizeof(T), stdin);

    P1[strcspn(P1, "\n")] = '\0';
    P2[strcspn(P2, "\n")] = '\0';
    T[strcspn(T, "\n")] = '\0';

    replace_strings(P1, P2, T);

    printf("%s", T);

    return 0;
}
