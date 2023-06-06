#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "File.h"
#include <string.h>

namespace sdds{
    int import(FILE* GPA, struct GPA gpa[]) {
        int i = 0;
        int stop = 1;
        
        do {
            fscanf(GPA, " %[^,] ,%d,%lf", gpa[i].name, &gpa[i].stno, &gpa[i].gpa);
            i++;
            if (i == 100) {
                stop = 0;
            }
        } while (feof(GPA) == 0 && stop != 0);
        return i;
        
    }
}
