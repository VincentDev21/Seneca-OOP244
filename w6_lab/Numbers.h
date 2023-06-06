#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
using namespace std;
namespace sdds {
    class Numbers {
        double* Collection=nullptr;
        char filename[255];
        unsigned int Collection_Size=0;
        bool original_flag=false;
        bool added_flag=false;
        unsigned int countLines(const char* filename);
        void sort(double* collectionPtr, unsigned int size);
        void setEmpty();
        bool load();
        void save();
        double max() const;
        double min()const;
        double average()const;


    public:
	Numbers();
        Numbers(const char* str);
        
        ~Numbers();
        Numbers(const Numbers& data);
        Numbers& operator=(const Numbers& data);
        void sort();
        operator bool() const;
        Numbers& operator+=(double data);
        std::ostream& display(std::ostream& ostr = std::cout) const;
        
        Numbers& operator +=(const Numbers& data);

    };
    istream& operator >>(istream& istr, Numbers& data);

    ostream& operator<<(ostream& ostr, const Numbers& data);
}
#endif // !SDDS_NUMBERS_H_
