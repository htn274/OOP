#pragma once
#include "CObject.h"

class CPeople : public CObject{
private:
	int m_state; //song: true; false: chet
public:
	CPeople();

	void draw(char ch);
	void updatePos(char );
	bool isDead();
	bool isImpact(CObject* obj);
	void Die();
	bool isWin();
};