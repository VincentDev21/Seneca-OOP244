#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include<iostream>
#include<cstring>
#include "Numbers.h"
using namespace std;
namespace sdds {
    void Numbers::sort(double* nums, unsigned int size) {
        unsigned int i, j;
        double temp;
        for (i = size - 1; size && i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }

    unsigned int Numbers::countLines(const char* filename) { 
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }
    Numbers::Numbers(const char* str){
        setEmpty();

        if (str != nullptr) {
            strcpy(filename, str);
            load();
        }
        
    }
    Numbers::Numbers() {
        setEmpty();
    }
    Numbers:: ~Numbers() {
        save();
        delete[] Collection;
    }
    Numbers::Numbers(const Numbers& data) {
        setEmpty();
        if (data) {
            *this = data;
        }
    }    Numbers& Numbers::operator=(const Numbers& right) {
        save();
        delete[] Collection;
        Collection = nullptr;
        Collection_Size = 0;
        original_flag = false;
        strcpy(filename, right.filename);

        Collection_Size = right.Collection_Size;
        Collection = new double[Collection_Size];
        int count = Collection_Size;
        for (int i = 0; i < count; i++)
        {
            Collection[i] = right.Collection[i]; 
        }
        return *this;

    }
    void Numbers::setEmpty() {
        //Collection = nullptr;
        delete[] Collection;
        Collection = nullptr;
        Collection_Size = 0;
        filename[0] = '\0';
        original_flag = false;
        added_flag = false;

    }
    void Numbers::sort() {
        sort(Collection,Collection_Size);
    }
    bool Numbers::load() {

        int i = 0;
        delete[] Collection;
        Collection = nullptr;
        int count;
        count =countLines(filename);
        if (count > 0) {
            Collection = new double[count];
            ifstream f(filename);
            while (f) {
                f >> Collection[i];
                i++;
            }
            i--;
            if (count != i) {
                setEmpty();
            }
            else {
                Collection_Size = i;
                original_flag = true;
                
            }
            f.close();
        }
        if (i >= 1) {
            return true;
        }
        else {
            return false;
        }
    }
    void Numbers::save() {
        if (original_flag == true && added_flag==true) {
            ofstream fout(filename);
            int i;
            int count = Collection_Size;

            for (i = 0; i < count; i++) {
                fout.setf(ios::fixed);
                fout.precision(2);
                fout << Collection[i]<<endl;

            }
            fout.close();
        }
    }
    Numbers::operator bool() const {

        return true;
    }
    Numbers& Numbers::operator+=(double data) {
        int count = Collection_Size;
        double* numbers = new double[count + 1];

        for (int i = 0; i < count; i++) {

            numbers[i] = Collection[i]; 

        }
        added_flag = true;
        Collection_Size++; 

        numbers[Collection_Size - 1] = data; 

        delete[] Collection; 

        Collection = numbers; 
        return *this;

    }
   
    istream& operator >>(istream& istr, Numbers& data)
    {
        double num;
        istr >> num;
        data += num;
        
        return istr;
        
    }
    Numbers& Numbers::operator +=(const Numbers& data) {
        Collection = new double[data.Collection_Size+Collection_Size];
        int count = data.Collection_Size;

        for (int i = Collection_Size; i < count; i++) {
            Collection[i] = data.Collection[i];
        }
        added_flag = true;
        
        return *this;

    }
    ostream& operator<<(ostream& ostr, const Numbers& data) {
        return data.display(ostr);
    }
    ostream& Numbers::display(std::ostream& ostr) const  {
        int count = Collection_Size;

        if (Collection_Size == 0) {
            ostr << "Empty list";
        }
        else {
            ostr.setf(ios::fixed);
            ostr.precision(2) ;
            if (original_flag == false) {
                ostr << "Copy of ";
            }
            ostr << filename << endl;
            int i;
            for (i = 0; i < count; i++) {
                ostr << Collection[i];
                if (i != count -1) {
                    ostr << ", ";
                }
            }
            ostr << endl;
            ostr << "----------------------------------------------------------------------------" << endl;
            ostr << "Total of " << Collection_Size<<" number(s), ";
            ostr << "Largest: " << max();
            ostr << ", Smallest: " <<min();
            ostr << ", Average: " << average()<<endl;
            ostr << "============================================================================";
        }
        return ostr;
    }

    
    
    double Numbers:: max() const {
        double data=0.0;
        data = Collection[0];

        int count = Collection_Size;

        for (int i = 1; i < count; i++) {
            if (data < Collection[i]) {
                data = Collection[i];
            }
        }
        return data;
    }
    double Numbers::min() const {
        double data=0.0;
        data = Collection[0];
        int count = Collection_Size;

        for (int i = 1; i < count; i++) {
            if (data > Collection[i])
            {
                data = Collection[i];
            }
        }

        return data;

    }
    double Numbers::average() const {
        double average = 0.0;
        int count = Collection_Size;

        for (int i = 0; i < count; i++) {
            average += Collection[i];
        }
        return average/(double)Collection_Size;
    }
}