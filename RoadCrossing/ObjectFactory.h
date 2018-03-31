#pragma once
#include "CPeople.h"
#include "CAR.h"
#include "DINOSAUR.h"
#include "TRUCK.h"
#include "BIRD.h"

class ObjectFactory {
public:
	enum TYPE_OBJECT {
		People, 
		Car,
		Truck,
		Dinosaur,
		Bird
	};
	static CObject* createObject(int choice);
};