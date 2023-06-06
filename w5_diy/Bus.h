#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>
using namespace std;
namespace sdds {
    const double price = 125.34;
	class Bus {
        int e_seats=0;
        int e_noOfPassengers=0;
        bool inservice=true;
        void setFull();
        ostream& display(ostream& ostr = cout) const;

	public:
        Bus(int seats=20 , int noOfPassangers=0 );
        istream& read(istream& istr = cin);
        void drawBus(int seat, int noOfPassengers, ostream& ostr) const;

        operator bool() const;
        operator int() const;
        operator double() const;

        bool operator--();
        bool operator++();
        bool operator--(int);
        bool operator++(int);

        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);
        bool operator==(const Bus& right) const;

        friend int operator+(int left, const Bus& right);
        friend ostream& operator<<(ostream& ostr, const Bus& right);
        friend istream& operator>>(istream& istr, Bus& right);
	};

}
#endif

