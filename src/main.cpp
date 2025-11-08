// clang-format off
#include "manipulator.h"
#include "settings.h"
#include <raylib.h>
#include "camera.h"
#include "ui.h"
// clang-format on

int main(void) {
  InitWindow(W_WIDTH, W_HEIGHT, TITLE);
  SetTargetFPS(FPS);
  PresentationCamera preCamera = PresentationCamera();
  Manipulator manipulator = Manipulator();
  GUI gui = GUI();

  while (!WindowShouldClose()) {
    //--- Update
    preCamera.Run();
    //---

    //--- Draw
    BeginDrawing();
    ClearBackground(palette.background);
    BeginMode3D(preCamera.Get());
    manipulator.Exploitation();
    DrawGrid(10, 0.5f);
    EndMode3D();
    //---GUI
    gui.StateSwitchButton(((float)GetScreenWidth() - 130), &preCamera.state,
                          preCamera.GetTitle());
    //---
    EndDrawing();
    //---
  }

  manipulator.Finish();
  CloseWindow();
  return 0;
}
