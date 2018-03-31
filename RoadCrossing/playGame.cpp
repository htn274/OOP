#include "playGame.h"

void PlayGame::SubThread()
{
	IS_RUNNING = true;
	IS_PAUSE = TRULY_PAUSE = false;
	while (IS_RUNNING) {
		if (IS_PAUSE) TRULY_PAUSE = true;
		while (IS_PAUSE)
			wait();

		if (!cg.isOver()) {
			cg.updatePosObject(MOVING);
			MOVING = ' ';
			cg.drawScence();
		}
		if (cg.isCrash() && !cg.isOver()) {
			cg.Over();
		}

		if (cg.isFinish()){
			cg.afterFinish();
		}
		
		Sleep(200);
	}
}

void PlayGame::pauseGame()
{
	std::lock_guard<std::mutex> lk(m);
	IS_PAUSE = true;
	while (!TRULY_PAUSE);
}

void PlayGame::wait()
{
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk);
	lk.unlock();
}

void PlayGame::resumeGame()
{
	std::lock_guard<std::mutex> lk(m);
	IS_PAUSE = false;
	TRULY_PAUSE = false;
	cv.notify_one();
}

void PlayGame::exitGame()
{
	IS_RUNNING = false;
	//cg.Over();
	gameThread.join();
}

void PlayGame::playGame()
{
	char temp;
	int choice;
	while (true) {
		sound.play(OPENING_MUSIC);
		m_menu.draw();
		choice = m_menu.updateChoice();
		if (choice == 3) {
			break;
		}
		if (choice == 2) {
			m_menu.setting();
			continue;
		}
		sound.stop(OPENING_MUSIC);
		cg.CGAME::CGAME();
		if (choice == 1) 
			if (!cg.loadGame()) continue;
		if (choice == 0) cg.startGame();
		
		gameThread = thread(&PlayGame::SubThread, this);
		while (1) {
			temp = toupper(_getch());
			if (!cg.isOver()) {
				if (temp == ESC) {
					exitGame();
					break;
				}
				else if (temp == 'P') {
					pauseGame();
				}
				else if (temp == 'L') {
					pauseGame();
					cg.saveGame();
					resumeGame();
				}
				else if (temp == 'T') {
					pauseGame();
					cg.loadGame();
					cg.drawGame();
					resumeGame();
				}
				else {
					resumeGame();
					MOVING = temp;
				}
			}
			else {
				exitGame();
				break;
			}
		}
	}
}
