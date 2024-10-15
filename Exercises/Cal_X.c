// Problem: Cal_X
// Description
// Cho một biểu thức dạng xâu với các toán hạng (operand) là số thực và toán tử (operator) là các phép cộng "+", trừ "-", nhân "*", và chia "/", kết hợp với biểu thức ngoặc tròn mở ngoặc "(", và đóng ngoặc ")". Tính giá trị của biểu thức.  (Giả thiết biểu thức đầu vào là đúng.)
// Chú ý:
// -  Nếu tính toán trên số nguyên (cộng, trừ, nhân) và chia hết (trong trường hợp có phép chia) thì chỉ trả về giá trị nguyên (không có dấu thập phân).
// -  Các trường hợp còn lại trả về số thực thì làm tròn đến 1 chữ số sau dấu thập phân.
// -  Không dùng hàm Eval hay các thư viện tính giá trị biểu thức trực tiếp trên python.
// Input:
// Dòng 1: Biểu thức dạng xâu có độ dài nhỏ hơn 100, không có dấu cách (hay khoảng trống).
// Output:
// Giá trị của biểu thức

// Ví dụ:
// Input:
// 10+(1.0+2.0)/2
// Output:
// 11.5

// Input:
// 10+10
// Output:
// 20

// Input:
// 10+11.0
// Output:
// 21.0

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

void applyOperator(double* numbers, int* numIdx, char* operators, int* opIdx, bool* isFloat) {
    double b = numbers[--(*numIdx)];
    double a = numbers[--(*numIdx)];
    char op = operators[--(*opIdx)];
    double res = calculate(a, b, op);

    if (op == '/') {
        *isFloat = true;
    }

    numbers[(*numIdx)++] = res;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double evaluate(const char* expression, bool* isFloat) {
    double numbers[100];
    char operators[100];
    int numIdx = 0, opIdx = 0;
    int i = 0;

    while (expression[i] != '\0') {
        if (isdigit(expression[i]) || expression[i] == '.') {
            double number = 0;
            int decimalPlace = -1;
            while (isdigit(expression[i]) || expression[i] == '.') {
                if (expression[i] == '.') {
                    decimalPlace = 1;
                    *isFloat = true;
                } else {
                    number = number * 10 + (expression[i] - '0');
                    if (decimalPlace > 0) decimalPlace *= 10;
                }
                i++;
            }
            if (decimalPlace > 0) {
                number = number / decimalPlace;
            }
            numbers[numIdx++] = number;
        } else if (expression[i] == '(') {
            operators[opIdx++] = expression[i];
            i++;
        } else if (expression[i] == ')') {
            while (opIdx > 0 && operators[opIdx - 1] != '(') {
                applyOperator(numbers, &numIdx, operators, &opIdx, isFloat);
            }
            opIdx--; // remove (
            i++;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (opIdx > 0 && precedence(operators[opIdx - 1]) >= precedence(expression[i])) {
                applyOperator(numbers, &numIdx, operators, &opIdx, isFloat);
            }
            operators[opIdx++] = expression[i];
            i++;
        } else i++;
    }

    while (opIdx > 0) {
        applyOperator(numbers, &numIdx, operators, &opIdx, isFloat);
    }

    return numbers[0];
}

int main(int argc, char const *argv[]){
    char expression[100];
    scanf("%s", expression);

    bool isFloat = false;
    double res = evaluate(expression, &isFloat);

    if (isFloat) {
        printf("%.1f\n", res);
    } else {
        printf("%d\n", (int)res);
    }

    return 0;
}
