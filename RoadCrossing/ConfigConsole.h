#pragma once
#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

#define CONSOLE_WIDTH 120
#define	CONSOLE_HEIGHT 30

/* note : 72 -> UP button
75 -> RIGHT button
77 -> LEFT button
80 -> DOWN button
13 -> ENTER
*/
#define ESC 27
#define UP		'W'
#define DOWN	'S'
#define LEFT	'A'
#define RIGHT	'D'
#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77
#define KEY_ENTER	13

const int BOARD_STARTX = 0;
const int BOARD_STARTY = 2;
const int BOARD_ENDX = 90;
const int BOARD_ENDY = 28;
const int MENU_WIDTH = 15;
const int MENU_HEIGHT = 5;

void ShowConsoleCursor(bool showFlag);
void Resize(int, int);
void FixConsoleWindow();
void TextColor(int x);
void GotoXy(int x, int y);
void clrscr();
void drawBoard(int, int, int, int);
void setFontSize(int);
