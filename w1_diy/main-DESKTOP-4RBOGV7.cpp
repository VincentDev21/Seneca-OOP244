/***********************************************************************
// Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"
using namespace std;
using namespace sdds;


int main() {
	struct GPA gpa[100];
	import("students.csv", gpa);
	int count = 0;
	int i;
	double b = 2.0;
	cout << "[" << count << "] " << gpa[1].stno << ": " << gpa[1].gpa << " (" <<gpa[5].name << ")" << endl;
	/*
	cout << "hey";
	switch ('<') {
	case '>':
		cout << "good1";
		for (i = 0; i < 100; i++) {
			if (gpa[i].gpa>=b) {
				count++;
				cout << "[" << count << "] " << gpa[i].stno << ": " << gpa[i].gpa << " (" << gpa[i].name << ")" << endl;
			}
		}
		break;
	case '<':
		cout << "good2";
		for (i = 0; i < 100; i++) {
			if (gpa[i].gpa<=b&&gpa[i].gpa>=0) {
				count++;
				cout << "[" << count << "] " << gpa[i].stno << ": " << gpa[i].gpa << " (" << gpa[i].name << ")" << endl;
			}
			if (gpa[i].name == NULL) {
				i = 100;
			}
		}
		break;
	case '~':
		cout << "good3";
		for (i = 0; i < 100; i++) {
			if (b == gpa[i].gpa) {
				count++;
				cout << "[" << count << "] " << gpa[i].stno << ": " << gpa[i].gpa << " (" << gpa[i].name << ")" << endl;
			}
		}
		break;

	}
	*/
}

/*
/***********************************************************************
// Workshop 1 p2: tester program
//
// File  main.cpp
// Version 1.0
// Date  winter 2023
// Author Fardad Soleimanloo
//
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************
#include <iostream>
#include "GPAlist.h"
using namespace sdds;
int main() {
	if (gpaQuery("std.csv")) {
		std::cout << "This should have failed!" << std::endl;
	}
	else {
		std::cout << "failed!, this is the correct exectution" << std::endl;
	}
	if (!gpaQuery("students.csv")) {
		std::cout << "This should have worked, fix the problem!" << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}
*/