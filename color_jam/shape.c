#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"

void drawDiamond(u_char size, u_char offset_r, u_char offset_c){
  for (u_char r = 0; r <= size; r++){
    for (u_char c = 0; c <= (size-r); c++){
      drawPixel(offset_c - c, offset_r - r, COLOR_RED);
      drawPixel(offset_c - c, offset_r + r, COLOR_GREEN);
    }
  }
  for (u_char r = 0; r <= size/2; r++){
    for (u_char c = 0; c <= (size-r); c++){
      drawPixel(offset_c - c, offset_r - r, COLOR_GREEN);
      drawPixel(offset_c + c, offset_r - r, COLOR_GREEN);
    }
  }
  for (u_char r = 0; r <= size/2; r++){
    for (u_char c = 0; c <= (size-r); c++){
      drawPixel(offset_c + c, offset_r + r, COLOR_RED);
      drawPixel(offset_c - c, offset_r + r, COLOR_RED);
    }
  }
  for (u_char r = 0; r <= size; r++){
    for (u_char c = 0; c <= (size-r/2); c++){
      drawPixel(offset_c + c, offset_r + r, COLOR_RED);
      drawPixel(offset_c + c, offset_r - r, COLOR_GREEN);
    }
  }
  
}
