#pragma once
#include <map>
#include <raylib.h>
#include <vector>

class Manipulator {
public:
  Manipulator(Shader*);
  enum Capability { BASE, MIN, MAX };
  void StaticStart();
  void Finish();
  void ForearmMove();
  void ArmMove();
  void WristMove();
  void EffectorMove();
  float *GetPtrCapabilityValue(const char *, const char *, Capability);

private:
  std::map<const char *, Texture2D> textureSwatch; 
  std::map<const char *, Model> model;
  std::map<const char *, std::map<const char *, std::vector<float>>> capability;
  float scale;
  Shader *shader;
};
