#ifndef LIGHTGRID_H
#define LIGHTGRID_H

#include <Arduino.h>
#include <FastLED.h>
#include <Point.h>

class LightGrid {
  public:
    LightGrid();
    void setBrightness(int brightness);
    void drawPixel(int x, int y, CRGB color);
    void drawPixel(struct Point p, CRGB color);
    void clearPixel(int x, int y);
    void clearPixel(struct Point p);
    void drawRect(int length, int height, int startX, int startY, CRGB color);
    void drawRect(int length, int height, struct Point startPoint, CRGB color);
    void drawLine(struct Point a, struct Point b, CRGB color);
    void clear();
    void render();
};

#endif