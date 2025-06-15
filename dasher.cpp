#include "raylib.h"

int main()
{
  // Initialization
  const int windowWidth{512};
  const int windowHeight{380};
  InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

  // Set the target FPS
  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose())
  {
    // Update

    // Draw
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }

  // De-Initialization
  CloseWindow(); // Close window and OpenGL context

  return 0;
}