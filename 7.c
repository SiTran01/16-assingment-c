#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10  

typedef struct Node {
    int key;
    struct Node *next;
}Node;

Node* hashTable[SIZE];

// Hàm băm (hash function)
int hashFunction(int key) {
    return key % SIZE; // đơn giản: chia lấy dư
}

Node *createNode(int key){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

//add member in hash table
void insert(int key) {
    int index = hashFunction(key);
    Node *newNode = createNode(key);
    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    } else {
        Node *temp = hashTable[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d into bucket %d\n", key, index);
}

//find member in hash table
void search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            printf("%d found in bucket %d!\n", key, index);
            return;
        }
        temp = temp->next;
    }

    printf("%d not found in hash table.\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    // Khởi tạo bảng hash rỗng
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
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