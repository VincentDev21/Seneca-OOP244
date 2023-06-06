#include<iostream>
#include"Animation.h"
using namespace std;
namespace sdds {
	Animation::Animation() {
		m_dimension = 0;
	}
	Animation::Animation(int length, int dimension) : Video(length) {
		if (dimension == 2 || dimension == 3) {
			m_dimension = dimension;
		}
		else {
			dimension = 0;
		}

	}
	void Animation::load(std::istream& is){   
		char temp[100];
		Video::load(is);
		is.getline(temp, 100, '\n');

	}
	std::ostream& Animation::play(std::ostream& os) const {
		if (m_dimension != 0&&get()>0) {
			os << "Animation is in " << m_dimension <<"-D" << endl;
			os << "Video Length = " << get() ;
		}
		return os;

	}
	
}