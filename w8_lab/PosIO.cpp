#include <iostream>
#include "PosIO.h"
using namespace std;
namespace sdds {
    std::istream& operator>>(std::istream& is, PosIO& posIO) {
        return posIO.read(is);
    }
    std::ostream& operator<<(std::ostream& os, const PosIO& posIO) {
        return posIO.write(os);
    }

    std::ifstream& operator>>(std::ifstream& ifs, PosIO& posIO) {
        return posIO.load(ifs);
    }

    std::ofstream& operator<<(std::ofstream& ofs, const PosIO& posIO) {
        return posIO.save(ofs);
    }

}
