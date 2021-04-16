#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include "ui_utils.h"

int main_menu(){
  clearScreen(COLOR_BLUE);
  drawString5x7(30,10, "COLOR JAM!", COLOR_BLACK, COLOR_BLUE);
  drawString5x7(30,20, "The rules:", COLOR_BLACK, COLOR_BLUE);
  drawString5x7(5,30, "-Go to the indicated", COLOR_BLACK, COLOR_BLUE);
  drawString5x7(5,40, " color by the word", COLOR_BLACK, COLOR_BLUE);
  drawString5x7(5,60, "-Press S1 to play.", COLOR_BLACK, COLOR_BLUE);

  
  while(1){
    u_int switches5 = p2sw_read();
    char start_state = (switches5 & (1<<0)) ? '-' : '1';
    if (start_state == '1')
      return 1;
  }
  return 0;
}

int game_over(){
  //enableWDTInterrupts(); //periodic interrupts
  //or_sr(0x8); //enable interrupts
  clearScreen(COLOR_BLUE);
  drawString5x7(30,10, "GAME OVER", COLOR_BLACK, COLOR_BLUE);
  //TODO integrate high score functionality. Written in assembly
  drawString5x7(05,30, "S1 to try again.", COLOR_BLACK, COLOR_BLUE);

  while (1){
    u_int switches_states = p2sw_read();
    char s1_state = (switches_states & (1<<0)) ? '-' : '1'; //char is equal to '1' when pressed.
    if (s1_state == '1')
      return 1;
    //or_sr(0x10); //turns CPU off
  }
  return 0;
}
