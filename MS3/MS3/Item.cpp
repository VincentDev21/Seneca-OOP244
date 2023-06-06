#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Item.h"
using namespace std;
namespace sdds {
    Item::Item() : price(0.0), taxable(false), Quantity(0), DisplayType(0) {
        SKU[0] = '\0';
        Name = nullptr;
    }

    Item::Item(const Item& other) {
        *this = other;
    }

    Item& Item::operator=(const Item& other) {
        if (this != &other) {
            delete[] Name;
            Name = nullptr;
            strcpy(SKU, other.SKU);
            price = other.price;
            taxable = other.taxable;
            Quantity = other.Quantity;
            DisplayType = other.DisplayType;
            if (other.Name != nullptr) {
                Name = new char[strlen(other.Name) + 1];
                strcpy(Name, other.Name);
            }
        }
        return *this;
    }

    Item::~Item() {
        delete[] Name;
        Name = nullptr;
    }

    bool Item::operator ==(const char* SKU) const {
        return strcmp(this->SKU, SKU) == 0;
    }

    bool Item::operator>(const Item& other) const {
        return strcmp(Name, other.Name) > 0;
    }

    int Item::operator+=(int m_quantity) {
        if (m_quantity < 0) {
            return Quantity;
        }
        int newQuantity = Quantity + m_quantity;
        if (newQuantity > MAX_STOCK_NUMBER) {
            Quantity = MAX_STOCK_NUMBER;
            error = ERROR_POS_QTY;
        }
        else {
            Quantity = m_quantity;
        }
        return Quantity;
    }

    int Item::operator-=(int m_quantity) {
        if (m_quantity < 0) {
            return Quantity;
        }
        if (m_quantity > Quantity) {
            Quantity = 0;
            error = ERROR_POS_STOCK;
        }
        else {
            Quantity -= m_quantity;
        }
        return Quantity;
    }

    Item::operator bool() const {
        return !error;
    }
    Item& Item::displayType(int pos) {
        DisplayType = pos;
        return *this;
    }
    double Item::cost() const {
        double m_price = price;
        if (taxable) {
            m_price += (price * TAX);
        }
        return m_price;
    }
    int Item::quantity() {
        return Quantity;
    }
    Item& Item::clear() {
        error.clear();
        return *this;
    }
    std::ostream& Item::write(std::ostream& os) const {
        double total;
        if (!error) {
            if (DisplayType == POS_LIST) {
                os << std::left << std::setw(7) << SKU << "|";
                if (strlen(Name) > 20) {
                    for (int i = 0; i < 20; i++) {
                        if (Name[i] != '\0') {
                            os << Name[i];
                        }
                    }
                }
                else {
                    os << std::setw(20) << Name;
                }
                os << "|";
                os << std::right << std::setw(7) << std::fixed << std::setprecision(2) << price << "|";
                os << (taxable ? " X " : "   ") << "|";
                os << std::setw(4) << Quantity << "|";
                os << std::setw(9) << std::fixed;
                if (taxable == true) {
                    total = price * Quantity;
                    total = total + (total * TAX);
                    os << std::setprecision(2) << total;
                }
                else {
                    total = price * Quantity;
                    os << std::setprecision(2) << total;
                }
                os << "|";
            }
            else if (DisplayType == POS_FORM) {
                os << "=============v" << std::endl;
                os << std::left << std::setw(13) << "Name:" << std::right << Name << std::endl;
                os << std::left << std::setw(13) << "Sku:" << std::right << SKU << std::endl;
                os << std::left << std::setw(13) << "Price:" << std::right << std::fixed << std::setprecision(2) << price << std::endl;
                os << std::left << std::setw(13) << "Price + tax:" << std::right;
                if (taxable == true) {
                    total = price + (price * TAX);
                    os << std::setprecision(2) << total << std::endl;
                }
                else {
                    os << "N/A" << std::endl;
                }
                os << std::left << std::setw(13) << "Stock Qty:" << std::right << Quantity << std::endl;
            }
        }
        else {
            os << error;
        }
        return os;
    }


