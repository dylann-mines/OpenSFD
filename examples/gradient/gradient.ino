#include "lightgrid.h"


LightGrid lg;

const int FADE_LEN = 256;
int lastX[FADE_LEN+1] = {-1};
int lastY[FADE_LEN+1] = {-1};

void setup() {
  // put your setup code here, to run once:
  lg = LightGrid();
  lg.setBrightness(5);

  for(int x = 1; x <= 64; x++) {
    for(int y = 1; y<=8; y++) {
      lg.drawPixel(x, y, CRGB(45, 45, 45));
    }
  }
  lg.render();
}

void loop() {
  for(int x = 1; x <= 64; x++) {

    for(int y = 1; y<=8; y++) {
      lg.drawPixel(x, y, CRGB(0,255,0));

      for(int i = 0; i < FADE_LEN; i++) {
        if(lastX[i] >= 1) {
          int bright = 255-(i*255/FADE_LEN);
          lg.drawPixel(lastX[i], lastY[i], CRGB(0, bright, 255-bright));
        }
      }

      // delay(100);

      lg.drawPixel(lastX[FADE_LEN], lastY[FADE_LEN], CRGB(45,45,45));
      // lg.clearPixel(lastX[FADE_LEN], lastY[FADE_LEN]);
      for(int i = FADE_LEN; i > 0 ; i--) {
        lastX[i] = lastX[i-1];
        lastY[i] = lastY[i-1];
      }
      lastX[0] = x;
      lastY[0] = y;

      lg.render();
    }
  }
}
