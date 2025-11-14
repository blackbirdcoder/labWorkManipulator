#pragma once
#include <map>
#include <raylib.h>
#include <vector>

class Manipulator {
public:
  Manipulator();
  enum Capability { BASE, MIN, MAX };
  void StaticStart();
  void Finish();
  void ForearmMove();
  void ArmMove();
  void WristMove();
  float *GetPtrCapabilityValue(const char *, const char *, Capability);

private:
  std::map<const char *, Model> model;
  std::map<const char *, std::map<const char *, std::vector<float>>> capability;
  float scale;
};
