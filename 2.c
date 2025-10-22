#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song *next;
}Song;

Song *head = NULL;

// Add new Song to the end of the playlist
void addSong(char *name){
    Song *newSong = (Song *)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    if(head == NULL){
        head = newSong;
    }else{
        Song *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newSong;
    }
    printf("Added song: %s\n", name);
}

// show the entire playlist
void displayPlaylist(){
    if(head == NULL){
        printf("Playlist is empty!\n");
        return;
    }
    Song *temp = head;
    int index = 1;
    printf("\n--- PLAYLIST ---\n");
    while(temp != NULL){
        printf("%d. %s\n", index++, temp->name);
        temp = temp->next;
    }
}

//remove Song by name
void removeSong(char *name){
    Song *temp = head;
    Song *prev = NULL;
    while(temp != NULL && strcmp(temp->name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Song not found: %s\n", name);
        return;
    }
    if(prev == NULL){
        head = temp->next;
    }else{
        prev->next = temp->next;
    }
    free(temp);
    printf("Removed song: %s\n", name);
}

// Free the entire playlist
void freePlaylist(){
    Song *temp = head;
    while(temp != NULL){
        Song *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

int main(){
    int choice;
    char name[50];
    while(1){
        printf("\n1. Add new Song\n2. Display playlist\n3. Remove Song\n4. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter song name: ");
                scanf(" %[^\n]", name);
                addSong(name);
                break;
            case 2:
                displayPlaylist();
                break;
            case 3:
                printf("\nEnter song name to remove: ");
                scanf(" %[^\n]", name);
                removeSong(name);
                break;
            case 4:
                freePlaylist();
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}