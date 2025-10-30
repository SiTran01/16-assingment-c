#include <stdio.h>
#include <string.h>

#define MAX 10

char stack[MAX][50];
int top = -1;


void push(const char *funcName) {
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot call more functions.\n");
        return;
    }
    strcpy(stack[++top], funcName);
    printf("CALL: %s()  → pushed to stack.\n", funcName);
}


void pop() {
    if (top == -1) {
        printf("Stack underflow! No function to return.\n");
        return;
    }
    printf("RETURN: %s()  → popped from stack.\n", stack[top--]);
}


void showStack() {
    printf("\nCurrent Call Stack (Top → Bottom):\n");
    if (top == -1) {
        printf("   [empty]\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("   | %s |\n", stack[i]);
    }
    printf("   --------\n\n");
}


void functionC();
void functionB();
void functionA();

void functionC() {
    push("functionC");
    showStack();
    printf("   Doing work in functionC...\n");
    pop();
    showStack();
}

void functionB() {
    push("functionB");
    showStack();
    functionC();
    printf("   Back to functionB\n");
    pop();
    showStack();
}

void functionA() {
    push("functionA");
    showStack();
    functionB();
    printf("   Back to functionA\n");
    pop();
    showStack();
}

int main() {
    printf("Program started...\n");
    push("main");
    showStack();

    functionA();

    pop(); // main ends
    showStack();

    printf("Program finished.\n");
    return 0;
}
