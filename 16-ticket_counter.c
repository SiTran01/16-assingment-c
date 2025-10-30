#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Customer {
    char name[50];
    int tickets;
    struct Customer *next;
} Customer;

Customer *front = NULL, *rear = NULL;

void addCustomer(char *name, int tickets) {
    Customer *newCustomer = (Customer *)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    newCustomer->tickets = tickets;
    newCustomer->next = NULL;

    if (rear == NULL) {
        front = rear = newCustomer;
    } else {
        rear->next = newCustomer;
        rear = newCustomer;
    }

    printf("\nCustomer %s added with %d ticket(s).\n", name, tickets);
}


void serveCustomer() {
    if (front == NULL) {
        printf("\nNo customers waiting!\n");
        return;
    }

    Customer *temp = front;
    printf("\nServing customer: %s (Tickets: %d)\n", temp->name, temp->tickets);

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
}


void displayQueue() {
    if (front == NULL) {
        printf("\nNo customers in queue.\n");
        return;
    }

    printf("\nCurrent Waiting List:\n");
    Customer *temp = front;
    while (temp != NULL) {
        printf(" - %s (%d ticket(s))\n", temp->name, temp->tickets);
        temp = temp->next;
    }
}


void clearQueue() {
    Customer *temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
}

int main() {
    int choice;
    char name[50];
    int tickets;

    printf("=== Ticket Reservation Counter System ===\n");

    while (1) {
        printf("\n1. Add Customer\n2. Serve Next Customer\n3. View Waiting List\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf(" %[^\n]", name);
                printf("Enter number of tickets: ");
                scanf("%d", &tickets);
                addCustomer(name, tickets);
                break;
            case 2:
                serveCustomer();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                clearQueue();
                printf("\nSystem shutting down...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
