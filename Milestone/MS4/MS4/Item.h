#pragma once
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include"POS.h"
#include "PosIO.h"
#include"Error.h"
namespace sdds {
    class Item :public PosIO {
        char SKU[MAX_SKU_LEN] = { '\0' };
        char* Name = nullptr;
        double price;
        bool taxable = false;
        int Quantity = 0;
    protected:
        int DisplayType = 0;
        Error error;
    public:
        Item();
        Item(const Item& data);
        virtual~Item();
        Item& operator=(const Item& data);
        bool operator ==(const char* other) const;
        bool operator>(const Item& other) const;
        int operator+=(int right);
        int operator-=(int other);
        operator bool() const;
        virtual char itemType() const = 0;
        Item& displayType(int pos);
        double cost()const;
        int quantity();
        Item& clear();
        virtual std::ostream& write(std::ostream& os) const;
        virtual std::istream& read(std::istream& is);

        virtual std::ofstream& save(std::ofstream& ofs)const;
        virtual std::ifstream& load(std::ifstream& ifs);
        std::ostream& bprint(std::ostream& os)const;
    };
    double operator+=(double& total, Item& src);


}



#endif 
