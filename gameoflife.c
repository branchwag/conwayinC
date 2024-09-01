#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define FPS 12
#define CELL_SIZE 25
#define LINE_THICKNESS 2
#define GRID_WIDTH (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)

int grid[GRID_HEIGHT][GRID_WIDTH];

void initializeGrid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = rand() % 2;  // Randomly set each cell to 0 or 1
        }
    }
}

void drawGrid() {
    // Draw filled cells
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x] == 1) {
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, GREEN);
            }
        }
    }

    // Draw grid lines
    for (int x = 0; x <= WINDOW_WIDTH; x += CELL_SIZE) {
        DrawLineEx((Vector2){x, 0}, (Vector2){x, WINDOW_HEIGHT}, LINE_THICKNESS, LIGHTGRAY);
    }
    for (int y = 0; y <= WINDOW_HEIGHT; y += CELL_SIZE) {
        DrawLineEx((Vector2){0, y}, (Vector2){WINDOW_WIDTH, y}, LINE_THICKNESS, LIGHTGRAY);
    }

    DrawRectangleLinesEx((Rectangle){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, LINE_THICKNESS, LIGHTGRAY);
}

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    
    srand(time(NULL));
    initializeGrid();

    Color grey = {29, 29, 29, 255};
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(grey);
        drawGrid();
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
