#include "manipulator.h"
#include "settings.h"
#include <raylib.h>
#include <raymath.h>

Manipulator::Manipulator() {
  scale = 1.0f;
  model["basis"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 1.0f));
  model["sleeve"] = LoadModelFromMesh(GenMeshCylinder(0.3f, 0.2f, 12));
  model["joint"] = LoadModelFromMesh(GenMeshSphere(0.25f, 12, 12));
  model["forearm"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 0.35f));
}

void Manipulator::Exploitation() {
  DrawModel(model["basis"], (Vector3){0.0f, 0.0f, 0.0f}, scale, palette.basic);
  DrawModel(model["sleeve"], (Vector3){0.0f, 0.1f, 0.0f}, scale,
            palette.covert);
  DrawModel(model["joint"], (Vector3){0.0f, 0.3f, 0.0f}, scale, palette.chunk);
  DrawModel(model["forearm"], (Vector3){0.0f, 0.55f, 0.0f}, scale,
            palette.basic);
}

void Manipulator::Finish() {
  for (const auto pair : model) {
    UnloadModel(pair.second);
  }
}