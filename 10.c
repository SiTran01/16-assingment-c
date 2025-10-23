#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100   // Kích thước tối đa của stack

// ------------------ KHAI BÁO STACK ------------------
char stack[MAX];  // Mảng làm stack
int top = -1;     // Vị trí phần tử trên cùng

// ------------------ CÁC HÀM STACK ------------------

// Thêm phần tử vào stack (PUSH)
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;  // tăng top rồi thêm ký tự vào
}

// Lấy phần tử ra khỏi stack (POP)
char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack[top--];  // trả về ký tự trên cùng rồi giảm top
}

// ------------------ HÀM CHÍNH ------------------
int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%[^\n]", str);  // đọc cả chuỗi (kể cả khoảng trắng)

    // Đưa từng ký tự vào stack
    for (int i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    // Lấy ra từ stack để đảo ngược
    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");
    return 0;
}
