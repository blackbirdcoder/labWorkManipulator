#pragma once
#include <raylib.h>

extern const int W_WIDTH;
extern const int W_HEIGHT;
extern const char *TITLE;
extern const int FPS;

struct Palette {
  Color background;
  Color basic;
  Color chunk;
  Color ui;
  Color covert;
};

extern const Palette palette;