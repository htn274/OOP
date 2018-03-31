#pragma once
#include "CObject.h"

#define TIME_TRAFFIC_LIGHT 20
#define GREY 8
#define RED 12
#define GREEN 10

class TRAFFIC_LIGHT : public CObject{
protected:
	enum COLOR{red, green};
	int m_state; //RED or GREEN
	int m_time;
public:
	TRAFFIC_LIGHT();
	TRAFFIC_LIGHT(int y);
	void incTime();
	void draw(char );
	void updateState(char ch);
	bool isRed();

	void writeToFile(FILE* f);
	void readFromFile(FILE* f);
};