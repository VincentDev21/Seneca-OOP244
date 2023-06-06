#include <iostream>
#include "NonPerishable.h"
using namespace std;
namespace sdds {
	std::ostream& NonPerishable::write(std::ostream& os) const {
		if (*this) {
			if (DisplayType == POS_LIST) {
				Item::write(os);
				os << "     N / A   |";
			}
			if (DisplayType == POS_FORM) {
				Item::write(os);
				os << "=============^"<<endl;
			}
		}
		return os;
	}
}