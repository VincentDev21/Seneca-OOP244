#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "POS.h"
#include "Error.h"
#include <ctime>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
namespace sdds {
    void Date::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
    int Date::uniqueDateValue(int year, int mon, int day, int hour, int min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    int Date::daysOfMonth(int year, int month) {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    Date::Date() {

        getSystemDate(year, month, day, hour, minute, false);

    }
    Date::Date(int m_year, int m_month, int m_day) {
        year = m_year;
        month = m_month;
        day = m_day;
        onlyDate = true;
        validate();
    }
    
    Date::Date(int m_year, int m_month, int m_day, int m_hour, int m_min) {
        year = m_year;
        month = m_month;
        day = m_day;
        hour = m_hour;
        minute = m_min;
        validate();
    }
    

    void Date::validate() {
        //Error_Message = Error::Error();

        if (year < 1000 || year > 9999) {
            Error_Message = "Invalid Year";
        }
        if (month < 1 || month > 12) {
            Error_Message = "Invalid Month";
        }
        if (day < 1 || day > daysOfMonth(year, month)) {
            if (daysOfMonth(year, month) != 0) {
                Error_Message = "Invalid Day";
            }
        }
        if (!onlyDate) {
            if (hour < 0 || hour > 23) {
                Error_Message = "Invalid Hour";
            }
            if (minute < 0 || minute > 59) {
                Error_Message= "Invlid Minute";
            }
        }
        
    }

    Date::operator bool()const {
        return !Error_Message;
    }

    Date& Date::dateOnly(bool data) {
        onlyDate = data;
        if (data) {
            hour = 0;
            minute = 0;
        }
        return *this;
    }
    Error& Date::error() {
        return Error_Message;
    }
    std::ostream& Date::display(std::ostream& ostr ) const {
        if (Error_Message) {
            ostr << Error_Message << "(";

            ostr << year << "/";
            if (month < 10) {
                ostr << "0";
            }
            ostr << month << "/";
            if (day < 10) {
                ostr << "0";
            }
            ostr << day;
            
            if (!onlyDate) {
                ostr << ", ";
                if (hour < 10) {
                    ostr << "0";
                }
                ostr << hour << ":";
                if (minute < 10) {
                    ostr << "0";
                }
                ostr << minute;
            }
            ostr << ")";
        }
        else {
            ostr << year << "/";
            
            if (month < 10) {
                ostr << "0";
            }
            ostr << month << "/";
            if (day < 10) {
                ostr << "0";
            }
            ostr << day;

            if (!onlyDate) {
                ostr << ", ";
                if (hour < 10) {
                    ostr << "0";
                }
                ostr << hour << ":";
                if (minute < 10) {
                    ostr << "0";
                }
                ostr << minute;
            }
        }
        
        return ostr;
    }
    
    std::ostream& operator<<(std::ostream& os, const Date& error) {
        return error.display(os);
    }
     void Date::valid(int boolean) {
         if (boolean == 1) {
             val = true;
         }
         if(boolean==0){
             val = false;
         }
    }
    
    istream& Date::read(std::istream& istr) {
        year = 0;
        month = 0;
        day = 0;
        hour = 0;
        minute = 0;
        
        bool error = false;
        istr >> year;
        if (istr.fail())
        {
            Error_Message = "Cannot read year entry";
            error = true;
        }
        else
        {
            istr.ignore();
        }

        if (!error)
        {
            istr >> month;
            if (istr.fail())
            {
                Error_Message = "Cannot read month entry";
                error = true;
            }
            else
            {
                istr.ignore();
            }
        }

        if (!error)
        {
            istr >> day;
            if (istr.fail())
            {
                Error_Message = "Cannot read day entry";
                error = true;
            }
            else
            {
                if (!onlyDate)
                {
                    if (!error)
                    {
                        istr.ignore();
                        istr >> hour;
                        if (istr.fail())
                        {
                            Error_Message = "Cannot read hour entry";
                            error = true;
                        }
                        else
                        {
                            istr.ignore();
                        }
                    }

                    if (!error)
                    {
                        istr >> minute;
                        if (istr.fail())
                        {
                            Error_Message = "Cannot read minute entry";
                            error = true;
                        }
                    }
                }
            }

        }
        if (!error) {
            validate();
        }
        return istr;
    }

    std::istream& operator >>(std::istream& istr, Date& data) {
       
        return data.read(istr);
    }
    
    
    
    
    
    
    
    bool Date::operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }
    bool Date::operator!=(const Date& other) const {
        return !(*this == other);
    }
    bool Date::operator<(const Date& other) const{
        if (year < other.year) {
            return true;
        }
        else if (year == other.year && month < other.month) {
            return true;
        }
        else if (year == other.year && month == other.month && day < other.day) {
            return true;
        }
        return false;
    }

    bool Date::operator>(const Date& other) const{
        return other < *this;

    }
    bool Date::operator<=(const Date& other) const{
        return *this == other || *this < other;

    }
    bool Date::operator>=(const Date& other) const {
        return *this == other || *this > other;


    }
  
}

