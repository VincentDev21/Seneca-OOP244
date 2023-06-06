#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <iostream>
#include<cstring>
using namespace std;
namespace sdds {
	Error::Error() {
		error_message = nullptr;
	}
	Error::Error(const char* errorMessage) {
		delete[] error_message;
		error_message = nullptr;
		error_message = new char[strlen(errorMessage) + 1];
		strcpy(error_message, errorMessage);
	}
	Error::~Error() {
		delete[] error_message;
		error_message = nullptr;
	}
	Error::Error(const Error& other) {
		if (other)
		*this = other;
	}
	Error& Error::operator=(const Error& other) {
		delete[] error_message;
		error_message = nullptr;
		error_message = new char[strlen(other.error_message) + 1];
		strcpy(error_message, other.error_message);
		return *this;
	}

	Error::operator bool() const {
		if (error_message) {
			return true;
		}
		else {
			return false;
		}
	}
	std::ostream& Error::display(std::ostream& ostr) const {
		if (error_message != nullptr) {
			ostr << error_message;
		}
		else {
			ostr << "";
		}

		return ostr;
	}

	Error& Error::clear() {
		delete[] error_message;
		error_message = nullptr;
		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const Error& error) {
			return error.display(os);
	}
}
