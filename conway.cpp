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
struct cells{

  // life value
  bool life = false;
  // is there an x
  int x = 1;
 
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

using namespace std;


int main(){

  initscr();
  keypad(stdscr,TRUE);
  noecho();
  cbreak();

  int x = COLS;
  int y = LINES;

  int cell_y = 23;
  int cell_x = 23;

  int cell = 1;
  //int cursor = 1;

  char lifebox[x][y];

  for(int i = 0; i < y; ++i){
    for(int j = 0; j < x; ++j){

      lifebox[x][y] = ' ';
    }
  }

  WINDOW * window = newwin(y,x,0,0);
  refresh();

  wmove(window,cell_y,cell_x);

  //mvwprintw(window,y/2,x/2,"Cell: %d",cell);
  //wrefresh(window);

  while(cell != 2)
  {
    cell = getch();
    switch(cell) {
          case KEY_UP:
                  if((cell_y-1) < 0)
                    cell_y = cell_y;
                  else
                  {
                    --cell_y;
                    wmove(window,cell_y,cell_x);
                  }
                  wrefresh(window);
                  break;

          case KEY_DOWN:
                  if((cell_y+1) > y)
                    cell_y = cell_y;
                  else
                  {
                    ++cell_y;
                    wmove(window,cell_y,cell_x);
                  }
                  wrefresh(window);
                  break;

          case KEY_RIGHT:
                  if((cell_x+1) > x)
                    cell_x = cell_x;
                  else
                  {
                    ++cell_x;
                    wmove(window,cell_y,cell_x);
                  }
                  wrefresh(window);
                    break;

          case KEY_LEFT:
                  if((cell_x-1) < 0)
                    cell_x = cell_x;
                  else
                  {
                    --cell_x;
                    wmove(window,cell_y,cell_x);
                  }
                  wrefresh(window);
                  break;
          default:
                  break;
    }
    refresh();
    wrefresh(window);
                    
  } 

  endwin();

  return 0;

}
int move_cell(struct cells,int cell_y,int cell_x)
{
  return 0;

}
