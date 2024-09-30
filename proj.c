#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define MINES 10

char grid[SIZE][SIZE];
char display[SIZE][SIZE];
int revealed[SIZE][SIZE];

void initializeGrid();
void placeMines();
void calculateHints();
void revealCell(int x, int y);
void printGrid();
int isGameOver(int x, int y);

int main() {
    int x, y;
    int gameOver = 0;

    printf("\nINSTRUCTIONS");
    printf("\n 1. Enter the coordinates. r c");
    printf("\n 2. If you reveal a number or zero, continue revealing cells.");
    printf("\n 3. If you reveal a mine, the game is over.\n");

    srand(time(NULL));
    initializeGrid();

    while (!gameOver) {
        printGrid();
        printf("Enter coordinates (row and column) to reveal (0-%d): ", SIZE-1);
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        if (revealed[x][y]) {
            printf("Cell already revealed. Try again.\n");
            continue;
        }

        revealCell(x, y);
        gameOver = isGameOver(x, y);
        if (gameOver) {
            printGrid();
            printf("Game Over! You hit a mine!\n");
            break;
        }
    }

    return 0;
}

void placeMines() {
    int placed = 0;
    while (placed < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] != 'M') {
            grid[x][y] = 'M';
            placed++;
        }
    }
}

void calculateHints() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 'M') continue;

            int count = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && grid[ni][nj] == 'M') {
                        count++;
                    }
                }
            }
            grid[i][j] = count + '0';
        }
    }
}


void initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '0';
            display[i][j] = '*';
            revealed[i][j] = 0;
        }
    }
    placeMines();
    calculateHints();
}


void revealCell(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y]) return;

    revealed[x][y] = 1;
    display[x][y] = grid[x][y];

    if (grid[x][y] == '0') {
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int ni = x + dx, nj = y + dy;
                if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
                    revealCell(ni, nj);
                }
            }
        }
    }
}

void printGrid() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }
}

int isGameOver(int x, int y) {
    return grid[x][y] == 'M';
}