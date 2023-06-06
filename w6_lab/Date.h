#pragma once
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
#include "Error.h"
namespace sdds {
	class Date {
		int year = 0;
		int month = 0;
		int day = 0;
		int hour = 0;
		int minute = 0;
		bool onlyDate = false;
		Error Error_Message;
		void validate();
		bool val = false;
	public:
		
		Date();
		Date(int m_year, int m_month, int m_day);
		Date(int m_year, int m_month, int m_day,int m_hour, int m_min=0);
		operator bool() const;
		bool operator==(const Date& other) const;
		bool operator!=(const Date& other) const;
		bool operator<(const Date& other) const;
		bool operator>(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator>=(const Date& other) const;
		Date& dateOnly(bool data);
		Error& error();
		void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
		int uniqueDateValue(int year, int mon, int day, int hour, int min);
		int daysOfMonth(int year, int month); 
		std::ostream& display(std::ostream& ostr = std::cout) const;
		void valid(int boolean);
		std::istream& read(std::istream& istr);

	};
	std::ostream& operator<<(std::ostream& os, const Date& error);
	std::istream& operator >>(std::istream& istr, Date& data);
}
#endif