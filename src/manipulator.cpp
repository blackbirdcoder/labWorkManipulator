#include "manipulator.h"
#include "settings.h"
#include <raylib.h>

Manipulator::Manipulator() {
  model["basis"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 1.0f));
  model["sleeve"] = LoadModelFromMesh(GenMeshCylinder(0.3f, 0.2f, 12));
}

void Manipulator::Exploitation() {
  DrawModel(model["basis"], (Vector3){0.0f, 0.0f, 0.0f}, 1.0f, palette.basic);
  DrawModel(model["sleeve"], (Vector3){0.0f, 0.1f, 0.0f}, 1.0f, palette.basic);
}

void Manipulator::Finish() {
  UnloadModel(model["basis"]);
  UnloadModel(model["sleeve"]);
}