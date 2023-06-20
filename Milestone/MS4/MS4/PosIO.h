#pragma once
#ifndef SDDS_POSIO_H_
#define SDDS_POSIO_H_
#include <iostream>
namespace sdds {
    class PosIO {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual std::ofstream& save(std::ofstream& ofs) const = 0;
        virtual std::ifstream& load(std::ifstream& ifs) = 0;
    };
    std::istream& operator>>(std::istream& is, PosIO& posIO);
    std::ostream& operator<<(std::ostream& os, const PosIO& posIO);

    std::ifstream& operator>>(std::ifstream& ifs, PosIO& posIO);
    std::ofstream& operator<<(std::ofstream& ofs, const PosIO& posIO);


}
#endif 

