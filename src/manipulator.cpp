#include "manipulator.h"
#include "settings.h"
#include <raylib.h>
#include <rlgl.h>

Manipulator::Manipulator() {
  scale = 1.0f;

  model["basis"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 1.0f));
  model["sleeve"] = LoadModelFromMesh(GenMeshCylinder(0.3f, 0.2f, 12));
  model["joint"] = LoadModelFromMesh(GenMeshSphere(0.25f, 12, 12));
  model["forearm"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 0.35f));
  model["arm"] = LoadModelFromMesh(GenMeshCube(0.1f, 0.2f, 0.2f));

  capability["forearm"]["z"] = {0.0f, -15.0f, 15.0f};
  capability["forearm"]["y"] = {0.0f, 0.0f, 180.0f};
  capability["forearm"]["x"] = {0.0f, -5.0f, 5.0f};
  capability["arm"]["x"] = {0.5f, 0.5f, 10.0f};
}

void Manipulator::StaticStart() {
  DrawModel(model["basis"], (Vector3){0.0f, 0.0f, 0.0f}, scale, palette.basic);
  DrawModel(model["sleeve"], (Vector3){0.0f, 0.1f, 0.0f}, scale,
            palette.covert);
  DrawModel(model["joint"], (Vector3){0.0f, 0.3f, 0.0f}, scale, palette.chunk);
}

void Manipulator::ForearmMove() {
  float z = capability["forearm"]["z"][BASE];
  float y = capability["forearm"]["y"][BASE];
  float x = capability["forearm"]["x"][BASE];

  rlPushMatrix();
  rlRotatef(y, 0.0f, 1.0f, 0.0f);
  rlRotatef(z, 0.0f, 0.0f, 1.0f);
  rlRotatef(x, 1.0f, 0.0f, 0.0f);
  rlTranslatef(0.0f, 0.55f, 0.0f);
  DrawModel(model["forearm"], (Vector3){0.0f, 0.0f, 0.0f}, scale,
            palette.basic);
  rlPopMatrix();
}

void Manipulator::ArmMove() {
  float lenX = capability["arm"]["x"][BASE];
  float z = capability["forearm"]["z"][BASE];
  float y = capability["forearm"]["y"][BASE];

  rlPushMatrix();
  rlRotatef(y, 0.0f, 1.0f, 0.0f);
  rlRotatef(z, 0.0f, 0.0f, 1.0f);
  rlTranslatef(0.5f, 0.55f, 0.0f);
  rlScalef(lenX, 1.0f, 1.0f);
  DrawModel(model["arm"], (Vector3){0.0f, 0.0f, 0.0f}, scale, palette.chunk);
  rlPopMatrix();
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