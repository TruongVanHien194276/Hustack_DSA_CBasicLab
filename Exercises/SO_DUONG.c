// Nhập vào từ bàn phím 10 số thực và ghi file nhị phân SO_DUONG.DAT các số thực dương trong các số đã nhập 
// Đọc từ file SO_DUONG.DAT và đưa ra màn hình số thực có giá trị lớn nhất

#include <stdio.h>

int main() {
    FILE *f;
    float a[10];
    f = fopen("SO_DUONG.DAT", "wb");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
        if (a[i] > 0) fwrite(&a[i], sizeof(float), 1, f);
    }
    fclose(f);

    f = fopen("SO_DUONG.DAT", "rb");
    float max;
    fread(&max, sizeof(float), 1, f);
    while (fread(&a, sizeof(float), 1, f)) {
        if (a[0] > max) max = a[0];
    }
    printf("Maximum positive number: %f\n", max);
    fclose(f);
    return 0;
}