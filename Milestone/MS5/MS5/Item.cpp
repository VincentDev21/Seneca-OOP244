#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Item.h"
using namespace std;
namespace sdds {
    Item::Item() {
        SKU[0] = '\0';
        delete[] Name;
        Name = nullptr;
        m_price = 0.0;
        taxable = false;
        m_quantity = 0;
        m_displayType = 0;
    }
    Item::Item(const Item& data) {
        if (data) {
            *this = data;
        }
    }

    Item& Item::operator=(const Item& data) {
        if (this != &data) {
            delete[]Name;
            strcpy(SKU, data.SKU);
            m_price = data.m_price;
            taxable = data.taxable;
            m_quantity = data.m_quantity;
            m_displayType = data.m_displayType;
            if (strlen(data.Name) <= MAX_NAME_LEN) {
                Name = new char[strlen(data.Name) + 1];
                strcpy(Name, data.Name);
            }
        }
        return *this;
    }
    Item::~Item() {
        delete[]Name;
        Name = nullptr;
    }
    bool Item::operator ==(const char* other) const {
        return strcmp(SKU, other) == 0;
    }
    bool Item::operator>(const Item& other) const {
        int i = 0;
        while (i < MAX_NAME_LEN && Name[i] != '\0' && other.Name[i] != '\0') {
            if (Name[i] > other.Name[i]) {
                return true;
            }
            else if (Name[i] < other.Name[i]) {
                return false;
            }
            i++;
        }
        return (Name[i] != '\0' && other.Name[i] == '\0');
    }
    int Item::operator+=(int right) {

        if (right < 0)
            return m_quantity;
        int total = m_quantity + right;
        if (total >= MAX_STOCK_NUMBER) {
            m_quantity = MAX_STOCK_NUMBER;
            m_error = ERROR_POS_QTY;
        }
        else {
            m_quantity += right;
        }
        return m_quantity;
    }
    int Item::operator-=(int other) {
        if (other < 0)
            return m_quantity;
        if (other > m_quantity) {
            m_quantity = 0;
            m_error = ERROR_POS_STOCK;
        }
        else {
            m_quantity -= other;
        }
        return m_quantity;
    }
    Item::operator bool() const {
        return !m_error;
    }
    Item& Item::displayType(int pos) {
        m_displayType = pos;
        return *this;
    }
    double Item::cost() const{
        double price = m_price;
        if (taxable) {
            price += (price * TAX);
        }
        return price;
    }
    int Item::quantity() {
        return m_quantity;
    }
    Item& Item::clear() {
        m_error.clear();
        return *this;
    }
    std::ostream& Item::write(std::ostream& os)const {
        double total;
        if (!m_error) {
            if (m_displayType == POS_LIST) {
                os.setf(ios::left);
                os.width(7);
                os << SKU;
                os << "|";
                if (strlen(Name) > 20) {
                    for (int i = 0; i < 20; i++) {
                        if (Name[i] != '\0') {
                            os << Name[i];
                        }
                    }
                }
                else {
                    os.width(20);
                    os << Name;
                }
                os << "|";
                os.width(7);
                os.setf(ios::right);
                os.setf(ios::fixed);
                os << setprecision(2);
                os << m_price;
                os << "|";
                if (taxable) {
                    os << " X ";
                }
                else {
                    os << "   ";
                }

                os << "|";
                os.width(4);
                os << m_quantity;
                os << "|";
                os.width(9);
                os.setf(ios::fixed);

                if (taxable == true) {
                    total = m_price * m_quantity;
                    total = total + (total * TAX);
                    os << setprecision(2);
                    os << total;
                }
                else {
                    total = m_price * m_quantity;
                    os << setprecision(2);
                    os << total;
                }
                os << "|";
                os.unsetf(ios::right);

            }
            if (m_displayType == POS_FORM) {
                os << "=============v" << endl;
                os.setf(ios::left);
                os.width(13);
                os << "Name:";
                os.setf(ios::right);
                os << Name << endl;
                os.unsetf(ios::right);

                os.setf(ios::left);
                os.width(13);
                os << "Sku:";
                os.setf(ios::right);
                os << SKU << endl;
                os.unsetf(ios::right);

                os.setf(ios::left);
                os.width(13);
                os << "Price:";
                os.setf(ios::fixed);
                os << setprecision(2);
                os << m_price << endl;
                os.unsetf(ios::right);

                os.setf(ios::left);
                os.width(13);
                os << "Price + tax:";
                os.setf(ios::right);
                os << setprecision(2);
                if (taxable == true) {
                    total = m_price + (m_price * TAX);
                    os << total << endl;
                }
                else {
                    os << "N/A" << endl;
                }

                os.unsetf(ios::right);

                os.width(13);
                os << "Stock Qty:";
                os << m_quantity << endl;
            }
        }
        else {
            os << m_error;
        }
        return os;
    }
    std::istream& Item::read(std::istream& is) {
        int flag;
        cout << "Sku" << endl;
        cout << "> ";
        is >> SKU;
        if (strlen(SKU) > MAX_SKU_LEN) {
            m_error = ERROR_POS_SKU;
            m_error.display();
            cout << endl;
            flag = 1;
            while (flag == 1) {
                cout << "> ";
                is >> SKU;
                if (strlen(SKU) > MAX_SKU_LEN) {
                    m_error = ERROR_POS_SKU;
                    m_error.display();
                    cout << endl;
                }
                else {
                    flag = 0;
                }
            }
        }
        string temp_name;
        bool valid = false;
        cout << "Name" << endl;
        is.ignore();
        while (!valid) {
            cout << "> ";
            getline(is, temp_name);
            if (temp_name.length() < 40) {
                valid = true;
            }
            else {
                m_error = ERROR_POS_NAME;
                m_error.display();
                cout << endl;
            }
        }
        delete[]Name;
        Name = new char[temp_name.length() + 1];
        strcpy(Name, temp_name.c_str());
        cout << "Price" << endl;
        cout << "> ";
        is >> m_price;
        if (is.fail() || m_price < 0) {
            m_error = ERROR_POS_PRICE;
            m_error.display();
            cout << endl;
            flag = 1;
            while (flag == 1) {
                cout << "> ";
                is.clear();
                is.ignore(1000, '\n');
                is >> m_price;
                if (is.fail() || m_price < 0) {
                    m_error = ERROR_POS_PRICE;
                    m_error.display();
                    cout << endl;
                }
                else {
                    flag = 0;
                }
            }
        }
        cout << "Taxed?" << endl;
        cout << "(Y)es/(N)o: ";

        char tax;
        valid = false;
        while (!valid) {
            cin >> tax;
            if (tax == 'y' || tax == 'Y' || tax == 'n' || tax == 'N') {
                valid = true;
            }
            else {
                cout << "Only 'y' and 'n' are acceptable: ";
                is.clear();
                is.ignore(1000, '\n');
            }
        }
        if (tax == 'y' || tax == 'Y') {
            taxable = true;
        }
        else {
            taxable = false;
        }
        cout << "Quantity" << endl;
        cout << "> ";
        is >> m_quantity;
        if (is.fail() || !(m_quantity > 0 && m_quantity < 100)) {
            is.clear();
            is.ignore(1000, '\n');
            m_error = ERROR_POS_QTY;
            m_error.display();
            cout << endl;
            flag = 1;
            while (flag == 1) {
                cout << "> ";
                is >> m_quantity;
                if (is.fail() || !(m_quantity > 0 && m_quantity < 100)) {
                    is.clear();
                    is.ignore(1000, '\n');
                    m_error = ERROR_POS_QTY;
                    m_error.display();
                    cout << endl;
                }
                else {
                    flag = 0;
                }
            }
        }


        return is;
    }
    std::ofstream& Item::save(std::ofstream& ofs)const {
        ofs << itemType() << "," << SKU << "," << Name << ",";
        ofs.setf(ios::fixed);
        ofs << setprecision(2);
        ofs << m_price;
        ofs << ","
            << taxable << "," << m_quantity;
        return ofs;
    }
    std::ifstream& Item::load(std::ifstream& ifs) {
        m_error.clear();
        double tempPrice = 0;
        int tempTaxed = 0;
        int tempQuantity = 0;
        string sku;
        string name;

        getline(ifs, sku, ',');
        if (sku.length() > MAX_SKU_LEN) {
            m_error = ERROR_POS_SKU;
            return ifs;

        }
        else {
            strcpy(SKU, sku.c_str());
        }
        getline(ifs, name, ',');
        if (name.length() > MAX_NAME_LEN) {
            m_error = ERROR_POS_NAME;
            return ifs;

        }
        else {
            delete[] Name;
            Name = new char[name.length() + 1];
            strcpy(Name, name.c_str());
        }

        ifs >> tempPrice;
        if (tempPrice < 0) {
            m_error = ERROR_POS_PRICE;
            return ifs;

        }
        else {
            m_price = tempPrice;
        }
        ifs.ignore();
        ifs >> tempTaxed;
        if (tempTaxed < 0) {
            m_error = ERROR_POS_TAX;
            return ifs;

        }
        else {
            if (tempTaxed == 1) {
                taxable = true;
            }
            else {
                taxable = false;
            }
        }
        ifs.ignore();
        ifs >> tempQuantity;
        if (tempQuantity > 100) {
            m_error = ERROR_POS_QTY;
            return ifs;

        }
        else {
            m_quantity = tempQuantity;
        }

        return ifs;
    }
    ostream& Item::bprint(ostream& os)const {
        os.setf(std::ios::left);
        os << "| ";
        if (strlen(Name) > 20) {
            for (int i = 0; i < 20; i++) {
                if (Name[i] != '\0') {
                    os << Name[i];
                }
            }
        }
        else {
            os.width(20);
            os << Name;
        }

        os << "|  ";
        os.setf(std::ios::fixed);
        os.setf(std::ios::right);
        os << setprecision(2);
        os.width(8);
        if (taxable) {
            os << m_price * (1 + TAX);
        }
        else {
            os << m_price;

        }
        os.unsetf(std::ios::fixed);
        os << " | ";
        if (taxable) {
            os << " "<<"T" << " ";
        }
        else {
            os << "   ";

        }
        os << " |" << endl;
        os.unsetf(std::ios::right);

        os.setf(std::ios::fixed);
        os << setprecision(2);

        return os;
    }

    double operator+=(double& total, Item& src) {
        total += src.cost() * src.quantity();
        return total;
    }


}