#pragma once
#include "CAnimal.h"

class DINOSAUR : public CAnimal{
private:
public:
	DINOSAUR();
	DINOSAUR(int y);
	void draw(char ch);
	void updatePos(char direct);
};