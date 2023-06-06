#pragma once
#ifndef SDDS_DOG_H_
#define SDDS_DOG_H_
#include "Pet.h"
using namespace std;
namespace sdds {
	class Dog :public Pet {
		const double COST_BASE = 1.00;
		const double COST_FEED = 0.25;
		const double COST_CREATE = 4.00;
		const double COST_RESPAWN = 1.00;

	public:
		int m_numWalks = 0;
		Dog(const char* name, int age = 0) :Pet(name, age, COST_BASE) {
		}
		
		void walk();
		void feed();
		void reSpawn();
		void operator++(int num);
		Dog& operator=(const Dog& other);
	};
	ostream& operator<<(ostream& ostr,  Dog& right);
}
#endif