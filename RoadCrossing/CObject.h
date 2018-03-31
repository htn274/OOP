#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ConfigConsole.h"
#include <string>
#include <vector>

#define YCAR			25
#define YTRUCK			9
#define YDINOSAUR		17

class CObject {
protected:
	int m_x, m_y; //Diem ben trai duoi
	int m_width, m_height;
	int m_type; //0: people, 1 car, 2 truck, 3 dinosaur, 4 bird
public:
	virtual void init(int);
	void init(const CObject*, int d, int direct); // driect = 1: ben phai, direct = -1: ben trai

	virtual void draw(char ch) = 0;
	void Up();
	void Left();
	void Right();
	void Down();

	bool Thuoc(int x, int y);
	bool IsHitBoard();
	bool isOutBoard();
	bool shouldCreateNext(CObject* x);
	virtual void updatePos(char );
	virtual bool isDead();
	virtual bool isImpact(CObject*);
	virtual void Die() {}
	virtual bool isWin();

	virtual void writeToFile(FILE* f);
	virtual void readFromFile(FILE* f);

	bool isFull(CObject*);

	virtual void drawTrafficLight() {};
};