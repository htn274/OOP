#include "ObjectFactory.h"

CObject * ObjectFactory::createObject(int choice)
{
	switch (choice) {
	case People: return new CPeople();
	case Car: return new CAR();
	case Truck: return new TRUCK();
	case Dinosaur: return new DINOSAUR();
	case Bird: return new BIRD();
	}
}
