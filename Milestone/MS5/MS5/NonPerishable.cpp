#include <iostream>
#include "NonPerishable.h"
using namespace std;
namespace sdds {
	std::ostream& NonPerishable::write(std::ostream& os) const {
		if (*this) {
			if (m_displayType == POS_LIST) {
				Item::write(os);
				os << "     N / A   |";
			}
			if (m_displayType == POS_FORM) {
				Item::write(os);
				os << "=============^"<<endl;
			}
		}
		return os;
	}
}