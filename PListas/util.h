#ifndef UTIL_H_
#define UTIL_H_

#include<iostream>
#include<Windows.h>

using namespace std;

class util{
public:
	static void gotoxy(int x, int y);   //Posiciona el cursor
	static int getY();                  //Coordenada Y del cursor
	static int getX();                  //Coordenada X del cursor
	static void clrscr();               //Limpia la pantalla
};
#endif