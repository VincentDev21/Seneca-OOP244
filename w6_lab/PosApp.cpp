/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.h
Version 1.0
Author	Vincent Le
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
#include <cstring>
#include<iomanip>
#include "PosApp.h"
#include"Perishable.h"
#include"NonPerishable.h"
using namespace std;
namespace sdds {
	PosApp::PosApp(const char* name) {
		strcpy(filename, name);
	}
	
	int PosApp::menu() {
		int flag = 1;
		int selection;

		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add item" << endl;
		cout << "3- Remove item" << endl;
		cout << "4- Stock item" << endl;
		cout << "5- POS" << endl;
		cout << "0- exit program" << endl;
		cout << "> ";
		while (flag == 1) {
			cin >> selection;
			if (cin.fail()) {
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (selection < 0 || selection>5) {
				cout << "[0<=value<=5], retry: > ";
			}
			else {
				flag = 0;

			}
		}
		return selection;
	}
	

	void PosApp::run() {
		int a = 1;
		loadRecs();
		while (a != 0) {
			a = menu();
			switch (a) {
			case 1:
				listItems(true);
				break;
			case 2:
				addItem();
				break;
			case 3:
				removeItem();
				break;
			case 4:
				stockItem();
				break;
			case 5:
				pointOfSale();
				break;
			case 0:
				saveRecs();
				break;
			}
		}
		cout << "Goodbye!" << endl;
	}
	void PosApp::sortItems() {
		for (int i = 0; i < nptr - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < nptr; j++) {
				if (*Iptr[j] < *Iptr[minIndex]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				Item* temp = Iptr[i];
				Iptr[i] = Iptr[minIndex];
				Iptr[minIndex] = temp;
			}
		}
	}

	void PosApp::listItems(bool boolean) {
		ActionTitle("Listing Items");
		double total = 0.0;

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |"<<endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|-------------|"<<endl;
		
		for (int i = 0; i < nptr; i++) {
			for (int j = i + 1; j < nptr; j++) {
				if (*Iptr[i] > *Iptr[j]) {
					Item* temp = Iptr[i];
					Iptr[i] = Iptr[j];
					Iptr[j] = temp;
				}
			}
		}

		for (int a = 0; a < nptr; a++) {
			cout << std::setw(4);
			cout.setf(ios::right);
			cout<< a + 1 << " | ";
			cout.unsetf(ios::right);

			Iptr[a]->displayType(POS_LIST);
			Iptr[a]->write(cout);
			total += Iptr[a]->quantity() * Iptr[a]->cost();
			cout << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;

		if (boolean == true) {
			cout << "                               Total Asset: $  |" << setw(14) << fixed << setprecision(2);
			cout.setf(ios::right);
			cout << total << "|" << endl;
			cout.unsetf(ios::right);
			cout << "-----------------------------------------------^--------------^" << endl << endl;
		}
		
	}
	void PosApp::addItem() {
		char input;
		ActionTitle("Adding Item to the store");
		if (nptr == MAX_NO_ITEMS) {
			cout << "Inventory Full!" << endl;
		}
		else {
			Item* item;
			cout << "Is the Item perishable? (Y)es/(N)o: ";
			bool valid = false;
			while (!valid) {
				cin >> input;
				if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') {
					valid = true;
				}
				else {
					cout << "Only 'y' and 'n' are acceptable: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
			if (input == 'y' || input == 'Y') {
				item = new Perishable();
			}
			else {
				item = new NonPerishable();
			}
			valid = false;
			while (!valid) {
				item->read(cin);
				if (!item) {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << ", try again...\n";
				}
				else {
					Iptr[nptr] = item;
					nptr++;
					valid = true;
				}
			}
			
		}
		ActionTitle("DONE");
	}
	int PosApp::selectItem() {
		int flag = 1;
		int selection;
		ActionTitle("Item Selection by row number");
		cin.ignore(1000, '\n');
		cout << "Press <ENTER> to start....";
			cin.ignore(1000,'\n');
		listItems(false);
		cout << "Enter the row number: ";
		while (flag == 1) {
			cin >> selection;
			if (cin.fail()) {
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (selection < 1 || selection>nptr) {
				cout << "[1<=value<="<<nptr<<"], retry: > ";
			}
			else {
				flag = 0;
			}
		}
		return selection;
	}

	void PosApp::removeItem() {
		int selection = selectItem();
		selection--;
		cout << "Removing...." << endl;
		Iptr[selection]->displayType(POS_FORM);
		Iptr[selection]->write(cout);
		delete Iptr[selection];
		Iptr [selection] = nullptr;
		int num;
		Item* temp;
		for (int i = selection; i < nptr; i++) {
			if (Iptr[i] == nullptr) {
				num = i+1;
				temp = Iptr[num];
				Iptr[i] = temp;
				Iptr[num] = nullptr;

			}
		}
		nptr--;
		ActionTitle("Done!");
	}
	void PosApp::stockItem() {
		ActionTitle("Select an item to stock");
		
		int flag=1;
		int quantity;
		int selection = selectItem();
		selection--;
		Iptr[selection]->displayType(POS_FORM);
		Iptr[selection]->write(cout);

		cout << "Enter quantity to add: ";
		while (flag == 1) {
			cin >> quantity;
			if (cin.fail()) {
				cout << "Invalid Integer, try again: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}
			else if (quantity < 1 || quantity>MAX_STOCK_NUMBER-Iptr[selection]->quantity()) {
				cout << "[1<=value<=" << MAX_STOCK_NUMBER - Iptr[selection]->quantity() << "], retry: > ";
			}
			else {
				flag = 0;
			}
			Iptr[selection][0] += quantity;
			
		}
	}
	void PosApp::pointOfSale() {
		string sku;
		double total=0.0;
		bool valid=false;
		int selection;
		Bill temp;
		ActionTitle("Starting Point of Sale");
		cout << "Enter SKU or <ENTER> only to end sale..." << endl;
		cout << ">";
		cin.ignore();
		while (1) {
			//cin.ignore();
			//cin.getline(sku, 8);
			//cin >> sku;
			getline(cin, sku);
			if (sku[0] == '\0') {
				break;
			}
			if (cin.fail()) {

			}
			else {
				for (int i = 0; i < nptr; i++) {
					if (Iptr[i][0] == sku.c_str() ) {
						valid = true;
						selection = i;
						i = nptr;

					}
					else {
						valid = false;
					}
				}
				if (valid&&Iptr[selection]->quantity()!=0) {
					Iptr[selection][0] -= 1;
					Iptr[selection]->displayType(POS_FORM);
					Iptr[selection]->write(cout);
					total += Iptr[selection]->cost();
					temp.add(Iptr[selection]);
					cout << endl << endl;
					cout << ">>>>> Added to bill" << endl;
					cout << ">>>> > Total: "<< fixed << setprecision(2)<< total << endl;
					
				}
				else {
					if (!valid) {
						cout << "!!!!! Item Not Found !!!!!" << endl;
					}
					else {
						cout << "Item out of stock" << endl;

					}
				}
			}
			cout << "Enter SKU or <ENTER> only to end sale..." << endl;
			cout << ">";
		}
		temp.print(cout);
		
		//cout << fixed << setprecision(2)<< total;
	}
	void PosApp::ActionTitle(const char* title) {
		cout << ">>>> ";
		cout.width(72);
		cout.fill('.');
		cout.setf(ios::left);
		cout << title << endl;
		cout.fill(' ');
		cout.unsetf(ios::left);
		
	}
	void PosApp::loadRecs() {
		ActionTitle("Loading Items");
		int i;

		for (i = 0; i < nptr; i++) {
			delete Iptr[i];
			Iptr[i] = nullptr;
		}
		nptr = 0;
		char id;
		ifstream file(filename);
		if (file.fail())
		{
			ofstream data(filename);
			data.close();

		}
		else {
			while (!file.eof()) {

				file.get(id);

				if (id == 'P' || id == 'N') {
					if (id == 'P') {
						Iptr[nptr] = new Perishable();
					}
					else if (id == 'N') {
						Iptr[nptr] = new NonPerishable();
					}
					file.ignore();
					Iptr[nptr++]->load(file);
				}
			}
			ofstream data(filename);
			data.close();
		}
	}
	void PosApp::saveRecs() {
		ActionTitle("Saving Data");
		ofstream ofs(filename);
		for (int i = 0; i < nptr; i++) {
			for (int j = i + 1; j < nptr; j++) {
				if (*Iptr[i] > *Iptr[j]) {
					Item* temp = Iptr[i];
					Iptr[i] = Iptr[j];
					Iptr[j] = temp;
				}
			}
		}
		for (int i = 0; i < nptr; i++) {
			Iptr[i]->save(ofs);
			ofs << endl;
		}
		for (int i = 0; i < nptr; i++) {
			delete Iptr[i];
			Iptr[i] = nullptr;
		}
		nptr = 0;
		ofs.close();
	}
}