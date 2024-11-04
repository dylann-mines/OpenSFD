#include "lightgrid.h"
#include "DisplayChar.h"

LightGrid lg;

String message = "HELLO ROOM";

void setup() {
  // put your setup code here, to run once:
  lg = LightGrid();
  lg.setBrightness(5);

}

void loop() {

  int x_prime = 0;
  for(char chr : message){
    DisplayChar cur_letter = DisplayChar(chr);
    if(x_prime < 64 - 5) {
      cur_letter.draw_to_lightgrid(x_prime, 1, lg);
    }
    x_prime += 6;
  }
  lg.render();
  delay(100);
}