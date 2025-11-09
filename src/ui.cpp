// clang-format off
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include "ui.h"
// clang-format on

GUI::GUI() { GuiLoadStyle("style_amber.rgs"); }

void GUI::StateSwitchButton(float btnPosX, bool *statePtr, const char *title) {
  if (GuiButton((Rectangle){btnPosX, 20, 110, 30}, title)) {
    *statePtr = !*statePtr;
  }
}

void GUI::ControlRange(const float PosY, const char *title, float *valuePtr, float minValue,
                       float maxValue) {
  GuiSliderBar((Rectangle){70, PosY, 100, 20}, title,
               TextFormat("%.2f", *valuePtr), valuePtr, minValue, maxValue);
}