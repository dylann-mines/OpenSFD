#ifndef LIGHTGRID_H
#define LIGHTGRID_H

#include <Arduino.h>
#include <FastLED.h>

class LightGrid {
  public:
    LightGrid();
    void setBrightness(int brightness);
    void drawPixel(int x, int y, CRGB color);
    void clearPixel(int x, int y);
    void drawRect(int length, int height, int startX, int startY, CRGB color);
    void drawLine(int startX, int startY, int endX, int endY, CRGB color);
    void clear();
    void render();
};

#endif