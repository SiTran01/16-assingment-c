#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char blockName[50];
} MemoryBlock;

typedef struct {
    MemoryBlock blocks[MAX];
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


void allocate(Stack *s, const char *name) {
    if (isFull(s)) {
        printf("Memory Stack Overflow! Cannot allocate more memory.\n");
        return;
    }
    strcpy(s->blocks[++s->top].blockName, name);
    printf("Allocated block: %s\n", name);
}


void freeMemory(Stack *s) {
    if (isEmpty(s)) {
        printf("No memory to free!\n");
        return;
    }
    printf("Freed block: %s\n", s->blocks[s->top--].blockName);
}


void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Memory Stack is empty.\n");
        return;
    }
    printf("\nCurrent Memory Stack (Top → Bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf(" | %s |\n", s->blocks[i].blockName);
    }
    printf(" --------\n");
}

int main() {
    Stack memory;
    init(&memory);

    int choice;
    char name[50];

    while (1) {
        printf("\n1. Allocate memory\n2. Free memory\n3. Show memory stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                printf("Enter block name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                allocate(&memory, name);
                break;
            case 2:
                freeMemory(&memory);
                break;
            case 3:
                display(&memory);
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
