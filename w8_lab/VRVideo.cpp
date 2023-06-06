#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"VRVideo.h"
using namespace std;
namespace sdds {
	VRVideo::VRVideo() {
		m_equpiment = nullptr;
	}
	VRVideo::VRVideo(int v_length, const char* equpiment): Video(v_length)
	{
		if (equpiment != nullptr) {
			m_equpiment = new char[strlen(equpiment) + 1];
			strcpy(m_equpiment, equpiment);
		}
		else {
			m_equpiment = nullptr;

		}
	}
	VRVideo::~VRVideo() {
		delete[] m_equpiment;
		m_equpiment = nullptr;
	}
	void VRVideo::load(std::istream& is){
		char temp[100];
		Video::load(is);
		is.getline(temp, 100, '\n');
		delete[] m_equpiment;
		m_equpiment = nullptr;
		m_equpiment = new char[strlen(temp) + 1];
		strcpy(m_equpiment, temp);
	}
	std::ostream& VRVideo::play(std::ostream& os) const {
		if (m_equpiment != nullptr&&get() > 0) {
			os << "VRVideo requires " << m_equpiment << endl;
			os << "Video Length = " << get() ;
		}
		return os;
	 }


}