#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "CPeople.h"
#include "CAR.h"
#include "TRUCK.h"
#include "DINOSAUR.h"
#include "BIRD.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <conio.h>
#include <stdio.h>
#include "ObjectFactory.h"

using namespace std;

const int MIN_SO_LUONG = 5;
const int MAX_DISTANCE = 10;
const int MIN_DISTANCE = 4;

#define CREATE_LEFT		-1
#define CREATE_RIGHT	1
#define MAX_LEVEL		10

class CGAME {
private:
	int m_level;
	vector<CObject*> m_obj;
	vector<int> m_numObj; //car, truck, dinosaur, bird
	void drawDaiPhanCach(int);
	void drawObject();
	void createBird(int );
	char* getFileName(string, int, int);
public:
	CGAME();
	CGAME(int );
	CGAME(CGAME &&);
	~CGAME();
	void drawLoad();
	void drawScence();
	void drawGame();
	void startGame();
	
	void updatePosObject(char );
	bool isOver();
	bool isCrash();
	void Over();
	bool isFinish();
	void afterFinish();

	void saveGame();
	bool writeFile(char* fileName);
	bool loadGame();
	bool readFile(char* fileName);

	int getLevel();
};

