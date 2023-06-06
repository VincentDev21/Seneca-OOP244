// Final Project Milestone 2
// Student constant values tester
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"
#include "POS.h"
using namespace std;
using namespace sdds;

int main() {
   int ret = 0;
   bool ok = true;
   if(ok) {
      cout << "Checking constant values, POS.h: " << endl;
   }
   if(ok && MIN_YEAR != 2000) {
      cout << "MIN_YEAR must be 2000" << endl;
      ok = false;
   }
   if(ok && MAX_YEAR != 2030) {
      cout << "MAX_YEAR must be 2030" << endl;
      ok = false;
   }
   if(ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)) {
      cout << "TAX must be 0.13" << endl;
      ok = false;
   }
   if(ok && MAX_SKU_LEN != 7) {
      cout << "MAX_SKU_LEN must be 7" << endl;
      ok = false;
   }
   if(ok && MAX_NO_ITEMS != 2000) {
      cout << "MAX_NO_ITESM must be 2000" << endl;
      ok = false;
   }

   if(ok) {
      cout << "Passed!" << endl;
   }
   if(ok) {
      cout << "Checking constant values passed, now do the next test!" << endl;
   } else {
      cout << "You did not pass all the tests, keep working on your project!" << endl;
      ret = 1;
   }
   return ret;
}
