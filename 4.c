#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Task{
    char name [50];
    char describe[200];
    bool completed;
    struct Task *next;
}Task;

Task *head = NULL;

// setup tasks for mission automation
void setupTasks(){
    Task *temp = NULL, *last = NULL;
    for(int i = 0; i < 6; i++){
        temp = (Task *)malloc(sizeof(Task));
        sprintf(temp->name, "Task %d ", i);
        sprintf(temp->describe, "Description for Task %d ", i);
        temp->completed = false;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
        }else
            last->next = temp;
        last = temp;
    }
}

Task *getCurrentTask(){
    Task *temp = head;
    while(temp != NULL && temp->completed){
        temp = temp->next;
    }
    return temp;
}

void currentTasks(){
    if(head == NULL){
        printf("\nThe Task is empty!\n");
        return;
    }

    Task *temp = getCurrentTask();

    if(temp == NULL){
        printf("\nCongratulations! You got the Treasure!\n");
    }else{
        printf("To find the treasure, you must complete all the tasks");
        printf("\nYour next Task is: %s: %s \n", temp->name, temp->describe);
    }
}



int main(){
    setupTasks();
    char Done[10];
    printf("-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=");
    printf("\nWelcome to the game find the treasure\n");
    while(1){
        currentTasks();
        Task *current = getCurrentTask();

        if (current == NULL) {  // all done
            exit(0);
        }

        printf("\nType Done if you have been finished the task: ");
        scanf(" %[^\n]", Done);
        if(strcasecmp(Done, "done") == 0){
            current->completed = true;
            printf("✅ %s completed!\n", current->name);
        } else {
            printf("⚠️ Please type 'Done' when you finish the task.\n");
        }
    }
    return 0;
}
    
