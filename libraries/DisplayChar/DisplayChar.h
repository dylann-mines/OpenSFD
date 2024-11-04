#ifndef DISPLAYCHAR_H
#define DISPLAYCHAR_H

#include <lightgrid.h>

class DisplayChar {
  public:
    int width;
    bool arr[7][5];

    DisplayChar() {
    }

    DisplayChar(char chr) {
      set_pattern_with_key(chr);
    }

    // Given x and y (upper left corner), draw the letter onto Lightgrid
    void draw_to_lightgrid(int x_prime, int y_prime, LightGrid lg) {
      for(int x = 1; x <= 5; x++) {
        for(int y = 1; y <= 7; y++) {
          if (arr[y-1][x-1]) {
            lg.drawPixel(x + x_prime, y + y_prime, CRGB(100,100,100));
          } else {
            lg.drawPixel(x + x_prime, y + y_prime, CRGB(0,0,0));
          }
        }
      }
    }

    void set_pattern(bool char_pattern[7][5]) {
      for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 5; j++) {
          arr[i][j] = char_pattern[i][j];
        }
      }
    }

    void set_pattern_with_key(char key) {
      if(key == ' ') {
        bool pattern[7][5] = {
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0}
        };
        set_pattern(pattern);
      } else if(key == 'A') {
        bool pattern[7][5] = {
            {0, 1, 1, 1, 0},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1}
          };
        set_pattern(pattern);
      } else if(key == 'B') {
        bool pattern[7][5] = {
          {1, 1, 1, 1, 0},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 1, 1, 0},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 1, 1, 0}
        };
        set_pattern(pattern);
      } else if(key == 'C') {
        bool pattern[7][5] = {
          {1, 1, 1, 1, 1},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1}
        };
        set_pattern(pattern);
      } else if(key == 'D') {
        bool pattern[7][5] = {
          {1, 1, 1, 1, 0},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 1, 1, 0}
        };
        set_pattern(pattern);
      } else if(key == 'E') {
        bool pattern[7][5] = {
          {1, 1, 1, 1, 1},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1}
        };
        set_pattern(pattern);
      }
      // TODO: F - G
      else if(key == 'H') {
        bool pattern[7][5] = {
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 1, 1, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1}
        };
        set_pattern(pattern);
      }
      // TODO: I - K
      else if(key == 'L') {
        bool pattern[7][5] = {
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1}
        };
        set_pattern(pattern);
      }
      else if(key == 'M') {
        bool pattern[7][5] = {
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 0, 1, 1},
          {1, 0, 1, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1}
        };
        set_pattern(pattern);
      }
      // TODO: N
      else if(key == 'O') {
        bool pattern[7][5] = {
          {0, 1, 1, 1, 0},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {0, 1, 1, 1, 0}
        };
        set_pattern(pattern);
      }
      // TODO: P - Q
      else if(key == 'R') {
        bool pattern[7][5] = {
          {1, 1, 1, 1, 0},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 1, 1, 0},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1}
        };
        set_pattern(pattern);
      }
      // TODO: S - V
      else if(key == 'W') {
        bool pattern[7][5] = {
          {1, 0, 0, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 1, 0, 1},
          {1, 0, 1, 0, 1},
          {1, 0, 1, 0, 1},
          {1, 1, 0, 1, 1},
          {1, 0, 0, 0, 1}
        };
        set_pattern(pattern);
      }
      // TODO: X - Z
      // TODO: a - z
      // TODO: 0 - 9
      else {
        // '?'
        bool pattern[7][5] = {
          {0, 1, 1, 1, 0},
          {0, 1, 0, 1, 0},
          {0, 0, 0, 1, 0},
          {0, 0, 1, 0, 0},
          {0, 0, 1, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 1, 0, 0}
        };
        set_pattern(pattern);
      }
    }
};

#endif