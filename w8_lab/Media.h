#pragma once
#ifndef SDDS_MEDIA_H_
#define SDDS_MEDIA_H_
#include <iostream>
#include <istream>
namespace sdds {
	class Media {
	public:
		virtual ~Media() {}
		virtual std::ostream& play(std::ostream& os) const = 0;
		virtual void load(std::istream& is) = 0;
	};
	std::istream& operator>>(std::istream& is, Media& media);
	std::ostream& operator<<(std::ostream& os, const Media& media);
}
#endif //!SDDS_MEDIA_H_