#pragma once
#include "CObstacle.h"
#include "TRAFFIC_LIGHT.h"

class CVEHICLE : public CObstacle {
protected:
	TRAFFIC_LIGHT m_trafficLight;
public:	
	bool isStop();
	void drawTrafficLight();
	virtual void writeToFile(FILE* f);
	virtual void readFromFile(FILE* f);
};