// Final Project Milestone 2
// Student Date Validation
// Version 1.0
// Date	2023-02-27
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Date class
// for submission.
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Date.h"
#include "POS.h"
using namespace std;
using namespace sdds;

int main() {
    int ret = 0;
    bool ok = true;
    ifstream fin;

    /*if (ok) {
        ofstream fout("date.txt");
        Date A;
        Date B;
        A.dateOnly(false);
        B.dateOnly(false);
        cout << "Testing operator<< and >> overload for iostream, " << endl;
        cout << "Please enter the following data and time:  2023/2/27, 1:35\n> ";
        cin >> A;
        cout << "Read From file:  " << A << endl;
        fout << A;
        fout.close();
        fin.open("date.txt");
        fin >> B;
        if (A != B) {
            cout << "Most likely you did not use istream and/or ostream refrences in your\n"
                "operator<< and operator>> overloads and used cin and cout instead" << endl;
            ok = false;
        }
        else {
            cout << "Passed" << endl;
        }
        cin.ignore(2000, '\n');
        fin.close();
    }*/
    if (ok) {
        cout << "Opening \"dataEntries.txt\" file for data entry..." << endl;
        fin.open("dateEntries.txt");
        if (!fin) {
            cout << "Failed to open the file!" << endl;
            ok = false;
        }
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Year validation, " << endl;
        cout << "Data in file:  10/1/1\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the year entry limits after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Month validation, " << endl;
        cout << "Data in file:  2000/13/1\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the month entry limits after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Day validation, " << endl;
        cout << "Data in file:  2000/1/50\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the day entry limits after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(true);
        cout << "Day validation, leap year:" << endl;
        cout << "Data in file:  2020/2/29\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Possibly your read function does not check the day entry limits using mday()" << endl;
            ok = false;
        }
        else {
            cout << "passed!" << endl;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(false);
        cout << "Hour validation, " << endl;
        cout << "Data in file:  2000/1/1, 25:10\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the hour entry limit after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        Date A;
        A.dateOnly(false);
        cout << "Minute validation, " << endl;
        cout << "Data in file:  2000/1/1, 23:60\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Correctly detected " << A.error() << endl;
        }
        else {
            cout << "Your read function does not check the minute entry limit after entry" << endl;
            ok = false;
        }
        fin.ignore(2000, '\n');
    }

    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid year entry" << endl;
        cout << "Data In file: abcd\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }

    if (ok) {
        Date A;
        A.dateOnly(false);
        cout << "Invalid month entry" << endl;
        cout << "Data In file: 2023abcd\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid day entry" << endl;
        cout << "Data In file: 2023/10abcd\n> ";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {  //fail
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid hour entry" << endl;
        cout << "Data In file: 2020/10/11abcd\n";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Invalid minute entry" << endl;
        cout << "Data In file: 2020/10/11, 8abcd\n";
        fin >> A;
        cout << "Read From file:  " << A << endl;
        if (!A) {
            cout << "Passed!" << endl;
        }
        else {
            cout << "Your read function does not check istream::fail() after each entry" << endl;
            ok = false;
        }
        fin.clear();
        fin.ignore(2000, '\n');
    }
    if (ok) { //fail
        cout << "Testing istream read failure detection..." << endl;
        Date A;
        A.dateOnly(false);
        cout << "Correct entry" << endl;
        cout << "Data In file: 2023/03/01, 20:43\n> ";
        fin >> A;
        if (!A) {
            cout << "incorrectly detected " << A.error() << endl;
            ok = false;
        }
        else {
            cout << "Passed! Read From file:  " << A << endl;
        }
        fin.ignore(2000, '\n');
    }
    if (ok) {
        cout << "You passed all error handling tests." << endl << endl
            << " If your output matches the required output, you can submit your" << endl
            << " Milestone 2" << endl;
    }
    else {
        cout << "You did not pass all the tests, keep working on your project!" << endl;
        ret = 1;
    }
    return ret;
}