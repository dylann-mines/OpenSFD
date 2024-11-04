#include "lightgrid.h"
#include "DisplayChar.h"

LightGrid lg;

String message = "Hello Room";
int message_width;
int x_start = 0;

void setup() {
  // put your setup code here, to run once:
  lg = LightGrid();
  lg.setBrightness(5);

  message_width = message.length()*6;
}

void loop() {
  int x_prime = 0;
  for(char chr : message){
    DisplayChar cur_letter = DisplayChar(chr);
    // if(x_prime < 64 - 5) {
    cur_letter.draw_to_lightgrid(x_start + x_prime, 1, lg);
    // }
    x_prime += 6;
  }
  lg.render();
  delay(200);

  if(message_width > 64) {
    if (x_start <= 64 - message_width) {
      x_start = 0;
    } else {
      x_start -= 1;
    }
  }
}