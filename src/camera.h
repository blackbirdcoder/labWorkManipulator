#pragma once
#include <raylib.h>

class PresentationCamera {
public:
  PresentationCamera();
  Camera3D Get();
  void Run(CameraMode mode);

private:
  Camera3D camera;
};