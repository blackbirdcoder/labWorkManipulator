#include "manipulator.h"
#include "settings.h"
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

Manipulator::Manipulator(Shader *shader) {
  this->shader = shader;
  scale = 1.0f;

  model["basis"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 1.0f));
  model["sleeve"] = LoadModelFromMesh(GenMeshCylinder(0.3f, 0.2f, 12));
  model["joint"] = LoadModelFromMesh(GenMeshSphere(0.25f, 12, 12));
  model["forearm"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.3f, 0.35f));
  model["arm"] = LoadModelFromMesh(GenMeshCube(1.0f, 0.2f, 0.2f));
  model["wrist"] = LoadModelFromMesh(GenMeshCube(0.2f, 0.1f, 0.1f));
  model["effector"] = LoadModelFromMesh(GenMeshTorus(0.3f, 0.2f, 12, 12));

  textureSwatch["one"] = LoadTexture("texture/rustyB.jpg");
  textureSwatch["two"] = LoadTexture("texture/rustyC.jpg");
  textureSwatch["three"] = LoadTexture("texture/rustyA.jpg");

  model["basis"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["one"];
  model["sleeve"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["one"];
  model["forearm"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["one"];
  model["arm"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["three"];
  model["wrist"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["two"];
  model["effector"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["two"];
  model["joint"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture =
      textureSwatch["two"];

  for (const auto pair : model) {
    pair.second.materials[0].shader = *this->shader;
  }

  capability["forearm"]["z"] = {0.0f, -15.0f, 15.0f};
  capability["forearm"]["y"] = {0.0f, 0.0f, 180.0f};
  capability["forearm"]["x"] = {0.0f, -5.0f, 5.0f};
  capability["arm"]["x"] = {0.1f, 0.1f, 0.5f};
}

void Manipulator::StaticStart() {
  DrawModel(model["basis"], (Vector3){0.0f, 0.0f, 0.0f}, scale, WHITE);
  DrawModel(model["sleeve"], (Vector3){0.0f, 0.1f, 0.0f}, scale, WHITE);
  DrawModel(model["joint"], (Vector3){0.0f, 0.3f, 0.0f}, scale, WHITE);
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
  DrawModel(model["forearm"], Vector3Zero(), scale, WHITE);
  rlPopMatrix();
}

void Manipulator::ArmMove() {
  float posX = capability["arm"]["x"][BASE];
  float z = capability["forearm"]["z"][BASE];
  float y = capability["forearm"]["y"][BASE];
  float x = capability["forearm"]["x"][BASE];

  rlPushMatrix();
  rlRotatef(y, 0.0f, 1.0f, 0.0f);
  rlRotatef(z, 0.0f, 0.0f, 1.0f);
  rlRotatef(x, 1.0f, 0.0f, 0.0f);
  rlTranslatef(posX, 0.55f, 0.0f);
  DrawModel(model["arm"], Vector3Zero(), scale, WHITE);
  rlPopMatrix();
}

void Manipulator::WristMove() {
  float increase = 0.5f;
  float posX = capability["arm"]["x"][BASE] + increase;
  float z = capability["forearm"]["z"][BASE];
  float y = capability["forearm"]["y"][BASE];
  float x = capability["forearm"]["x"][BASE];

  rlPushMatrix();
  rlRotatef(y, 0.0f, 1.0f, 0.0f);
  rlRotatef(z, 0.0f, 0.0f, 1.0f);
  rlRotatef(x, 1.0f, 0.0f, 0.0f);
  rlTranslatef(posX, 0.55f, 0.0f);
  DrawModel(model["wrist"], Vector3Zero(), scale, WHITE);
  rlPopMatrix();
}

void Manipulator::EffectorMove() {
  float increase = 0.7f;
  float posX = capability["arm"]["x"][BASE] + increase;
  float z = capability["forearm"]["z"][BASE];
  float y = capability["forearm"]["y"][BASE];
  float x = capability["forearm"]["x"][BASE];

  rlPushMatrix();
  rlRotatef(y, 0.0f, 1.0f, 0.0f);
  rlRotatef(z, 0.0f, 0.0f, 1.0f);
  rlRotatef(x, 1.0f, 0.0f, 0.0f);
  rlTranslatef(posX, 0.55f, 0.0f);
  DrawModel(model["effector"], Vector3Zero(), scale, WHITE);
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

  for (const auto pair : textureSwatch) {
    UnloadTexture(pair.second);
  }
}