#pragma once
#include "CVEHICLE.h"

class TRUCK : public CVEHICLE {
private:
public:
	TRUCK();
	TRUCK(int y);
	void draw(char ch);
	void updatePos(char direct);
	//void writeToFile(FILE * f);
};