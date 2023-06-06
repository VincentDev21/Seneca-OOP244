#pragma once
#ifndef SDDS_FISH_H_
#define SDDS_FISH_H_
#include "Pet.h"
using namespace std;
namespace sdds {
	class Fish :public Pet{
		const double COST_BASE = 1.00;
		const double COST_FEED = 0.10;
		const double COST_CREATE = 2.00;
		const double COST_RESPAWN = 0.50;
	public:
		Fish(const char* name, int age = 0) :Pet(name, age, COST_BASE) {

		}
		void feed();
		void reSpawn();
		void operator++(int num);
		Fish& operator=(const Fish& other);
	};
	ostream& operator<<(ostream& ostr,  Fish& right);
}
#endif