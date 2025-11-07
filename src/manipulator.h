#pragma once
#include <raylib.h>
#include <map>

class Manipulator {
public:
  Manipulator();
  void Exploitation();
  void Finish();
private:
std::map<const char*, Model> model;
float scale;
};
