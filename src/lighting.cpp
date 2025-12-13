#include "lighting.h"
#include <raylib.h>
#include <raymath.h>

Lighting::Lighting(const char *fileVS, const char *fileFS) {
  shader = LoadShader(fileVS, fileFS);
  shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(shader, "matModel");
  shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
}

const float Lighting::ambient[4] = {0.2, 0.2, 0.2, 1.0};

void Lighting::CreateAmbient() {
  int amb = GetShaderLocation(shader, "ambient");
  SetShaderValue(shader, amb, ambient, SHADER_UNIFORM_VEC4);
}

void Lighting::Point(const char *key, Vector3 pos, Color color) {
  light[key] = CreateLight(LIGHT_POINT, pos, Vector3Zero(), color, shader);
}

Shader *Lighting::GetShader() { return &shader; }

Light *Lighting::GetLight(const char *key) { return &light[key]; }

void Lighting::Unload() { UnloadShader(shader); }

void Lighting::Update() {
  for (const auto pair : light) {
    UpdateLightValues(shader, pair.second);
  }
}