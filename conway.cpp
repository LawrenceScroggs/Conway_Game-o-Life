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
  int x_loc = 0;
  int y_loc = 0;

  int neighbors = 0;

};

using namespace std;
int run_life(int,int, cells **);
int print_life(int ,int , cells **);


int main(){

  initscr();
  keypad(stdscr,TRUE);  // enables keypad
  noecho();  // wont print user input to screen
  cbreak();  // allows only one character to be held with input

  // size of terminal
  int x = COLS;
  int y = LINES;

  //int x = 20;
  //int y = 20;

  // keeps track of the cursor
  int cell_y = y/2;
  int cell_x = x/2; 

  int cell = ' ';
  int pause = ' ';

  //cells lifebox[x][y];
  cells **lifebox;
  lifebox = new cells* [x];
  for(int i = 0; i < x; ++i)
    lifebox[i] = new cells[y];


  for(int i = 0; i < x; ++i)
  {
    for(int j = 0; j < y; ++j)
    {
      lifebox[i][j].x_loc = i;
      lifebox[i][j].y_loc = j;
    }
  }
  

  WINDOW * window = newwin(y,x,0,0);
  refresh();

  wmove(window,cell_y,cell_x);

  while(cell != 'q')
  {
    cell = getch();
    if(cell == ERR)
      cell = 'p';
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
          case 'x':
                  waddch(window,'X');
                  lifebox[cell_x][cell_y].life = true;
                  wmove(window,cell_y,cell_x);
                  wrefresh(window);
                  break;
          case 'p':
                  run_life(x,y,lifebox);
                  for(int i = 0; i < x; ++i)
                  {
                    for(int j = 0; j < y; ++j)
                    {
                      if(lifebox[i][j].neighbors == 3)
                      {
                        lifebox[i][j].life = true;
                        mvwaddch(window,j,i,'X');
                      }
                      else if(lifebox[i][j].neighbors > 3 || lifebox[i][j].neighbors < 2)
                      {
                        lifebox[i][j].life = false;
                        mvwaddch(window,j,i,' ');
                      }
                      else
                        wmove(window,y,x);
                    }
                  }
                  wrefresh(window);
                  pause = getch();
                  if(pause == 'p')
                  {
                    cell = 'n';
                    break;
                  }
                  halfdelay(5);

                  break;
          case 'n':
                  run_life(x,y,lifebox);
                  for(int i = 0; i < x; ++i)
                  {
                    for(int j = 0; j < y; ++j)
                    {
                      if(lifebox[i][j].neighbors == 3)
                      {
                        lifebox[i][j].life = true;
                        mvwaddch(window,j,i,'X');
                      }
                      else if(lifebox[i][j].neighbors > 3 || lifebox[i][j].neighbors < 2)
                      {
                        lifebox[i][j].life = false;
                        mvwaddch(window,j,i,' ');
                      }
                      else
                        wmove(window,y,x);
                    }
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

int run_life(int x, int y, cells** lifebox)
{
  --x;
  --y;

  for(int i = 0; i < x; ++i)
  {
    for(int j = 0; j < y; ++j)
    {
      lifebox[i][j].neighbors = 0;
      if((i-1) >= 0 && lifebox[i-1][j].life == true)
        lifebox[i][j].neighbors += 1;
      if((i+1) <= x && lifebox[i+1][j].life == true)
        lifebox[i][j].neighbors += 1;
      if((j+1) <= y && lifebox[i][j+1].life == true)
        lifebox[i][j].neighbors += 1;
      if((j-1) >= 0 && lifebox[i][j-1].life == true)
        lifebox[i][j].neighbors += 1;
      if((i-1) >= 0 && (j+1) <= y && lifebox[i-1][j+1].life == true)
        lifebox[i][j].neighbors += 1;
      if((i+1) <= x && (j+1) <= y && lifebox[i+1][j+1].life == true)
        lifebox[i][j].neighbors += 1;
      if((i-1) >= 0 && (j-1) >= 0 && lifebox[i-1][j-1].life == true)
        lifebox[i][j].neighbors += 1;
      if((i+1) <= x && (j-1) >= 0 && lifebox[i+1][j-1].life == true)
        lifebox[i][j].neighbors += 1;

    
    }
  }


  return 0;

}
