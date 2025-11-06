#include "camera.h"

PresentationCamera::PresentationCamera() {
  camera = Camera3D();
  camera.position ={10.0f, 10.0f, 10.0f};
  camera.target = {0.0f, 0.0f, 0.0f};
  camera.projection = CAMERA_PERSPECTIVE;
  camera.up = {0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
}

Camera3D PresentationCamera::Get() { return camera; }
void PresentationCamera::Run(CameraMode mode) { UpdateCamera(&camera, mode); }
