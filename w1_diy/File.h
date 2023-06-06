#ifndef SDDS_FILE_H // replace NAMESPACE and HEADERFILENAME with relevant names
#define SDDS_FILE_H
#include "GPA.h"
namespace sdds {
	int import(FILE* filename, struct GPA gpa[]);
}

#endif