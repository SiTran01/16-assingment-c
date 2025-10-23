#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char action[100];
} Operation;

typedef struct {
    Operation ops[MAX];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX - 1;
}


void doAction(Stack *s, const char *act) {
    if (isFull(s)) {
        printf("Action stack full! Cannot do more actions.\n");
        return;
    }
    strcpy(s->ops[++s->top].action, act);
    printf("Action done: %s\n", act);
}


void undoAction(Stack *s) {
    if (isEmpty(s)) {
        printf("Nothing to undo!\n");
        return;
    }
    printf("Undo action: %s\n", s->ops[s->top--].action);
}


void showHistory(Stack *s) {
    if (isEmpty(s)) {
        printf("No actions performed yet.\n");
        return;
    }
    printf("\nAction History (Top → Bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf(" | %s |\n", s->ops[i].action);
    }
    printf(" --------\n");
}

int main() {
    Stack undoStack;
    init(&undoStack);

    int choice;
    char action[100];

    while (1) {
        printf("\n1. Do an action\n2. Undo last action\n3. Show action history\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                printf("Enter action description: ");
                fgets(action, sizeof(action), stdin);
                action[strcspn(action, "\n")] = '\0'; // remove newline
                doAction(&undoStack, action);
                break;
            case 2:
                undoAction(&undoStack);
                break;
            case 3:
                showHistory(&undoStack);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
