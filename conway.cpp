/* Lawrence Scroggs -- 10/20/20 -- Conway's Game of Life
   The purpose of this program is to implement Conway's 
   game of life and using the ncurses library to help build
   the GUI.
   RULES OF LIFE
   - For a space that is populated
      *Each cell with 1 or no neighbors dies from solitude
      *Each cell with 4 or more neighbors dies from overpopulation
      *EAch cell with 2 or 3 neighbors survives
   - For a space that is empty/unpopulated
      *Each cell with 3 neighbors becomes populated
*/

#include <iostream>
#include <ncurses.h>

using namespace std;


int main(){

  initscr();
  keypad(stdscr,true);

  int x = COLS;
  int y = LINES;

  int cell = ' ';
  int cursor = 1;

  char lifebox[x][y];

  for(int i = 0; i < y; ++i){
    for(int j = 0; j < x; ++j){

      lifebox[x][y] = ' ';
    }
  }

  WINDOW * window = newwin(y,x,0,0);
  refresh();

  mvwprintw(window,y/2,x/2,"Cell: %d",cell);
  print_menu(window,cursor);
  wrefresh(window);

  while(cell != 2)
  {
    cell = wgetch(window);
    switch(cell)
    {
          case KEY_UP:
                  if(cursor < 0)
                    break;
                  else
                    ++cursor;
                  break;
          case KEY_DOWN:
                  if(cursor > y)
                    break;
                  else
                    --cursor;
    }
                    



  endwin();


  

  return 0;

}
struct cell{

  // life value
  bool life = false;
  // is there an x
  char x = ' ';
 
  /* keeps tracks of neighbors
  int n1; 
  int n2; 
  int n3; 
  int n4; 
  int n5; 
  int n6; 
  int n7; 
  int n8; */

};
