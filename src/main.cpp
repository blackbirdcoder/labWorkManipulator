// clang-format off
#include "manipulator.h"
#include "settings.h"
#include <raylib.h>
#include "camera.h"
// clang-format on

int main(void) {
  InitWindow(W_WIDTH, W_HEIGHT, TITLE);
  SetTargetFPS(FPS);
  PresentationCamera preCamera = PresentationCamera();
  Manipulator manipulator = Manipulator();

  while (!WindowShouldClose()) {
    //--- Update
    preCamera.Run(CAMERA_FREE);
    //---

    //--- Draw
    BeginDrawing();
    ClearBackground(palette.background);
    DrawText("Manipulator", 10, 10, 30, palette.ui);
    BeginMode3D(preCamera.Get());
    manipulator.Exploitation();
    DrawGrid(10, 0.5f);
    EndMode3D();
    EndDrawing();
    //---
  }

  manipulator.Finish();
  CloseWindow();
  return 0;
}
