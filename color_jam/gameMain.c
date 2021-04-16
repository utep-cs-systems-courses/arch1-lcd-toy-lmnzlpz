/** \file lcddemo.c
 *  \brief A simple demo that draws a string and circle
 */

#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_over(){
  enableWDTInterrupts();
  clearScreen(COLOR_BLUE);
  drawString5x7(30,10, "GAME OVER", COLOR_BLACK, COLOR_BLUE);
  //TODO integrate high score functionality.
  drawString5x7(05,30, "S1 to try again.", COLOR_BLACK, COLOR_BLUE);

  while (1){
    u_int switches0 = p2sw_read();
    char start_state0 = (switches0 & (1<<0)) ? '-' : '1';
    if (start_state0 == '1')
      main();
    //or_sr(0x10); //turns CPU off
  }
}
/** Main function. Makes everything run together.*/
void main()
{
 START:
  configureClocks();
  lcd_init();
  p2sw_init(15);
  or_sr(0x8);			/* GIE (enable interrupts) */
  //srand(time(0));
  u_char width = screenWidth, height = screenHeight;

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
      break;
  }
  int program_counter = 0;
  while (1) {
    char *goto_color[] = {"RED", "YELLOW", "GREEN", "PURPLE"};
    u_int switches = p2sw_read(), i;
    char str[5];
    int rand_index = rand()%4;
    char *correct_color = goto_color[rand_index];
    char *current_color;
    //drawString5x7(40,40, current_color, COLOR_BLACK, COLOR_RED);
    if (program_counter == 0){
      current_color = "RED";
    }
    program_counter++;
    for (i = 0; i < 4; i++){
      str[i] = (switches & (1<<i)) ? '-' : '1'+i;
      if (str[i] == '1'){
	clearScreen(COLOR_RED);
	if (current_color != "RED"){
	  game_over();
	    //goto START;
	}
	current_color = correct_color;
	drawString5x7(30,20, correct_color, COLOR_BLACK, COLOR_RED);
      }
      else if (str[i] == '2'){
	clearScreen(COLOR_PURPLE);
	if (current_color != "PURPLE"){
	  //drawString5x7(40,40, "GAME OVER", COLOR_BLACK, COLOR_PURPLE);
	  //if(game_over())
	  //  goto START;
	}
	current_color = correct_color;
	drawString5x7(30,20, correct_color, COLOR_BLACK, COLOR_PURPLE);
      }
      else if (str[i] == '3'){
	clearScreen(COLOR_YELLOW);
	if (current_color != "YELLOW"){
	  //drawString5x7(40,40, "GAME OVER", COLOR_BLACK, COLOR_YELLOW);
	  //  if(game_over())
	  //goto START;
	}
	current_color = correct_color;
	drawString5x7(30,20, correct_color, COLOR_BLACK, COLOR_YELLOW);
      }
      else if (str[i] == '4'){
	clearScreen(COLOR_GREEN);
	if (current_color != "GREEN"){
	  //drawString5x7(40,40, "GAME OVER", COLOR_BLACK, COLOR_GREEN);
	  //if(game_over())
	  //goto START;
	}
	current_color = correct_color;
	drawString5x7(30,20, correct_color, COLOR_BLACK, COLOR_GREEN);
      }
    }
  } 
}
