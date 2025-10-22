#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char name[50];
    struct Song *next;
} Song;

Song *head = NULL;

// Thêm bài hát vào cuối danh sách
void addSong(char *name) {
    Song *newSong = malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        Song *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
    printf("Đã thêm bài hát: %s\n", name);
}

// Hiển thị toàn bộ playlist
void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist trống!\n");
        return;
    }

    Song *temp = head;
    int index = 1;
    printf("\n--- PLAYLIST ---\n");
    while (temp != NULL) {
        printf("%d. %s\n", index++, temp->name);
        temp = temp->next;
    }
}

// Xóa bài hát theo tên
void removeSong(char *name) {
    Song *temp = head;
    Song *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Không tìm thấy bài hát: %s\n", name);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Đã xóa bài hát: %s\n", name);
}

int main() {
    int choice;
    char name[50];

    do {
        printf("\n===== AUDIO PLAYER PLAYLIST =====\n");
        printf("1. Thêm bài hát\n");
        printf("2. Hiển thị playlist\n");
        printf("3. Xóa bài hát\n");
        printf("4. Thoát\n");
        printf("Chọn: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
        case 1:
            printf("Nhập tên bài hát: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            addSong(name);
            break;

        case 2:
            displayPlaylist();
            break;

        case 3:
            printf("Nhập tên bài hát cần xóa: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            removeSong(name);
            break;

        case 4:
            printf("Thoát chương trình.\n");
            break;

        default:
            printf("Lựa chọn không hợp lệ!\n");
        }
    } while (choice != 4);

    return 0;
}
