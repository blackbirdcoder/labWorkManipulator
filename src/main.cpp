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
    manipulator.StaticStart();
    manipulator.ForearmMove();
    manipulator.ArmMove();
    manipulator.WristMove();
    DrawGrid(10, 0.5f);
    EndMode3D();
    //---GUI
    gui.StateSwitchButton(((float)GetScreenWidth() - 130), &preCamera.state,
                          preCamera.GetTitle());
    gui.ControlRange(
        20.0f, "Forearm Z:",
        manipulator.GetPtrCapabilityValue("forearm", "z", manipulator.BASE),
        *manipulator.GetPtrCapabilityValue("forearm", "z", manipulator.MIN),
        *manipulator.GetPtrCapabilityValue("forearm", "z", manipulator.MAX));

    gui.ControlRange(
        45.0f, "Forearm Y:",
        manipulator.GetPtrCapabilityValue("forearm", "y", manipulator.BASE),
        *manipulator.GetPtrCapabilityValue("forearm", "y", manipulator.MIN),
        *manipulator.GetPtrCapabilityValue("forearm", "y", manipulator.MAX));

    gui.ControlRange(
        70.0f, "Forearm X:",
        manipulator.GetPtrCapabilityValue("forearm", "x", manipulator.BASE),
        *manipulator.GetPtrCapabilityValue("forearm", "x", manipulator.MIN),
        *manipulator.GetPtrCapabilityValue("forearm", "x", manipulator.MAX));

    gui.ControlRange(
        95.0f, "Arm X:",
        manipulator.GetPtrCapabilityValue("arm", "x", manipulator.BASE),
        *manipulator.GetPtrCapabilityValue("arm", "x", manipulator.MIN),
        *manipulator.GetPtrCapabilityValue("arm", "x", manipulator.MAX));
    //---
    EndDrawing();
    //---
  }

  manipulator.Finish();
  CloseWindow();
  return 0;
}
