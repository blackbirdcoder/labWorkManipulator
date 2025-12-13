// clang-format off
#include "manipulator.h"
#include "settings.h"
#include <raylib.h>
#include "camera.h"
#include "ui.h"
#define RLIGHTS_IMPLEMENTATION
#include "lighting.h"
#include <rlgl.h>
#include <iostream>
// clang-format on

int main(void) {
  InitWindow(W_WIDTH, W_HEIGHT, TITLE);
  SetTargetFPS(FPS);
  PresentationCamera preCamera = PresentationCamera();
  Lighting lighting = Lighting("shaders/lighting.vs", "shaders/lighting.fs");
  lighting.CreateAmbient();
  const char *spotlight = "spotlight";
  lighting.Point(spotlight, (Vector3){1.70f, 2.90f, 3.90f}, palette.spotlight);
  Manipulator manipulator = Manipulator(lighting.GetShader());
  GUI gui = GUI();

  while (!WindowShouldClose()) {
    //--- Update
    preCamera.Run();
    lighting.Update();
    //---

    //--- Draw
    BeginDrawing();
    ClearBackground(palette.background);
    BeginMode3D(preCamera.Get());
    BeginShaderMode(*lighting.GetShader());
    manipulator.StaticStart();
    manipulator.ForearmMove();
    manipulator.ArmMove();
    manipulator.WristMove();
    manipulator.EffectorMove();
    DrawGrid(10, 0.5f);
    EndShaderMode();
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
  lighting.Unload();
  CloseWindow();
  return 0;
}
