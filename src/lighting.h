#pragma once
// clang-format off
#include <map>
#include <raylib.h>
#include "rlights.h"
// clang-format on

class Lighting {
public:
  Lighting(const char *fileVS, const char *fileFS);
  void CreateAmbient();
  Shader *GetShader();
  void Point(const char *, Vector3, Color);
  Light *GetLight(const char *);
  void Unload();
  void Update();
  static const float ambient[4];

private:
  std::map<const char *, Light> light;
  Shader shader;
};