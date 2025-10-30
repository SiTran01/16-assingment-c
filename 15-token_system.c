#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int nextToken = 1;  


void issueToken() {
    if (rear == MAX - 1) {
        printf("\nQueue Full! Cannot issue new token.\n");
        return;
    }
    if (front == -1)
        front = 0;

    queue[++rear] = nextToken++;
    printf("\nToken number %d has been issued.\n", queue[rear]);
}


void announceToken() {
    if (front == -1 || front > rear) {
        printf("\nNo tokens waiting!\n");
        return;
    }

    printf("\nNow serving Token number: %d\n", queue[front]);
    front++;

    if (front > rear) {  
        front = rear = -1;
    }
}


void displayQueue() {
    if (front == -1) {
        printf("\nNo tokens in queue.\n");
        return;
    }

    printf("\nTokens currently waiting:\n");
    for (int i = front; i <= rear; i++) {
        printf(" %d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    printf("=== Token Number Announcement System ===\n");

    while (1) {
        printf("\n1. Issue New Token\n2. Announce Next Token\n3. Show Waiting Tokens\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                issueToken();
                break;
            case 2:
                announceToken();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("\nSystem shutting down...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}
