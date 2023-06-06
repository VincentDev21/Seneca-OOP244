#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Tournament.h"
using namespace std;

namespace sdds {
	Tournament::Tournament() {
		m_name = nullptr;
		m_soccer = nullptr;
		m_num = 0;
	}
	Tournament::Tournament(const char* name, int noOfteam, const SoccerTeam* soccer) {
		setTournament(name,  noOfteam, soccer);
	}
	Tournament::~Tournament() {
		delete[]m_name;
		m_name = nullptr;
		delete[]m_soccer;
		m_soccer = nullptr;
	}

	void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer){
		int i;
		if (name != nullptr && noOfteam > 0) {
			m_num = noOfteam;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_soccer = new SoccerTeam[m_num];
			for (i = 0; i < m_num; i++) {
				m_soccer[i] = soccer[i];
			}
		}
		else {
			setEmpty();
		}
	}
	void Tournament::setEmpty() {
		m_name = nullptr;
		m_soccer = nullptr;
		m_num = 0;
	}
	bool Tournament::isEmpty() const{
		if (m_name != nullptr && m_soccer != nullptr && m_num > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	Tournament& Tournament::match(const SoccerTeam* ls) {
		int a, b;
		for (a = 0; a < m_num; a++) {
			for (b = 0; b < m_num; b++) {
				if (ls[a].m_noFouls < ls[b].m_noFouls) {
					m_soccer[a].m_golas+=1;
					m_soccer[b].setFine(m_soccer[b].m_fines*1.2, m_soccer[b].m_noFouls*2);
				}
				if (m_soccer[b].m_noFouls > MAX_FOUL) {
					m_soccer[b].m_noFouls = -1;
				}
			}
		}
		return *this;
	}
	ostream& Tournament::display() const {
		int i;
		if (isEmpty()) {
			cout.setf(ios::right);
			cout << "Tournament name: "<<m_name<<endl;
			cout << "list of the teams"<<endl;
			cout.width(45);
			cout << "Fines";
			cout.width(10);
			cout << "Fouls";
			cout.width(10);
			cout << "Goals";
			for (i = 0; i < m_num; i++) {
				cout << "\nTeam[" << i + 1 << "] :";
				m_soccer[i].display();
			}
			cout << endl;
		}
		else {
			cout << "Invalid Tournament";
		}
		return cout;
	}
}