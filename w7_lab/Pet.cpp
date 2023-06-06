/////////////////////////////////////////////////////////
// Workshop 7: Derived Classes & Functions in a Hierarchy
// 
// Date:	10/29/2022
// Author:  Jitesh Arora
// File:	Pet.cpp
// 
// Last Updated 11/27/2022 by Jitesh Arora
// 
// Description:
// Base class implementation for a Pet 
////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Pet.h"

using namespace std;

namespace sdds
{
	Pet::Pet()
	{
		m_Name[0]	= '\0';
		m_origAge	= m_age = -1;

		m_numFeeds	= 0;
		m_numHugs	= 0;
		m_numCleans = 0;
		m_healthLvl = -1.0;

		m_totalCharges = 0;
	}


	Pet::Pet(const char* name, int age, double incrBaseCharge)
	{
		strncpy(m_Name, name, MAXLEN_PETNAME);
		m_totalCharges = COST_BASE + incrBaseCharge;
		m_origAge = m_age = age;

		m_numFeeds	= 0;
		m_numHugs	= 0;
		m_numCleans = 0;
		m_healthLvl = 1.0;	// Born with perfect health
	}

	void Pet::feed()
	{
		if (isAlive())
			m_numFeeds++;
	}

	void Pet::groom()
	{
		if (isAlive())
			m_numCleans++;
	}

	void Pet::hug()
	{
		if (isAlive())
			m_numHugs++;
	}

	int Pet::getFeeds()
	{
		return m_numFeeds;
	}

	int Pet::getGrooms()
	{
		return m_numCleans;
	}

	int Pet::getHugs()
	{
		return m_numHugs;
	}

	ostream& Pet::outputData(std::ostream& os) 
	{
		// Display class members
		os << "   Name: " << m_Name << "; " << m_age << " days old" << endl;
		os << "   Feeds, Cleans, Hugs: " << m_numFeeds << ", " << m_numCleans << ", " << m_numHugs << endl;

		os.setf(ios::fixed);
		os.precision(2);
		os << "   Charges: $" << m_totalCharges << endl;

		os << "   Health : " << m_healthLvl;
		if (m_healthLvl == 1.0)
			os << " (Ideal)";
		else if (m_healthLvl > 2.0 || m_healthLvl < 0.0)
			os << " (PERISHED)";
		else if (m_healthLvl > 1.0)
			os << " (Over Nurtured)";
		else if (m_healthLvl < 1.0)
			os << " (Under Nurtured)";
			
		os << endl;
		return os;
	}

	void Pet::payBalance(std::ostream& os)
	{
		os.setf(ios::fixed);
		os.precision(2);
		os << ">> Balance of $" << m_totalCharges << " has been paid for " << m_Name << endl;

		m_totalCharges = 0;
	}

	void Pet::operator++ (int num)
	{
		// Can only age if your alive
		if (isAlive())
			m_age++;

		// Always reset daily activity metrics
		m_numFeeds	= 0;
		m_numCleans = 0;
		m_numHugs	= 0;
	}

	// Check if pet is alive
	// Must be > 0 or < 2 to be considered alive 
	// 1.0 = Perfect Health; < or > is under or over cared
	bool Pet::isAlive() const
	{
		// Pet's are alive if their age has been initialized
		// And Health is between 0 and 2 (Inclusive)
		return (m_age >= 0 && m_healthLvl >= 0 && m_healthLvl <= 2.0);
	}

	// Reset pet to full health (for a small charge)
	void Pet::reSpawn()
	{
		m_age = m_origAge;

		m_numFeeds	= 0;
		m_numHugs	= 0;
		m_numCleans = 0;
		m_healthLvl = 1.0;	

		m_totalCharges += COST_REVIVE;
	}

	void Pet::applyHealthDelta(double delta)
	{
		m_healthLvl += delta;
	}

	void Pet::addCharge(double fee)
	{
		m_totalCharges += fee;
	}
	
	// Clone the pet; at 2x base cost
	Pet& Pet::operator=(const Pet& rhs)
	{
		strncpy(m_Name, rhs.m_Name, MAXLEN_PETNAME);
		strncat(m_Name, "(C)", 3);

		m_totalCharges = COST_BASE*2;

		m_age		= rhs.m_age;
		m_numFeeds	= rhs.m_numFeeds;
		m_numHugs	= rhs.m_numHugs;
		m_numCleans = rhs.m_numCleans;
		m_healthLvl = rhs.m_healthLvl;

		return *this;
	}

	// Global helper function 
	ostream& operator<<(ostream& os, Pet& pet)
	{
		os << "** Generic Pet **" << endl;
		return pet.outputData(os);
	}
}
