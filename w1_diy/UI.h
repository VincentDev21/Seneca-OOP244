#ifndef SDDS_UI_H 
#define SDDS_UI_H
#include "File.h"
namespace sdds {
	bool valid(char a);
	void error();
	void userinput(char* character, double* gpa);
	bool exit();
	void output(const struct GPA* gpa, char a, double b,int max);
	void  Sort(struct GPA* data, int size);
}
#endif