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
#include <cstring>
#include "PosApp.h"
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
		cout << "5- Point of Sale" << endl;
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
		while (a!=0) {
			a= menu();
			switch (a) {
			case 1:
				cout << ">>>> Listing Items..........................................................." << endl;
				listItems();
				break;
			case 2:
				cout << ">>>> Adding Item to the store................................................" << endl;
				addItem();
				break;
			case 3:
				cout << ">>>> Remove Item............................................................." << endl;
				removeItem();
				break;
			case 4:
				cout << ">>>> Select an item to stock................................................." << endl;
				stockItem();
				break;
			case 5:
				cout << ">>>> Starting Point of Sale.................................................." << endl;
				pointOfSale();
				break;
			case 0:
				saveRecs();
				break;
			}
		}
		cout << "Goodbye!"<<endl;
	}
	void PosApp::listItems(){
		cout << "Running listItems()" << endl;
	}
	void PosApp::addItem(){
		cout << "Running addItem()" << endl;
	}
	void PosApp::removeItem(){
		cout << "Running removeItem()" << endl;
	}
	void PosApp::stockItem(){
		cout << "Running stockItem()" << endl;
	}
	void PosApp::pointOfSale(){
		cout << "Running POS()" << endl;
	}
	void PosApp::loadRecs() {
		cout << ">>>> Loading Items..........................................................." << endl;
		cout << "Loading data from " << filename<<endl;
	}
	void PosApp::saveRecs() {
		cout << ">>>> Saving Data............................................................." << endl;
		cout << "Saving data in " << filename << endl;
	}
}