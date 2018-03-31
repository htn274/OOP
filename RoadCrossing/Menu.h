#pragma once
#include <string>
#include "ConfigConsole.h"
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <mmsystem.h>
#include <mciapi.h>

using namespace std;

#define MAX_CHOICE  4

class Menu {
private:

	vector<string> m_title{
"______                _   _____                   _             ",
"| ___ \\              | | /  __ \\                 (_)            ",
"| |_/ /___   __ _  __| | | /  \\/_ __ ___  ___ ___ _ _ __   __ _ ",
"|    // _ \\ / _` |/ _` | | |   | '__/ _ \\/ __/ __| | '_ \\ / _` |",
"| |\\ \\ (_) | (_| | (_| | | \\__/\\ | | (_) \\__ \\__ \\ | | | | (_| |",
"\\_| \\_\\___/ \\__,_|\\__,_|  \\____/_|  \\___/|___/___/_|_| |_|\\__, |",
"                                                           __/ |",
"                                                           |___/"
};
	int m_width, m_height;
	int levelStart = 0, music = 0;
	string musicState[2] = { "OFF", "ON" };
	string m_list[MAX_CHOICE] = { "New game", "Load Game", "Settings", "Exit" };
	string m_settingList[2] = { "Level", "Music" };
	int m_x;
	int m_y[MAX_CHOICE] = {12, 16, 20, 24};
	void drawTitle();

public:
	Menu();

	void draw();
	int updateChoice();
	void drawSettings();
	void setting();
	void updateSetting();
};