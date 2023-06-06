#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"GPAlist.h"
#include "GPA.h"
#include"File.h"
#include"UI.h"
using namespace std;
using namespace sdds;

namespace sdds {
	bool gpaQuery(const char* filename) {
		GPA* gpa=nullptr;
		gpa = new GPA[100];
		FILE* file=NULL;
		
		file = fopen(filename, "r");
		if (file == NULL) {
			return false;
			fclose(file);
		}
		else {
			char a;
			double b;
			int c=1;
			
			int size=import(file, gpa);
			Sort(gpa, size);
			cout << "Enter GPA query..." << endl;
			do {
				do {
					
					userinput(&a, &b);
					output(gpa,a, b, 100);

				} while (a != '!');
				c=exit();
			} while (c!=0);
			fclose(file);
		}
		delete[] gpa;
		gpa = nullptr;
		return true;
	}
}