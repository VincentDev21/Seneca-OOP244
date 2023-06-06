#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NameTag.h"
using namespace std;

namespace sdds {
	NameTag::NameTag() {
		setEmpty();
	}
	NameTag::NameTag(const char* name) {
		setName(name);
		t_ext = -1;

	}
	NameTag::NameTag(const char* name, int ext) {
		setName(name);
		setExt(ext);
	}
	
	NameTag::~NameTag() {
		delete[]t_name;
		t_name = nullptr;
		t_ext = 0;
		
	}
	void NameTag::setEmpty() {

		t_name = nullptr;
		t_ext = 0;
	}
	void NameTag::setName(const char* name) {
		int i;
		t_name = new char[41];
		if (name != nullptr) {
			for (i = 0; i < 40; i++) {
				t_name[i] = name[i];
				
				
			}
			t_name[40] = '\0';
		}
		else {
			delete[]t_name;
			t_name = nullptr;
			setEmpty();
		}
	}
	void NameTag::setExt(int ext) {
		if (ext >= 10000 && ext <= 99999) {
			t_ext = ext;
		}
		else {
			t_ext = 0;
		}
		
	}
	void NameTag::fill(int length) {
		cout.unsetf(ios::left);
		cout << "| ";
		cout.width(length);
		cout.fill(' ');
		cout << " |" << endl;
	}
	void NameTag::header_and_foot(int length) {
		cout.unsetf(ios::left);
		cout << "+-";
		cout.fill('-');
		cout.width(length);
		cout << "-+"<<endl;

	}
	void NameTag::Extension(int length) {
		cout.setf(ios::left);
		cout.width(11);
		cout.fill(' ');
		cout << "Extension:";
		cout.width(length-11);
		if (t_ext == -1) {
			cout.setf(ios::left);
			cout << "N/A";
		}
		else {
			cout.setf(ios::left);
			cout << t_ext;
		}
		cout << " |" << endl;
	}
	void NameTag::print() {
		
		if (t_name == nullptr||t_ext==0) {
			cout << "EMPTY NAMETAG!"<<endl;
		}
		else {
			int length = strlen(t_name);
			
			if (length < 20) {
				header_and_foot(22);
				fill(22);
				cout << "| ";
				cout.setf(ios::left);
				cout.width(20);
				cout.fill(' ');
				cout << t_name;
				cout << " |"<<endl;
				fill(22);
				cout << "| ";
				Extension(20);
				fill(22);
				header_and_foot(22);
			}
			else {
				header_and_foot(length+2);
				fill(length + 2);
				cout << "| ";
				cout.setf(ios::left);
				cout.width(length);
				cout.fill(' ');
				cout << t_name;
				cout << " |" << endl;
				fill(length + 2);
				cout << "| ";
				Extension(length);
				fill(length + 2);
				header_and_foot(length + 2);
			}
			
		}
		delete[]t_name;
		t_name = nullptr;
	}
	bool NameTag::Valid_Selection(char input) {
		if (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
			return false;
		}
		else {
			return true;
		}
	}
	bool NameTag::valid(int input) {
		if (input >= 10000 && input <= 99999) {
			return true;
		}
		else {
			return false;
		}
	}
	NameTag& NameTag::read() {
		
		char name[500];
		char selection;
		int extension;
		int flag = 0;
		cout << "Please enter the name: ";
		cin.getline(name, 41);
		if (strlen(name) >= 39) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		setName(name);
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		cin >> selection;
		while (!Valid_Selection(selection)) {
			cout << "Only (Y) or (N) are acceptable, try agin: ";
			cin >> selection;
		}
		if (selection == 'y' || selection == 'Y') {
			cout << "Please enter a 5 digit phone extension: ";
			
			while (flag == 0) {
				cin >> extension;
				if (!cin)
				{
					cout << "Bad integer value, try again: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else {
					if (valid(extension)) {
						flag = 1;
					}
					else {
						cout << "Invalid value [10000<=value<=99999]: ";
						cin.clear();
						cin.ignore(1000, '\n');
						flag = 0;
					}
				}
			}
			setExt(extension);
			//cout << endl;
		}
		else {
			t_ext = -1;
		}
		cin.ignore();
		return *this;
	}
}
