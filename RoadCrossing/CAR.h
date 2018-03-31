#pragma once
#include "CVEHICLE.h"

class CAR : public CVEHICLE {
private:
public:
	CAR();
	CAR(int y);
	void draw(char ch);
	void updatePos(char direct);
	//void writeToFile(FILE * f);
};