    std::istream& Item::read(std::istream& is) {
        std::string temp_name;
        bool valid_input = false;
        std::cout << "Sku" << std::endl;

        while (!valid_input) {
            std::cout << "> ";
            is >> SKU;
            if (strlen(SKU) > MAX_SKU_LEN) {
                error = ERROR_POS_SKU;
                error.display();
                std::cout << std::endl;
            }
            else {
                valid_input = true;
            }
        }
        valid_input = false;
        std::cout << "Name" << std::endl;

        while (!valid_input) {
            std::cout << "> ";
            std::getline(is >> std::ws, temp_name);
            if (temp_name.length() >= 40) {
                error = ERROR_POS_NAME;
                error.display();
                std::cout << std::endl;
            }
            else {
                valid_input = true;
                delete[] Name;
                Name = new char[temp_name.length() + 1];
                std::strcpy(Name, temp_name.c_str());
            }

        }
        valid_input = false;
        std::cout << "Price" << std::endl;

        while (!valid_input) {
            std::cout << "> ";

            if (!(is >> price) || price < 0) {
                error = ERROR_POS_PRICE;
                error.display();
                std::cout << std::endl;
                is.clear();
                is.ignore(1000, '\n');
            }
            else {
                valid_input = true;
            }
        }
        valid_input = false;
        std::cout << "Taxed?" << std::endl << "(Y)es/(N)o: ";

        while (!valid_input) {
            char tax_choice;
            if (!(is >> tax_choice) || (tax_choice != 'y' && tax_choice != 'Y' && tax_choice != 'n' && tax_choice != 'N')) {
                std::cout << "Only 'y' and 'n' are acceptable: ";
                is.clear();
                is.ignore(1000, '\n');
            }
            else {
                taxable = (tax_choice == 'y' || tax_choice == 'Y');
                valid_input = true;
            }

        }
        valid_input = false;
        std::cout << "Quantity" << std::endl;

        while (!valid_input) {
            std::cout << "> ";
            if (!(is >> Quantity) || !(Quantity > 0 && Quantity < 100)) {
                error = ERROR_POS_QTY;
                error.display();
                std::cout << std::endl;
                is.clear();
                is.ignore(1000, '\n');
            }
            else {
                valid_input = true;
            }
        }

        return is;
    }


    std::ofstream& Item::save(std::ofstream& ofs) const {
        ofs << itemType() << ",";
        ofs << SKU << ",";
        ofs << Name << ",";
        ofs << std::fixed << std::setprecision(2) << price << ",";
        ofs << taxable << ",";
        ofs << Quantity;
        return ofs;
    }

    std::ifstream& Item::load(std::ifstream& ifs) {
        error.clear();
        int tax = 0;
        std::string temp;

        // Read SKU from file
        if (!getline(ifs, temp, ',') || temp.length() > MAX_SKU_LEN) {
            error = ERROR_POS_SKU;
            return ifs;
        }
        std::strcpy(SKU, temp.c_str());

        // Read Name from file
        if (!getline(ifs, temp, ',') || temp.length() > MAX_NAME_LEN) {
            error = ERROR_POS_NAME;
            return ifs;
        }
        delete[] Name;
        Name = new char[temp.length() + 1];
        std::strcpy(Name, temp.c_str());


        // Read Price from file
        if (!(ifs >> price) || price < 0) {
            error = ERROR_POS_PRICE;
            return ifs;
        }
        ifs.ignore();

        // Read Taxed from file
        if (!(ifs >> tax) || (tax != 0 && tax != 1)) {
            error = ERROR_POS_TAX;
            return ifs;
        }
        taxable = (tax == 1);
        ifs.ignore();

        // Read Quantity from file
        if (!(ifs >> Quantity) || Quantity < 0 || Quantity > 100) {
            error = ERROR_POS_QTY;
            return ifs;
        }

        return ifs;
    }




    ostream& Item::bprint(ostream& os) const {
        os << "| " << setw(20) << left << (strlen(Name) > 20 ? string(Name, 20) : Name)
            << "|  " << setw(8) << right << fixed << setprecision(2)
            << (taxable ? (price * (1 + TAX)) : price)
            << " | " << setw(3) << (taxable ? "T" : "") << " |" << endl;
        os.unsetf(ios::fixed | ios::right | ios::left);
        return os;
    }



    double operator+=(double& total, Item& src) {
        total += src.cost() * src.quantity();
        return total;
    }


}