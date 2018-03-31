#include "playGame.h"
#include "Menu.h"
#include <conio.h>
#include <stdio.h>

void printACSII(){
	for (int i = 0; i < 255; i++)
	cout << i << ":" <<  char(i) << endl;
}

void ColorTable() {
	for (int i = 0; i < 256; i++) {
		TextColor(i);
		printf("%d Hello\n", i);
	}
	_getch();
}

int main() {
	PlayGame player;
	FixConsoleWindow();
	player.playGame();
	return 0;
}