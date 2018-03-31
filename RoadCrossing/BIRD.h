#pragma once
#include "CAnimal.h"

class BIRD : public CAnimal {
public:
	BIRD();
	BIRD(int y);
	void draw(char );
	void updatePos(char);
};