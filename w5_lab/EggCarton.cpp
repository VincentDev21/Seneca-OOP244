#include<iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds {

    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize) {
        if ((size % 6 == 0) && (size >= 6 && size <= 36) && (noOfEggs >= 0 && noOfEggs <= size)) {
            e_size = size;
            e_noOfEggs = noOfEggs;
            e_jumbo = jumboSize;
        }
        else {
            setBroken();
        }
    }
    void EggCarton::setBroken() {
        e_size = -1;
        e_noOfEggs = -1;
    }

    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++) {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }
    ostream& EggCarton::display(ostream& ostr) const {
        if (*this) {
            displayCarton(e_size,  e_noOfEggs,  e_jumbo,  ostr);
        }
        else {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr;
    }
    EggCarton:: operator bool() const {
        if (e_size > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    istream& EggCarton::read(istream& istr) {
        char temp;
        istr>>temp;
        if (temp == 'j') {
            e_jumbo = true;
        }
        else {
            e_jumbo = false;
        }
        istr.ignore();
        istr >> e_size;
        istr.ignore();
        istr >> e_noOfEggs;
        int TF=0;
        TF= (!((e_size % 6 == 0) && (e_size >= 6 && e_size <= 36) && (e_noOfEggs >= 0 && e_noOfEggs <= e_size)));
        if (TF) {
            setBroken();
        }
        return istr;
    }
    EggCarton::operator int() const {
        if (*this) {
            return e_noOfEggs;
        }
        else {
            return -1;
        }
        
    }
    EggCarton::operator double() const {
        double temp;
        if (*this) {
            if (e_jumbo == true) {
                temp = (e_noOfEggs*JumboEggWieght)/1000.0;
                return temp;
            }
            else {
                temp = (e_noOfEggs * RegularEggWieght) / 1000.0;
                return temp;
            }
        }
        else {
            return -1.0;
        }
    }
    EggCarton& EggCarton::operator--() {
        if (*this && e_noOfEggs > 0) {
            e_noOfEggs--;
        }
        return *this;
    }
    EggCarton& EggCarton::operator++() {
        if (*this) {
            e_noOfEggs++;
            if (e_size < e_noOfEggs) {
                setBroken();
            }
        }
        return *this;
    }
    EggCarton EggCarton::operator--(int) {
        EggCarton copy = *this;
        --(*this);
        return copy;
    }
    EggCarton EggCarton::operator++(int) {
        EggCarton copy = *this;
        ++(*this);
        return copy;
    }

    EggCarton& EggCarton::operator=(int value) {
        e_noOfEggs = value;
        if (e_noOfEggs > e_size) {
            setBroken();
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(int value) {
        e_noOfEggs += value;
        if (e_noOfEggs > e_size) {
            setBroken();
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(EggCarton& right) {
        if (*this) {
            e_noOfEggs += right.e_noOfEggs;
            if (e_noOfEggs>e_size) {
                right.e_noOfEggs = e_noOfEggs - e_size;
                e_noOfEggs = e_size;
            }
            else {
                right.e_noOfEggs = 0;
            }
        }
        return *this;

    }
    bool EggCarton::operator==(const EggCarton& right) const {
        bool temp = false;
        double weight = double(*this) - double(right);
        if (weight > -0.001 && weight < 0.001) {
            temp = true;
        }
        return temp;
    }
    int operator+(int left, const EggCarton& right) {
        if (right) {
            left += int(right);
        }
        return left;
    }
    ostream& operator<<(ostream& ostr, const EggCarton& right) {
        return right.display(ostr);
    }
    istream& operator>>(istream& istr, EggCarton& right) {
        return right.read(istr);
    }


}