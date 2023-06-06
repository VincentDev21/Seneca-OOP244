#define _CRT_SECURE_NO_WARNINGS
#include"Fish.h"
#include<iostream>
using namespace std;

namespace sdds {
	
	void Fish::feed() {
		Pet::feed();
		if (isAlive()) {
			addCharge(COST_FEED);
		}
	}
	void Fish::reSpawn() {
		Pet::reSpawn();
		addCharge(0.50);
	}
	void Fish::operator++(int num) {
		if (isAlive()) {
			double healthDelta = 0;
			healthDelta += 0.20 * (getFeeds() - 1);
			applyHealthDelta(healthDelta);
			Pet::operator++(num);
		}
		
		
	}
	Fish& Fish::operator=(const Fish& other) {
		Pet::operator=(other);
		addCharge(COST_CREATE*2);
		return *this;
	}
	
	ostream& operator<<(ostream& ostr, Fish& pet){
		ostr << "** Generic Fish **" << endl;
		pet.outputData(ostr);
		return ostr;
	}
}