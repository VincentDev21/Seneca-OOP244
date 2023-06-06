#include <iostream>

#include "UI.h"
#include "GPA.h"
using namespace std;
namespace sdds {
	
	bool valid(char a) {
		return (a == '>' || a == '<' || a == '~' || a == '!');
	}
	void error() {
		cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
		cout << "Op: [>,<,~,!]" << endl;
		cout << "value: GPA value" << endl<<endl;
	}
	void userinput(char* character, double* gpa) {
		double b;
		char a;
		int c=0;
		while (c == 0) {
			cout << "? "; cin >> a;
			if (a == '!') {
				c = 1;
				b = 0;
			}
			else {
				cin >> b;

			}

			if (valid(a) >0) {
				*character = a;
				*gpa = b;
				c = 1;
			}
			else {
				error();
			}
		}
		
	}
	void output(const struct GPA* gpa, char a, double b, int max) {
		int i=0;
		int count = 0;
		switch (a) {
		case '>':
			for (i = 0; i < 100; i++) {
				if (gpa[i].gpa > b && gpa[i].stno != 0) {
					count++;
					cout << "[" << count << "] " << gpa[i].stno << ": "; printf("%.1lf", gpa[i].gpa); cout << " (" << gpa[i].name  << ")" << endl;
				}
			}
			break;
		case '<':
			for (i = 0; i < 100; i++) {
				if (gpa[i].gpa < b && gpa[i].gpa >= 0&&gpa[i].stno!=0) {
					count++;
					cout << "[" << count << "] " << gpa[i].stno << ": "; printf("%.1lf", gpa[i].gpa); cout << " (" << gpa[i].name  << ")" << endl;
				}
			}
			break;
		case '~':
			for (i = 0; i < 100; i++) {
				if (b == gpa[i].gpa && gpa[i].stno != 0) {
					count++;
					cout << "[" << count << "] " << gpa[i].stno << ": "; printf("%.1lf", gpa[i].gpa); cout << " (" << gpa[i].name  << ")" << endl;
				}
			}
			break;
		}
	}
	void Sort(struct GPA* data, int size) {
		int i=0, y=0;
		struct GPA temp;
		for (i = 0; i < size; i++) {
			for (y = 0; y < size; y++) {
				if (data[i].stno < data[y].stno)
				{
					temp = data[i];
					data[i] = data[y];
					data[y] = temp;
				}
			
			}
		}
	}
	bool exit() {
		char a;
		int b=1;
		do {
			cout << "Exit the program? (Y)es/(N)o: ";
			cin >> a;
			if (a == 'Y' || a=='y') {
				return false;
				b = 0;
			}
			if (a == 'N' || a=='n') {
				b = 0;
			}
			else {
				cout << "Error enter valid input" << endl;
			}
		} while (b);
		return true;
	}
}
