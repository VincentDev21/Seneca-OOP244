#include <iostream>
#include <cstring>
#include "Bus.h"
using namespace std;
namespace sdds {
	void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}
    Bus::Bus(int seats, int noOfPassangers) {
        if ((seats % 2 == 0) && (seats >= 10 && seats <= 40) && (noOfPassangers >= 0 && noOfPassangers <= seats)) {
            e_seats = seats;
            e_noOfPassengers = noOfPassangers;
        }
        else {
            setFull();
        }
        
    }
    void Bus::setFull() {
        e_seats = -1;
        
    }

    ostream& Bus::display(ostream& ostr) const {
        Bus total(e_seats, e_noOfPassengers);
        if (*this) {
            drawBus( e_seats,  e_noOfPassengers, ostr) ;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout<<"Total Fare Price: "<< double(total)<<endl;
        }
        else {
            ostr << "Out of service!" << endl;
        }
        return ostr;
    }
    Bus:: operator bool() const {
        if (e_seats > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    istream& Bus::read(istream& istr) {
        istr >> e_seats;
        istr.ignore();
        istr >> e_noOfPassengers;
        if (!((e_seats % 2 == 0) && (e_seats >= 10 && e_seats <= 40) && (e_noOfPassengers >= 0 && e_noOfPassengers <= e_seats))) {
            setFull();
        }
        return istr;
    }
    Bus::operator int() const {
        if (*this) {
            return e_noOfPassengers;
        }
        else {
            return -1;
        }
    }
    Bus::operator double() const {
        if (*this) {
            return e_noOfPassengers * price;
        }
        else {
            return -1.0;

        }
    }
    bool Bus::operator--() {
        if (*this && e_noOfPassengers > 0) {
            e_noOfPassengers--;
            return true;
        }
        else {
            return false;
        }
        
    }
    bool Bus::operator++() {
        if (!(*this) || e_noOfPassengers >= e_seats)
        {
            return false;
        }
        else
        {
            e_noOfPassengers++;
            return true;
        }
    }
    bool Bus::operator--(int) {
        if (*this && e_noOfPassengers > 0) {
            e_noOfPassengers--;
            return true;
        }
        else {
            return false;
        }
    }
    bool Bus::operator++(int) {
        if (!(*this) || e_noOfPassengers >= e_seats)
        {
            return false;
        }
        else
        {
            e_noOfPassengers++;
            return true;
        }
    }

    Bus& Bus::operator=(int value) {
        e_noOfPassengers = value;
        if (e_noOfPassengers > e_seats) {
            setFull();
        }
        return *this;
    }
    Bus& Bus::operator+=(int value) {
        e_noOfPassengers += value;
        if (e_noOfPassengers > e_seats) {
            setFull();
        }
        return *this;
    }
    Bus& Bus::operator+=(Bus& right) {
        if (*this) {
            e_noOfPassengers += right.e_noOfPassengers;
            if (e_noOfPassengers > e_seats) {

                right.e_noOfPassengers = e_noOfPassengers - e_seats;
                e_noOfPassengers = e_seats;
            }
            else {
                right.e_noOfPassengers = 0;

            }
        }
        return *this;

    }
    bool Bus::operator==(const Bus& right) const {
        bool temp = false;
        int Bus_A = int(*this);
        int Bus_B=int(right);
        if (Bus_A == Bus_B) {
            temp = true;
        }
        return temp;
    }
    int operator+(int left, const Bus& right) {
        if (right) {
            left += int(right);
        }
        return left;
    }
    
    ostream& operator<<(ostream& ostr, const Bus& right) {
        return right.display(ostr);
    }
    istream& operator>>(istream& istr, Bus& right) {
        return right.read(istr);
    }
}