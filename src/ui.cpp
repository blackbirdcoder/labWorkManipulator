// clang-format off
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include "ui.h"
#include "style_amber.h"
// clang-format on
GUI::GUI() { GuiLoadStyleAmber(); }

void GUI::StateSwitchButton(float btnPosX, bool *statePtr, const char *title) {
  if (GuiButton((Rectangle){btnPosX, 20, 110, 30}, title)) {
    *statePtr = !*statePtr;
  }
}

void GUI::ControlRange(const char* title, float *valuePtr, float minValue, float maxValue) {
  GuiSliderBar((Rectangle){70, 20, 100, 20}, title,
               TextFormat("%.2f", *valuePtr), valuePtr, minValue, maxValue);
}