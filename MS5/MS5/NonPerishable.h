#pragma once
#ifndef SDDS_NONPERISHABLE_H_
#define SDDS_NONPERISHABLE_H_
#include "Item.h"
#include "PosIO.h"
namespace sdds {
	class NonPerishable :public Item {
	public:
		char itemType()const {
			return 'N';
		}
		virtual std::ostream& write(std::ostream& os) const;
	};
}

#endif