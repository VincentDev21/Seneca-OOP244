#ifndef SDDS_EGGCARTON_H_
#define SDDS_EGGCARTON_H_
#include <iostream>
using namespace std;
namespace sdds {
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;
    class EggCarton {
        int e_size;
        int e_noOfEggs;
        bool e_jumbo;
        ostream& display(ostream& ostr = cout) const;
        void setBroken();
    public:
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
        istream& read(istream& istr = cin);
        ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;

        operator bool() const;
        operator int() const;
        operator double() const;

        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator--(int);
        EggCarton operator++(int);

        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;

        friend int operator+(int left, const EggCarton& right);
        friend ostream& operator<<(ostream& ostr, const EggCarton& right);
        friend istream& operator>>(istream& istr, EggCarton& right);
    };
}
#endif