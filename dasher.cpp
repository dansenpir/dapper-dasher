#include "raylib.h"

int main()
{
  // Initialization
  const int windowWidth{512};
  const int windowHeight{380};
  InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

  // acceleration due to gravity (pixels/frame)/frame
  int gravity{1};

  Texture2D scarfy = LoadTexture("textures/scarfy.png");
  Rectangle scarfyRec = {0.0f, 0.0f, (float)scarfy.width / 6, (float)scarfy.height};
  Vector2 scarfyPos = {windowWidth / 2.0f - scarfyRec.width / 2.0f, windowHeight - scarfyRec.height};

  // is the rectangle in the air?
  bool isInAir{false};
  // jump velocity
  const int jumpVelocity{-22};

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
    if (scarfyPos.y >= windowHeight - scarfyRec.height)
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
    scarfyPos.y += velocity;

    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

    EndDrawing();
  }

  UnloadTexture(scarfy);
  // De-Initialization
  CloseWindow(); // Close window and OpenGL context

  return 0;
}