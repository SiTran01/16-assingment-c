#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct History{
    char folder[50];
    struct History *next;
    struct History *prev;
}History;

History *head = NULL;
History *current = NULL;

void goTo(char *name){
    History *newHis = (History *)malloc(sizeof(History));
    strcpy(newHis->folder, name);
    newHis->next = NULL;
    newHis->prev = NULL;

    if(head == NULL){
        head = newHis;
        current = newHis;
    }else{
        if(current->next != NULL){
            History *temp = current->next;
            while(temp != NULL){
                History *del = temp;
                temp = temp->next;
                free(del);
            }
            current->next = NULL;
        }
        // add new HIS folder
        current->next = newHis;
        newHis->prev = current;
        current = newHis;
    }

    printf("Go to %s \n", name);
}

void back() {
    if (current == NULL || current->prev == NULL) {
        printf("\n🚫 Cannot go back — this is the first folder.\n");
        return;
    }
    current = current->prev;
    printf("\n⬅️  Back to %s\n", current->folder);
}

void forward() {
    if (current == NULL || current->next == NULL) {
        printf("\n🚫 Cannot go forward — no next folder.\n");
        return;
    }
    current = current->next;
    printf("\n➡️  Forward to %s\n", current->folder);
}

void freeHistory() {
    History *temp = head;
    while (temp != NULL) {
        History *del = temp;
        temp = temp->next;
        free(del);
    }
    head = current = NULL;
    printf("\n✅ Freed all history.\n");
}



int main(){
    int choice;
    char name[50];
    while(1){
        printf("\n1. Go to...\n2.back...\n3.foward...\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter folder's name you wana to: ");
                scanf(" %[^\n]", name);
                goTo(name);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                freeHistory();
                exit(0);
            default:
                printf("Invalid Input!\n");
        }
    }
}