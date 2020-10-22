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

  int x = COLS - 1;
  int y = LINES - 1;

  int cell = ' ';

  char lifebox[x][y];

  for(int i = 0; i < y; ++i){
    for(int j = 0; j < x; ++j){

      lifebox[x][y] = ' ';
    }
  }

  initscr();

  WINDOW * window = newwin(y,x,5,5);
  refresh();

  wborder(window,35,35,35,35,35,35,35,35);
  printw("hello ");
  wrefresh(window);
  keypad(stdscr,true);
  cell = mvgetch(x,y);

  cout <<  cell << ' ' << lifebox[0][0] << "\n";


  refresh();

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
