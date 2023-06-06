#pragma once
#ifndef SDDS_PERISHABLE_H_
#define SDDS_PERISHABLE_H_
#include "Item.h"
#include"Date.h"
namespace sdds {
	class Perishable :public Item {
		Date date;
	public:
		char itemType()const {
			return 'P';
		}
		virtual std::ostream& write(std::ostream& os) const;
        virtual std::istream& read(std::istream& is);

        virtual std::ofstream& save(std::ofstream& ofs)const;
        virtual std::ifstream& load(std::ifstream& ifs);

	};
}
#endif