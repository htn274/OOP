#include "CVEHICLE.h"

bool CVEHICLE::isStop()
{
	return m_trafficLight.isRed();
}

void CVEHICLE::drawTrafficLight()
{
	m_trafficLight.draw(254);
}

void CVEHICLE::writeToFile(FILE * f)
{
	this->CObject::writeToFile(f);
	m_trafficLight.writeToFile(f);
}

void CVEHICLE::readFromFile(FILE * f)
{
	this->CObject::readFromFile(f);
	m_trafficLight.readFromFile(f);
}
