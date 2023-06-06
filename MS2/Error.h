
#pragma once
#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include<iostream>
namespace sdds {
	class Error {
		char* error_message=nullptr;
	public:
		Error();
		Error(const char* errorMessage);
		~Error();
		Error(const Error& other);
		Error& operator=(const Error& other);
		operator bool() const;
		Error& clear();
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};
	std::ostream& operator<<(std::ostream& os, const Error& error);
}
#endif
