#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

namespace sdds{
    int import(const char* filename, struct GPA gpa[]) {
        int i = 0;
        int stop = 1;
        FILE* GPA = fopen(filename, "r");
        
        do {
            fscanf(GPA, "%[^,] ,%d,%lf", &gpa[i].name, &gpa[i].stno, &gpa[i].gpa);
            if (i == 0) {
                strcpy(gpa[90].name, gpa[0].name);
                int a;
                int b;
                
                a = strlen(gpa[0].name);
                for (b = 0; b < a+1; b++) {
                    printf("%d\n", b);
                    if (b == 0) {
                        gpa[0].name[0] = ' ';
                    }
                    else {
                        printf("%c\n", gpa[90].name[b-1]);
                        gpa[0].name[b] = gpa[90].name[b-1];
                    }
                }
                gpa[90].name == NULL;
                gpa[0].name[a + 1] = '\0';
            }
            if (i != 0) {
                gpa[i].name[0] = ' ';
            }
            

            i++;
            if (i == 100) {
                stop = 0;
            }
        } while (feof(GPA) == 0 && stop != 0);
        return i;

    }
}
