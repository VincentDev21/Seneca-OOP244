#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Soccer.h"
using namespace std;

namespace sdds {
    void SoccerTeam::setTeam(const SoccerTeam& team) {
        setName(team.m_teamName);
        setFine(team.m_fines, team.m_noFouls);
    }
    void SoccerTeam::setName(const char* tname) {
        if (tname != NULL && strlen(tname) <= 40) {
            strcpy(m_teamName, tname);
        }
    }
    void SoccerTeam::setFine(double fines, int foul) {
        if (fines >=0 && foul >=0) {
            m_fines = fines;
            m_noFouls = foul;
        }
        else {
            setEmpty();
        }
    }
    void SoccerTeam::setEmpty() {
        m_teamName[0] = '\0';
        m_noFouls = -1;
        m_fines = -1;
        m_golas = 0;
    }
    bool SoccerTeam::isEmpty() const {
        if (m_teamName != NULL && strlen(m_teamName) <= 40 && m_teamName[0] != '\0' && m_fines > -1 && m_noFouls > -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void SoccerTeam::calFines() {
        double temp;
        temp = m_fines;
        m_fines = temp + (temp * 0.2);
    }
    int SoccerTeam::fouls() const {
        return m_noFouls;
    }
    SoccerTeam::SoccerTeam() {
        setEmpty();
    }
    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul) {
        if (tname != NULL && fines >-1 && foul >-1) {
            setName(tname);
            setFine(fines, foul);
            m_golas = 0;
        }
        else {
            setEmpty();
        }
        
    }
    ostream& SoccerTeam::display()const {
        if (isEmpty()) {
            cout.unsetf(ios::right);
            cout.setf(ios::left);
            cout.width(30);
            cout << m_teamName;
            cout.setf(ios::right);
            cout.width(6);
            cout.precision(2);
            cout << fixed << m_fines;
            cout.width(6);
            cout << m_noFouls;
            cout.width(10);
            if (m_golas > 0) {
                cout << m_golas << "w";
            }
            else {
                cout << m_golas;
                cout << " ";
            }
        }
        else {
            cout<< "Invalid Team";
        }
        return cout;
    }
}