#include <lightgrid.h>

#define NUM_LEDS 512
#define NUM_ROWS 8
#define NUM_COLS 64
#define DATA_PIN 23

CRGB leds[NUM_LEDS];

int getIndexFromCoordinate(int x, int y);

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

void LightGrid::clearPixel(int x, int y) {
  leds[getIndexFromCoordinate(x, y)] = CRGB::Black;
}

void LightGrid::drawRect(int length, int height, int startX, int startY, CRGB color) {
  for (int i = startY; i < startY + length; i++) {
    for (int j = startX; j < startX + height; j++) {
      drawPixel(i, j, color);
    }
  }
}

void LightGrid::drawLine(int startX, int startY, int endX, int endY, CRGB color) {
  // Implement Bresenham's Line Algorithm
  int deltaY = -(endY - startY);
  int deltaX = endX - startX;
  float slope = ((float)(deltaY))/(deltaX);

  int a;
  int b;
  int p;

  int currentPixelX = startX;
  int currentPixelY = startY;

  drawPixel(currentPixelX, currentPixelY, color);

  if (abs(deltaY) > abs(deltaX)) {
    a = 2 * (endX - currentPixelX);
    b = a - (2 * -(endY - currentPixelY));
    p = a + (endY - currentPixelY);

    while (currentPixelY != endY) {
      Serial.println(p);
      if (p < 0) {
        currentPixelY--;
        drawPixel(currentPixelX, currentPixelY, color);
        p += a;
      } else {
        if (slope < 0) {
          currentPixelX++;
        } else {
          currentPixelX--;
        }
        currentPixelY++;
        drawPixel(currentPixelX, currentPixelY, color);
        p += b;
      }
    }
  } else {
    a = abs(2 * -(endY - currentPixelY));
    b = a - (2 * (endX - currentPixelX));
    p = a - (endX - currentPixelX);

    while (currentPixelX != endX) {
      if (p < 0) {
        currentPixelX++;
        drawPixel(currentPixelX, currentPixelY, color);
        p += a;
      } else {
        if (slope < 0) {
          currentPixelY++;
        } else {
          currentPixelY--;
        }
        currentPixelX++;
        drawPixel(currentPixelX, currentPixelY, color);
        p += b;
      }
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