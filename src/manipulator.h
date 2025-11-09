#pragma once
#include <map>
#include <raylib.h>
#include <vector>

class Manipulator {
public:
  Manipulator();
  enum Capability { BASE, MIN, MAX };
  void Exploitation();
  void Finish();
  void ForearmMove();
  float *GetPtrCapabilityValue(const char *, const char *, Capability);

private:
  std::map<const char *, Model> model;
  std::map<const char *, std::map<const char *, std::vector<float>>> capability;
  float scale;
};
