#pragma once
#include <raylib.h>
#include <string>
#include <vector>

class GUI {
public:
  GUI();
  void StateSwitchButton(float, bool *, const char *);
  void ControlRange(const char *, float *, float, float);

private:
};
