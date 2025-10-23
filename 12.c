#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


bool isEmpty(Stack *s) {
    return s->top == -1;
}


void push(Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++s->top] = c;
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top--];
}


bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


bool isBalanced(char *exp) {
    Stack s;
    init(&s);

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s)) {
                return false; 
            }
            char top = pop(&s);
            if (!isMatchingPair(top, c)) {
                return false; 
            }
        }
    }

    return isEmpty(&s); 
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (isBalanced(exp))
        printf("✅ Balanced parentheses\n");
    else
        printf("❌ Not balanced parentheses\n");

    return 0;
}
