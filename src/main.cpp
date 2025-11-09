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

  float tf = 0.0f;

  while (!WindowShouldClose()) {
    //--- Update
    preCamera.Run();
    //---

    //--- Draw
    BeginDrawing();
    ClearBackground(palette.background);
    BeginMode3D(preCamera.Get());
    manipulator.Exploitation();
    manipulator.ForearmMoveZ();
    DrawGrid(10, 0.5f);
    EndMode3D();
    //---GUI
    gui.StateSwitchButton(((float)GetScreenWidth() - 130), &preCamera.state,
                          preCamera.GetTitle());
    gui.ControlRange(
        "Forearm Z:",
        manipulator.GetPtrCapabilityValue("forearm", "z", manipulator.BASE),
        *manipulator.GetPtrCapabilityValue("forearm", "z", manipulator.MIN),
        *manipulator.GetPtrCapabilityValue("forearm", "z", manipulator.MAX));
    //---
    EndDrawing();
    //---
  }

  manipulator.Finish();
  CloseWindow();
  return 0;
}
