#pragma once
#ifndef SDDS_ITEM_H_
#include"POS.h"
#include "PosIO.h"
#include"Error.h"
namespace sdds {
    class Item :public PosIO {
        char SKU[MAX_SKU_LEN] = { '\0' };
        char* Name = nullptr;
        double m_price = 0.0;
        bool taxable = false;
        int m_quantity = 0;
        int m_displayType = 0;
    protected:
        Error m_error;
    public:
        Item();
        Item(const Item* data);
        ~Item();
        Item& operator=(const Item& data);
        bool operator ==(const char* other) const;
        bool operator>(const Item& other) const;
        int& operator+=(int right);
        int operator-=(int other);
        operator bool() const;
        Item& displayType(int pos);
        double cost();
        int quantity();
        Item& clear();
        virtual std::ostream& write(std::ostream& os) const;
        virtual std::istream& read(std::istream& is);

        virtual std::ofstream& save(std::ofstream& ofs)const;
        virtual std::ifstream& load(std::ifstream& ifs);
        std::ostream& bprint(std::ostream& os);
    };
    double operator+=(double& total,  Item& src);

}

#endif 
