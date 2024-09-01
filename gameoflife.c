#include "raylib.h"

#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 750
#define FPS 12
#define CELL_SIZE 25
#define LINE_THICKNESS 1 

void drawGrid(int width, int height, int cellSize) {
    for (int x = cellSize; x < width; x += cellSize) {
        DrawLineEx((Vector2){x, 0}, (Vector2){x, height}, LINE_THICKNESS, LIGHTGRAY);
    }
    
    for (int y = cellSize; y < height; y += cellSize) {
        DrawLineEx((Vector2){0, y}, (Vector2){width, y}, LINE_THICKNESS, LIGHTGRAY);
    }

    // Draw border
    DrawRectangleLinesEx((Rectangle){0, 0, width, height}, LINE_THICKNESS, LIGHTGRAY);
}

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    
    Color grey = {29, 29, 29, 255};
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(grey);
        drawGrid(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
