#include<iostream>
#include<Windows.h>
#include "util.h"

void util::gotoxy(int x, int y){
	COORD coord;
	coord.X = x; coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}

int util::getY(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}
int util::getX(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

void util::clrscr()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }