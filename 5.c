#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
    int id;
    struct Node *next;
}Node;

Node *createN_Node(int n){
    Node *head = NULL, *temp =NULL, *last = NULL;
    for(int i = 1; i <= n; i++){
        temp = (Node *)malloc(sizeof(Node));
        temp->id = i;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            last = temp;
        }
        else{
            last->next = temp;
            last = temp;
        }
    }
    last->next = head;
    return head;
}

//Josephus Problem
int josephus(int n, int k){
    Node *head = createN_Node(n);
    Node *ptr = head, *prev = NULL;

    while(ptr->next != ptr){
        for(int count = 0; count < k; count++){
            prev = ptr;
            ptr = ptr->next;
        }

        // eliminated person k
        printf("Eliminated: %d\n", ptr->id);
        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;
    }

    int winer = ptr->id;
    free(ptr);
    return winer;
}


int main(){
    int n, k;
    printf("Enter number of players (N): ");
    scanf("%d", &n);
    printf("Enter step count (K): ");
    scanf("%d", &k);

    int winner = josephus(n, k);
    printf("\nThe last remaining player is: %d\n", winner);
    return 0;
}