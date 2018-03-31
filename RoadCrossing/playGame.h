#pragma once
#include "CGAME.h"
#include "Menu.h"
#include <conio.h>
#include <thread>
#include "SoundGame.h"
using namespace std;

#define OPENING_MUSIC "../Sound/opening.mp3"

class PlayGame {
private:
	CGAME cg;
	Menu m_menu;
	SoundGame sound;
	char MOVING;
	thread gameThread;

	mutex m;
	condition_variable cv;

	bool IS_RUNNING = true;
	bool IS_PAUSE = false;
	bool TRULY_PAUSE = false;
	void wait();
public:
	void SubThread();
	void playGame();
	void pauseGame();
	void resumeGame();
	void exitGame();
};