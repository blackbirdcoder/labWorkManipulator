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

  capability["forearm"]["z"] = {0.0f, -15.0f, 15.0f};
  capability["forearm"]["y"] = {0.0f, 0.0f, 180.0f};
  capability["forearm"]["x"] = {0.0f, -5.0f, 5.0f};
  
}

void Manipulator::Exploitation() {
  DrawModel(model["basis"], (Vector3){0.0f, 0.0f, 0.0f}, scale, palette.basic);
  DrawModel(model["sleeve"], (Vector3){0.0f, 0.1f, 0.0f}, scale,
            palette.covert);
  DrawModel(model["joint"], (Vector3){0.0f, 0.3f, 0.0f}, scale, palette.chunk);
  DrawModel(model["forearm"], (Vector3){0.0f, 0.55f, 0.0f}, scale,
            palette.basic);
}

void Manipulator::ForearmMove() {
  float z = DEG2RAD * capability["forearm"]["z"][BASE];
  float y = DEG2RAD * capability["forearm"]["y"][BASE];
  float x = DEG2RAD * capability["forearm"]["x"][BASE];

  model["forearm"].transform = MatrixRotateXYZ((Vector3){x, y, z});
}

float *Manipulator::GetPtrCapabilityValue(const char *type, const char *param,
                                          Capability value) {
  return &capability[type][param][value];
}

void Manipulator::Finish() {
  for (const auto pair : model) {
    UnloadModel(pair.second);
  }
}