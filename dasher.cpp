#include "raylib.h"

int main()
{
  // Initialization
  const int windowWidth{512};
  const int windowHeight{380};
  InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

  // acceleration due to gravity (pixels/s)/s
  int gravity{1000};

  // nebula variable declarations
  Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
  Rectangle nebRec = {0.0f, 0.0f, (float)nebula.width / 8, (float)nebula.height / 8};
  Vector2 nebPos = {windowWidth, windowHeight - nebRec.height};

  // nebula animation variables
  int nebFrame{};
  const float nebUpdateTime{1.0f / 12.0f}; // 12 FPS
  float nebRunningTime{};

  // nebula X velocity (pixels/s)
  int nebVel{-200};

  // scarfy variable declarations
  Texture2D scarfy = LoadTexture("textures/scarfy.png");
  Rectangle scarfyRec = {0.0f, 0.0f, (float)scarfy.width / 6, (float)scarfy.height};
  Vector2 scarfyPos = {windowWidth / 2.0f - scarfyRec.width / 2.0f, windowHeight - scarfyRec.height};

  // animation frame counter
  int frame{};

  // amount of time before we update the animation frame
  const float updateTime{1.0 / 12.0f}; // 12 FPS

  float runningTime{};

  // is the rectangle in the air?
  bool isInAir{false};
  // jump velocity (pixels/s)
  const int jumpVelocity{-600};

  int velocity{0};

  // Set the target FPS
  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose())
  {

    // delta time (time since last frame)
    float dT{GetFrameTime()};

    // start drawing
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
      velocity += gravity * dT;
      isInAir = true;
    }

    // jump check
    if (IsKeyPressed(KEY_SPACE) && !isInAir)
    {
      velocity += jumpVelocity;
    }

    // update nebula position
    nebPos.x += nebVel * dT;

    // update scarfy position
    scarfyPos.y += velocity * dT;

    // update scarfy's animation frame
    if (!isInAir)
    {
      // update running time
      runningTime += dT;
      if (runningTime >= updateTime)
      {
        runningTime = 0.0f;
        // update animation frame
        scarfyRec.x = (frame % 6) * scarfyRec.width;
        frame++;
        if (frame > 5)
        {
          frame = 0;
        }
      }
    }

    // update nebula animation frame
    nebRunningTime += dT;
    if (nebRunningTime >= nebUpdateTime)
    {
      nebRunningTime = 0.0f;
      nebRec.x = (nebFrame % 8) * nebRec.width;
      nebFrame++;
      if (nebFrame > 7)
      {
        nebFrame = 0;
      }
    }

    // draw nebula
    DrawTextureRec(nebula, nebRec, nebPos, WHITE);

    // draw scarfy
    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

    EndDrawing();
  }

  UnloadTexture(scarfy);
  UnloadTexture(nebula);
  // De-Initialization
  CloseWindow(); // Close window and OpenGL context

  return 0;
}