#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Toys.h"

using namespace std;

namespace sdds {
	Toys::Toys() {
		m_tname[0] = '\0';
		m_sku = 0;
		m_price = 0.0;
		m_age = 0;
		m_onSale = false;
	}
	int Toys::sku() {
		return m_sku;
	}
	void Toys::addToys(const char* tname, int sku, double price, int age) {
		
		int len = 0;
		int check = sku;
		while (check != 0) {
			check /= 10;
			len++;
		}
		if (tname == nullptr || len != 8) {
			m_tname[0] = '\0';
			m_sku = 0;
			m_price = 0;
			m_age = 0;
		}
		else {
			strcpy(m_tname, tname);
			m_sku = sku;
			m_price = price;
			m_age = age;
		}
	}
	void Toys::isSale(bool sale) {
		if (sale == true) {
			m_onSale = true;
		}
		
	}
	void Toys::calSale() {
		double temp;
		double total;
		if (m_onSale == true) {
			temp = m_price;
			total = temp - (m_price * 0.2);
		}
		else {
			total = m_price;
		}
		m_price = total;
	}
	void Toys::display()const {
		if (m_tname[0] == '\0') {
			cout << "Invalid Toy";
		}
		else {
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(15);
			cout << m_tname;
			cout.setf(ios::right);
			cout.width(10);
			cout << m_sku;
			cout.setf(ios::right);
			cout.width(6);
			cout << m_age;
			cout.setf(ios::right);
			cout.width(12);
			cout.precision(4);
			cout << m_price;
			if (m_onSale == true) {
				cout.width(11);
				cout << "On Sale ";
			}
			else {
				cout.width(8);
				cout<<"        ";
			}
			


				
		}
	}
}