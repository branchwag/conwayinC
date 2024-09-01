#include "raylib.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define FPS 10
#define CELL_SIZE 15
#define LINE_THICKNESS 1
#define GRID_WIDTH (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)

int grid[GRID_HEIGHT][GRID_WIDTH];
int temp_grid[GRID_HEIGHT][GRID_WIDTH];

void initializeGrid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = rand() % 4 == 0;  // 25% chance of being alive
        }
    }
}

int countNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = (x + i + GRID_WIDTH) % GRID_WIDTH;
            int ny = (y + j + GRID_HEIGHT) % GRID_HEIGHT;
            count += grid[ny][nx];
        }
    }
    return count;
}

void updateGrid() {
    memcpy(temp_grid, grid, sizeof(grid));
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int neighbors = countNeighbors(x, y);
            if (grid[y][x]) {
                temp_grid[y][x] = (neighbors == 2 || neighbors == 3);
            } else {
                temp_grid[y][x] = (neighbors == 3);
            }
        }
    }
    memcpy(grid, temp_grid, sizeof(grid));
}

void drawGrid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x]) {
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, GREEN);
            }
        }
    }

    for (int x = 0; x <= WINDOW_WIDTH; x += CELL_SIZE) {
        DrawLineEx((Vector2){x, 0}, (Vector2){x, WINDOW_HEIGHT}, LINE_THICKNESS, LIGHTGRAY);
    }
    for (int y = 0; y <= WINDOW_HEIGHT; y += CELL_SIZE) {
        DrawLineEx((Vector2){0, y}, (Vector2){WINDOW_WIDTH, y}, LINE_THICKNESS, LIGHTGRAY);
    }

    DrawRectangleLinesEx((Rectangle){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, LINE_THICKNESS, LIGHTGRAY);
}

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Conway's Game of Life");
    SetTargetFPS(FPS);
    
    srand(time(NULL));
    initializeGrid();

    Color grey = {29, 29, 29, 255};
    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            initializeGrid();  
        }
        
        updateGrid();
        
        BeginDrawing();
        ClearBackground(grey);
        drawGrid();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
