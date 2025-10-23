#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

typedef struct {
    int x, y;
}Point;

typedef struct {
    Point data[100];
    int top;
}Stack;

void push(Stack *s, Point p){
    s->data[++(s->top)] = p;
}

Point pop(Stack *s) {
    return s->data[(s->top)--];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isSafe(int maze[N][N], int visited[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N &&
            maze[x][y] == 1 && !visited[x][y]);
}

void solveMaze(int maze[N][N]) {
    int visited[N][N] = {0};
    Stack s;
    s.top = -1;

    Point start = {0, 0};
    push(&s, start);
    visited[0][0] = 1;

    int found = 0;

    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!isEmpty(&s)) {
        Point curr = s.data[s.top];

        if (curr.x == N - 1 && curr.y == N - 1) {
            found = 1;
            break;
        }

        int moved = 0;
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            if (isSafe(maze, visited, nx, ny)) {
                Point next = {nx, ny};
                push(&s, next);
                visited[nx][ny] = 1;
                moved = 1;
                break;
            }
        }

        if (!moved)
            pop(&s); 
    }

    if (found) {
        printf("✅ Path found:\n");
        for (int i = 0; i <= s.top; i++) {
            printf("(%d,%d) ", s.data[i].x, s.data[i].y);
        }
        printf("\n");
    } else {
        printf("❌ No path found.\n");
    }
}


int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    solveMaze(maze);
    return 0;
}
