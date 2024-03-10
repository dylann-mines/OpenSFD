#include <lightgrid.h>
#include <Point.h>

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
    struct Point p;
    p.x = 1;
    p.y = 1; 
    lg.drawPixel(p, CRGB(r, g, b));
		lg.render();
  }
}