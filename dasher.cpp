#include "raylib.h"

int main()
{
  // Initialization
  const int windowWidth{512};
  const int windowHeight{380};
  InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

  // rectagule dimensions
  const int width{50};
  const int height{80};

  int posY{windowHeight - height}; // Start at the bottom of the window
  int velocity{0};

  // Set the target FPS
  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose())
  {
    // Update

    // Draw
    BeginDrawing();
    ClearBackground(WHITE);

    if (IsKeyPressed(KEY_SPACE))
    {
      velocity -= 10;
    }

    posY += velocity;

    DrawRectangle((windowWidth - width) / 2, posY, width, height, BLUE);

    EndDrawing();
  }

  // De-Initialization
  CloseWindow(); // Close window and OpenGL context

  return 0;
}