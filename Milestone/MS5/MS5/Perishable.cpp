#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Perishable.h"
#include <fstream>

using namespace std;
namespace sdds {
		 std::ostream& Perishable::write(std::ostream& os) const{
			 if (*this) {
				 if (m_displayType == POS_LIST) {
					 Item::write(os);
					 os << "  " << date << " |";
				 }
				 if (m_displayType == POS_FORM) {
					 Item::write(os);
					 os << "Expiry date: " << date << endl << "=============^" << endl;
				 }
			 }
			 return os;
		 }
		 std::istream& Perishable::read(std::istream& is) {
			 if (!is.fail()) {
				 Item::read(is);
				 cout << "Expiry date (YYYY/MM/DD)" << endl;
				 cout << "> ";
				 date.dateOnly(true);
				 date.read(is);
				 if (*this) {
					 return is;
				 }
			 }
			 return is;
		 }
		 
		 std::ofstream& Perishable::save(std::ofstream& ofs) const {
			 if (*this|| !ofs.fail()) {
				 Item::save(ofs);
				 ofs << ",";
				 ofs << date;

			 }
			 return ofs;
		 }
		 std::ifstream& Perishable::load(std::ifstream& ifs) {
			 Item::load(ifs);
			 ifs.ignore();
			 date.dateOnly(true);
			 if (!ifs.fail()) {
				 date.read(ifs);
			 }
			 return ifs;
		 }
}

