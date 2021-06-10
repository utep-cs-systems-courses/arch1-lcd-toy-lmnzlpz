#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ui_utils.h"
#include "buzzer.h"
#include "assemblyCode.h"

int highScoreNum = 0;
int highScoreTemp = 0;
/** Main function. Makes everything run together.*/
void main()
{
 START:
  configureClocks();
  lcd_init();
  p2sw_init(15);
  or_sr(0x8); /* GIE (enable interrupts) */
  u_char width = screenWidth, height = screenHeight;
  main_menu();
  
  
  int program_counter = 0;
  while (1) {
    char *goto_color[] = {"RED", "YELLOW", "GREEN", "PURPLE"};
    u_int switches = p2sw_read(), i;
    char str[5];
    int rand_index = rand()%4;
    char *next_color = goto_color[rand_index];
    char *current_color;
   
    if (program_counter == 0){
      current_color = "RED";
    }
    program_counter++;
    for (i = 0; i < 4; i++){
      str[i] = (switches & (1<<i)) ? '-' : '1'+i;
      if (str[i] == '1'){
	clearScreen(COLOR_RED);
	if (current_color != "RED"){
	  highScoreNum = game_over(highScoreTemp, highScoreNum);
	  goto START;
	}
	current_color = next_color;
	highScoreTemp++;
	drawString11x16(width/4,height/4, next_color, COLOR_BLACK, COLOR_RED);
      }
      else if (str[i] == '2'){
	clearScreen(COLOR_PURPLE);
	if (current_color != "PURPLE"){
	  highScoreNum = game_over(highScoreTemp, highScoreNum);
	  goto START;
	}
	current_color = next_color;
	highScoreTemp++;
	drawString11x16(width/4,height/4, next_color, COLOR_BLACK, COLOR_PURPLE);
      }
      else if (str[i] == '3'){
	clearScreen(COLOR_YELLOW);
	if (current_color != "YELLOW"){
	  highScoreNum = game_over(highScoreTemp, highScoreNum);
	  goto START;
	} 
	current_color = next_color;
	highScoreTemp++;
	drawString11x16(width/4,height/4, next_color, COLOR_BLACK, COLOR_YELLOW);
      }
      else if (str[i] == '4'){
	clearScreen(COLOR_GREEN);
	if (current_color != "GREEN"){
	  highScoreNum = game_over(highScoreTemp, highScoreNum);
	  goto START;
	}
	current_color = next_color;
	highScoreTemp++;
	drawString11x16(width/4,height/4, next_color, COLOR_BLACK, COLOR_GREEN);
      }
    }
  } 
}
