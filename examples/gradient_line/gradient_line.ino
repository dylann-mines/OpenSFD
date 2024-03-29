#include "lightgrid.h"


LightGrid lg;

const int FADE_LEN = 64;
int lastX[FADE_LEN+1] = {-1};
// int lastY[FADE_LEN+1] = {-1};

void setup() {
  // put your setup code here, to run once:
  lg = LightGrid();
  lg.setBrightness(5);

  // for(int x = 1; x <= 64; x++) {
  //   for(int y = 1; y<=8; y++) {
  //     lg.drawPixel(x, y, CRGB(45, 45, 45));
  //   }
  // }
  // lg.render();
}

void loop() {
  for(int x = 1; x <= 64; x++) {

    for(int y = 1; y<=8; y++) {
      lg.drawPixel(x, y, CRGB(255/2,0,255/2));
    }


    for(int i = 0; i < FADE_LEN; i++) {
      if(lastX[i] >= 1) {
        int bright = 255-(i*255/FADE_LEN);
        for(int y = 1; y<=8; y++) {
          lg.drawPixel(lastX[i], y, CRGB(bright/2, 0, 255-bright/2));
        }
      }
    }

    // for(int y = 1; y<=8; y++) {
    //   lg.drawPixel(lastX[FADE_LEN], y, CRGB(45,45,45));
    //   //lg.clearPixel(lastX[FADE_LEN], lastY[FADE_LEN]);

    //   // lastY[0] = y;
    // }

    for(int i = FADE_LEN; i > 0 ; i--) {
      lastX[i] = lastX[i-1];
    }
    lastX[0] = x;

    lg.render();
    delay(10);
  }
}