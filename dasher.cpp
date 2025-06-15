#include "raylib.h"

int main()
{
  // Initialization
  const int windowWidth{512};
  const int windowHeight{380};
  InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

  // acceleration due to gravity (pixels/frame)/frame
  int gravity{1};

  // rectagule dimensions
  const int width{50};
  const int height{80};

  // is the rectangle in the air?
  bool isInAir{false};
  // jump velocity
  const int jumpVelocity{-22};

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

    // perform ground check
    if (posY >= windowHeight - height)
    {
      velocity = 0;
      isInAir = false;
    }
    else
    {
      // apply gravity
      velocity += gravity;
      isInAir = true;
    }

    // jump check
    if (IsKeyPressed(KEY_SPACE) && !isInAir)
    {
      velocity += jumpVelocity;
    }

    // update position
    posY += velocity;

    DrawRectangle((windowWidth - width) / 2, posY, width, height, BLUE);

    EndDrawing();
  }

  // De-Initialization
  CloseWindow(); // Close window and OpenGL context

  return 0;
}