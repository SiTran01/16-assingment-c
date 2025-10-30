#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
    char name[50];
    struct Person *next;
}Person;

Person *head = NULL;

//Add new person
void addPerson(char *name){
    Person *newPerson = (Person *)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->next = NULL;

    if(head == NULL) {
        head = newPerson;
    } else {
        Person *temp = head;         
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newPerson;
    }

    printf("Add new Person: %s\n", name);
}

//show All person
void showPerson(){
    if(head == NULL){
        printf("EMPTY!\n");
    }
    int index = 1;
    Person *temp = head;
    printf("--- Waiting List ---\n");
    while(temp != NULL){
        printf("%d. %s\n", index++, temp->name);
        temp = temp->next;
    }
}

//Remove Person by name
void rmPersonByName(char *name){
    Person *temp = head;
    Person *prev = NULL;
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Person not found!\n");
        return;
    }
    if(prev == NULL){
        head = temp->next;
    }else{
        prev->next = temp->next;
    }
    free(temp);
    printf("The Person %s has been deleted\n", name);
}

//ServiceNextPerson
void servNextPerson(){
    if(head == NULL){
        printf("No Person to serve\n");
    }else{
        Person *temp = head;
        head = temp->next;
        printf("The next Person has been served\n");
        free(temp);
    }
}

// free ALL person before exit(0)
void freeAllPerson(){
    Person  *temp = head;
    while(temp != NULL){
        Person *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}


int main(){
    int choice;
    char name[50];
    while(1){
        printf("\n1. Add new Song\n2. Display playlist\n3. Remove Song\n4. Serve next person\n5. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter Person name: ");
                scanf(" %[^\n]", name);
                addPerson(name);
                break;
            case 2:
                showPerson();
                break;
            case 3:
                printf("\nEnter song name to remove: ");
                scanf(" %[^\n]", name);
                rmPersonByName(name);
                break;
            case 4:
                servNextPerson();
                break;
            case 5:
                freeAllPerson();
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");

        }
        
    }
}