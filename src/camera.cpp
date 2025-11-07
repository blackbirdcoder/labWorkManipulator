#include "camera.h"
#include <raylib.h>

PresentationCamera::PresentationCamera() {
  camera = Camera3D();
  camera.position = {5.0f, 5.0f, 5.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.projection = CAMERA_PERSPECTIVE;
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;

  titles = {"Camera Orbit", "Camera Freeze"};
  state = false;
}

Camera3D PresentationCamera::Get() { return camera; }
void PresentationCamera::Run() {
  UpdateCamera(&camera, state ? CAMERA_ORBITAL : CAMERA_CUSTOM);
}
const char *PresentationCamera::GetTitle() { return titles[state]; }
