#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Store.h"

using namespace std;

namespace sdds {
	
	void Store::setStore(const char* sName, int no) {
		strcpy(m_sName, sName);
		if (no == 0) {
			m_noOfToys = 0;
		}
		else {
			m_noOfToys = no;
		}
		m_addToys = 0;
	}
	void Store::setToys(const char* tname, int sku, double price, int age) {
		m_toy[m_addToys].addToys(tname, sku, price, age);
		m_addToys++;
	}
	void Store::display() const {
		int i = 0;
		for (i = 0; i < 60; i++){
			cout << "*";
		}
		cout << endl;
		if (m_sName == NULL) {
			cout << "Invalid Store" << endl;
		}
		else {
			cout << m_sName<<endl;

		}
		for (i = 0; i < 60; i++) {
			cout << "*";
		}
		cout << endl;
		cout << "list of the toys" << endl;
		cout.width(30);
		cout << "SKU";
		cout.width(10);
		cout << "Age";
		cout.width(11);
		cout << "Price";
		cout.width(10);
		cout << "Sale";
		for (i = 0; i < m_noOfToys; i++) {
			cout << "\nToy[" << i+1 << "] :";
			m_toy[i].display();
			
		}
		cout << endl;
	}
	void Store::find(int sku) {
		
		int i = 0;
		for (i = 0; i < m_noOfToys; i++) {
			if (m_toy[i].sku()==sku) {
				m_toy[i].isSale(true);
				m_toy[i].calSale();
			}
			else {
				m_toy[i].isSale(false);
			}
		}
	}
	void Store::setEmpty() {
		m_sName[0] = '\0';
		m_noOfToys=0;
		m_addToys=0;
	}
}