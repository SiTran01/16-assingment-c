#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Device {
    char nameDevice[50];
    int id;
    struct Device *next;
} Device;

Device *head = NULL;

// Thêm thiết bị mới
void addDevice(char *name) {
    Device *newDevice = (Device *)malloc(sizeof(Device));
    strcpy(newDevice->nameDevice, name);
    newDevice->next = NULL;

    // Gán ID tự động
    int id = 1;
    if (head == NULL) {
        head = newDevice;
    } else {
        Device *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            id++;
        }
        temp->next = newDevice;
        id++;
    }
    newDevice->id = id;

    printf("✅ Device '%s' added with ID %d\n", name, id);
}

// Xóa thiết bị theo ID
void rmDevicebyID(int id) {
    if (head == NULL) {
        printf("⚠️ Devices list is empty!\n");
        return;
    }
    Device *temp = head;
    Device *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Device with ID %d not found!\n", id);
        return;
    }

    if (temp == head)
        head = head->next;
    else
        prev->next = temp->next;

    printf("🗑️ Device with ID %d ('%s') removed successfully.\n", id, temp->nameDevice);
    free(temp);
}

// Xóa thiết bị theo tên
void rmDevicebyName(char *name) {
    if (head == NULL) {
        printf("⚠️ Devices list is empty!\n");
        return;
    }

    Device *temp = head;
    Device *prev = NULL;

    while (temp != NULL && strcmp(temp->nameDevice, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("❌ Device '%s' not found!\n", name);
        return;
    }

    if (temp == head)
        head = head->next;
    else
        prev->next = temp->next;

    printf("🗑️ Device '%s' removed successfully.\n", name);
    free(temp);
}

// Hiển thị tất cả thiết bị
void showAllDevices() {
    if (head == NULL) {
        printf("📭 No devices found!\n");
        return;
    }

    printf("\n📋 List of Devices:\n");
    printf("-------------------------------\n");

    Device *temp = head;
    while (temp != NULL) {
        printf("ID: %d | Name: %s\n", temp->id, temp->nameDevice);
        temp = temp->next;
    }
    printf("-------------------------------\n");
}

// Giải phóng toàn bộ bộ nhớ
void freeAllDevices() {
    Device *temp = head;
    while (temp != NULL) {
        Device *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    printf("🧹 All devices have been freed.\n");
}

int main() {
    int id, choice;
    char name[50];

    while (1) {
        printf("\n--- Manage Devices ---\n");
        printf("1. Add new Device\n");
        printf("2. Remove Device by Name\n");
        printf("3. Remove Device by ID\n");
        printf("4. Show All Devices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Device's name: ");
                scanf(" %[^\n]", name);
                addDevice(name);
                break;
            case 2:
                printf("Enter Device's name to remove: ");
                scanf(" %[^\n]", name);
                rmDevicebyName(name);
                break;
            case 3:
                printf("Enter Device ID to remove: ");
                scanf("%d", &id);
                rmDevicebyID(id);
                break;
            case 4:
                showAllDevices();
                break;
            case 5:
                freeAllDevices();
                printf("👋 Exiting program...\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    }
}
