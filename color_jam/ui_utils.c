#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <stdio.h>
#include "ui_utils.h"
#include "buzzer.h"
#include "assemblyCode.h"
#include "shape.h"

int main_menu(){
  configureClocks();
  lcd_init();

  clearScreen(COLOR_BLUE);
  while(1){
      drawString5x7(30,10, "COLOR JAM!", COLOR_BLACK, COLOR_BLUE);
      drawString5x7(30,20, "The rules:", COLOR_BLACK, COLOR_BLUE);
      drawString5x7(5,30, "-Go to the indicated", COLOR_BLACK, COLOR_BLUE);
      drawString5x7(5,40, " color by the word", COLOR_BLACK, COLOR_BLUE);
      drawString5x7(5,60, "-Press S1 to play.", COLOR_BLACK, COLOR_BLUE);
      u_char size = 20, offset_r = 100, offset_c = 65;
      drawDiamond(size, offset_r, offset_c);
      while(1){
	u_int switches5 = p2sw_read();
	char start_state = (switches5 & (1<<0)) ? '-' : '1';
	if (start_state == '1')
	  return 1;
      }
  }
  return 0;
}

int game_over(int highScoreTemp, int highScoreNum){
  buzzer_init();
  char text[4];

  int newHs = isHighScore(highScoreTemp, highScoreNum);
  clearScreen(COLOR_RED);
  drawString11x16(5,10, "GAME OVER", COLOR_BLACK, COLOR_RED);
  sprintf(text, "%d", newHs);
  drawString5x7(05,30, "HIGHSCORE:", COLOR_BLACK, COLOR_RED);
  drawString5x7(80, 30, text, COLOR_BLACK, COLOR_RED);
  drawString5x7(05,50, "S1 to try again.", COLOR_BLACK, COLOR_RED);
  
  
  while (1){
    buzzer_set_period(1000);
    u_int switches_states = p2sw_read();
    char s1_state = (switches_states & (1<<0)) ? '-' : '1'; //char is equal to '1' when pressed.
    if (s1_state == '1'){
      buzzer_set_period(0);
      return newHs;
    }
  }
  return 0;
}
