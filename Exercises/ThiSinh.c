// Bài 2: Nhập danh sách từ bàn phím các thí sinh dự thi, mỗi thí sinh gồm họ tên, số báo danh, khoa dự thi và điểm thi. 
// Dữ liệu nhập được ghi vào file ThiSinh.dat. 
// Kết thúc nhập khi gặp một thí sinh có tên là «***» 
// Đọc từ file ThiSinh.Dat, đưa ra màn hình danh sách các thí sinh thi vào ngành CNTT có điểm thi lớn hớn 21 theo quy cách   
//     STT So_Bao_Danh Ho_Ten Diem_Thi 
// Từ file ThiSinh.Dat, tạo file CNTT.Dat chỉ chứa danh sách các thí inh thi vào khoa CNTT 
// Nhập vào một số báo danh, tìm trong file ThiSinh.Dat và in ra họ tên, điểm thi và khoa đăng ký của thí sinh nếu tìm thấy. 
// Nếu không tìm thấy thí sinh thì đưa ra thông báo «không tìm thấy»


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_DEPT_LEN 10

typedef struct {
    char name[100];
    int id;
    char major[20];
    float score;
} Student;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void inputStudents(const char *f) {
    FILE *file = fopen(f, "wb");
    if (!file) return;

    Student st;
    while (1) {
        printf("Nhap ho ten thi sinh (*** de ket thuc): ");
        fgets(st.name, MAX_NAME_LEN, stdin);
        st.name[strcspn(st.name, "\n")] = 0;  

        if (strcmp(st.name, "***") == 0) break;

        printf("Nhap so bao danh: ");
        scanf("%d", &st.id);
        clearInputBuffer(); 

        printf("Nhap khoa du thi: ");
        scanf("%19s", st.major); 
        clearInputBuffer(); 

        printf("Nhap diem thi: ");
        scanf("%f", &st.score);
        clearInputBuffer(); 

        fwrite(&st, sizeof(Student), 1, file);
    }

    fclose(file);
}

void displayITStudents(const char *f) {
    FILE *file = fopen(f, "rb");
    if (!file) return;

    Student st;
    int cnt = 1;

    printf("STT So_Bao_Danh Ho_Ten Diem_Thi\n");
    while (fread(&st, sizeof(Student), 1, file)) {
        if (strcmp(st.major, "CNTT") == 0 && st.score > 21) {
            printf("%d %d %s %.2f\n", cnt++, st.id, st.name, st.score);
        }
    }

    fclose(file);
}

void createITFile(const char *inFile, const char *outFile) {
    FILE *inputFile = fopen(inFile, "rb");
    FILE *outputFile = fopen(outFile, "wb");
    if (!inputFile || !outputFile) return;

    Student st;
    while (fread(&st, sizeof(Student), 1, inputFile)) {
        if (strcmp(st.major, "CNTT") == 0) {
            fwrite(&st, sizeof(Student), 1, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

void searchByID(const char *filename, int id) {
    FILE *file = fopen(filename, "rb");
    if (!file) return;

    Student st;
    int found = 0;
    while (fread(&st, sizeof(Student), 1, file)) {
        if (st.id == id) {
            printf("So bao danh: %d\n", st.id);
            printf("Ho ten: %s\n", st.name);
            printf("Diem thi: %.2f\n", st.score);
            printf("Khoa dang ky: %s\n", st.major);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay\n");
    }

    fclose(file);
}

int main() {
    const char *inFile = "ThiSinh.Dat";
    const char *outFile = "CNTT.Dat";

    inputStudents(inFile);
    displayITStudents(inFile);
    createITFile(inFile, outFile);

    int id;
    printf("Nhap so bao danh de tim kiem thong tin: ");
    clearInputBuffer(); 
    scanf("%d", &id);
    searchByID(inFile, id);

    return 0;
}

