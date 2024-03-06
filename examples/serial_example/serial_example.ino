#include <lightgrid.h>

LightGrid lg;

void setup() {
  Serial.begin(9600);
  lg = LightGrid();
}

void loop() {
  if (Serial.available() > 0) {
		char r = Serial.read();
		char g = Serial.read();
    char b = Serial.read();
    lg.drawPixel(1, 1, CRGB(r, g, b));
		lg.render();
  }
}