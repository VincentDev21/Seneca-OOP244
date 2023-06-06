#include <iostream>
#include <istream>
#include"Media.h"
using namespace std;
namespace sdds {
		
	std::istream& operator>>(std::istream& is, Media& media) {
		media.load(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const Media& media) {
		return media.play(os);
	}

}