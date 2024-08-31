#include "raylib.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define FPS 12

int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    
    Color grey = {29, 29, 29, 255};

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(grey);
        EndDrawing();
    }
  CloseWindow();
  return 0;
}
