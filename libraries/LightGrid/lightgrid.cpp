#include <lightgrid.h>

#define NUM_LEDS 512
#define NUM_ROWS 8
#define NUM_COLS 64
#define DATA_PIN 23

CRGB leds[NUM_LEDS];

int getIndexFromCoordinate(int x, int y);
int getIndexFromCoordinate(Point p);

LightGrid::LightGrid() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void LightGrid::setBrightness(int brightness) {
  if (brightness > 255) {
    FastLED.setBrightness(255);
  } else if (brightness < 0) {
    FastLED.setBrightness(0);
  } else {
    FastLED.setBrightness(brightness);
  }
}

void LightGrid::drawPixel(int x, int y, CRGB color) {
  leds[getIndexFromCoordinate(x, y)] = color;
}

void LightGrid::drawPixel(struct Point p, CRGB color) {
  leds[getIndexFromCoordinate(p)] = color;
}

void LightGrid::clearPixel(int x, int y) {
  leds[getIndexFromCoordinate(x, y)] = CRGB::Black;
}

void LightGrid::clearPixel(struct Point p) {
  leds[getIndexFromCoordinate(p.x, p.y)] = CRGB::Black;
}

void LightGrid::drawRect(int length, int height, int startX, int startY, CRGB color) {
  for (int i = startY; i < startY + length; i++) {
    for (int j = startX; j < startX + height; j++) {
      drawPixel(i, j, color);
    }
  }
}

void LightGrid::drawRect(int length, int height, struct Point startPoint, CRGB color) {
  for (int i = startPoint.y; i < startPoint.y + length; i++) {
    for (int j = startPoint.x; j < startPoint.x + height; j++) {
      drawPixel(i, j, color);
    }
  }
}

void LightGrid::clear() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}

void LightGrid::render() {
  FastLED.show();
}

int getIndexFromCoordinate(int x, int y) {
  if (x % 2 == 0) return (((x - 1) * NUM_ROWS) + (NUM_ROWS - y));
  return (((x - 1) * NUM_ROWS) + (y - 1));
}

int getIndexFromCoordinate(struct Point p) {
  if (p.x % 2 == 0) return (((p.x - 1) * NUM_ROWS) + (NUM_ROWS - p.y));
  return (((p.x - 1) * NUM_ROWS) + (p.y - 1));
}