#pragma once
#include <raylib.h>
#include <vector>

class PresentationCamera {
public:
  PresentationCamera();
  bool state;
  Camera3D Get();
  void Run();
  const char *GetTitle();

private:
  Camera3D camera;
  std::vector<const char *> titles;
};