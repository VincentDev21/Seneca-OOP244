#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete
    void EmptyRecord(Customers& data) {
        data.retweets_count = 0;
        data.likes_count = 0;
        data.replies_count = 0;
        data.share_videos = 0;
        data.user_name[0] = '\0';

    }
    void EmptyRecord(CustomersRecord &data) {
        data.noOfRecords = 0;
        data.ptr_rec=NULL;
    }
    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }
    bool read(Customers &rec) {
        cout << " Enter User name: ";
        read(rec.user_name, 100);

        if (rec.user_name[0] == '\0') {
            return false;
        }
        else {
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
        }
        return true;
    }
    void addCustomer(CustomersRecord & t_rec, const Customers & c_rec) {
        if (t_rec.noOfRecords == 0) {
            t_rec.ptr_rec = new Customers[100];
        }
        t_rec.ptr_rec[t_rec.noOfRecords] = c_rec;
        t_rec.noOfRecords++;
        
    }
    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", "
            << c_rec.likes_count << ", "
            << c_rec.retweets_count << ", "
            << c_rec.replies_count << ", "
            << c_rec.share_videos << endl << endl;
    }
    void display(const CustomersRecord& t_rec) {
        int i = 0;
        for (i = 0; i < t_rec.noOfRecords; i++) {
            cout << i+1 << ". ";
            display(t_rec.ptr_rec[i]);
        }
    }
    // complete


}
