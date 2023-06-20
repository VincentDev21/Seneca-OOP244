// Final Project Milestone 2
// Student Error module tester
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Error.h"
using namespace std;
using namespace sdds;
int main() {
   Error F;
   Error G("Error G has a message");
   Error X("Error X has a message too");
   Error C = G;
   X = G;
   if(!F) {
      cout << "This is correct >" << F << "<" << endl;
   } else {
      cout << "This message should not get printed: " << F << endl;
   }
   if(G) {
      cout << "This is correct >" << G << "<" << endl;
   } else {
      cout << "This message should not get printed: " << G << endl;
   }
   if(X) {
      cout << "This copy assign is correct >" << X << "<" << endl;
   } else {
      cout << "This message should not get printed: " << X << endl;
   }
   if(C) {
      cout << "This copy is correct >" << C << "<" << endl;
   } else {
      cout << "This message should not get printed: " << C << endl;
   }
   G.clear();
   if(!G) {
      cout << "This is correct >" << G << "<" << endl;
   } else {
      cout << "This message should not get printed: " << G << endl;
   }
   return 0;

}
/* output
This is correct ><
This is correct >Error G has a message<
This copy assign is correct >Error G has a message<
This copy is correct >Error G has a message<
This is correct ><
*/