#define _CRT_SECURE_NO_WARNINGS
#include"Dog.h"
#include<iostream>
using namespace std;

namespace sdds {
	
	void Dog::feed() {
		Pet::feed();
		if (isAlive()) {
			addCharge(COST_FEED);
		}
		else {
			m_numWalks = 0;
		}
	}
	void Dog::walk() {
		if (isAlive()) {
			m_numWalks++;
		}
		else {
			m_numWalks = 0;
		}
	}
	void Dog::reSpawn() {
		Pet::reSpawn();
		addCharge(COST_RESPAWN);
		m_numWalks = 0;
	}
	void Dog::operator++(int num) {
		if (isAlive()) {
			double healthDelta = 0;
			healthDelta += 0.15 * (getHugs() - 1);
			healthDelta += 0.10 * (getFeeds() - 2);
			healthDelta += 0.10 * (getGrooms() - 1);
			healthDelta += 0.20 * (m_numWalks - 2);
			applyHealthDelta(healthDelta);
			m_numWalks = 0;
			Pet::operator++(num);
		}
		
	}
	Dog& Dog::operator=(const Dog& other) {
		m_numWalks = other.m_numWalks;
		Pet::operator=(other);
		addCharge(COST_CREATE * 2);
		return *this;
	}
	ostream& operator<<(ostream& ostr, Dog& pet) {
		ostr << "** Generic Dog **" << endl;
		ostr << "   Walks: " << pet.m_numWalks << endl;
		pet.outputData(ostr);
		return ostr;
	}
}