#ifndef SDDS_STORE_H_
#define SDDS_STORE_H_
#include "Toys.h"
#define MAX_NUM_TOYS 10
#define  MAX_SNAME 31
namespace sdds {

	class Store {
		char m_sName[MAX_SNAME];// Store name, up to MAX_SNAME size
		int m_noOfToys;//No of toys;
		int m_addToys;//no of toys added
		Toys m_toy[MAX_NUM_TOYS];// statically array of toys with size MAX_NUM_TOYS
	public:
		void setStore(const char* sName, int no);
		void setToys(const char* tname, int sku, double price, int age);
		void display()const;
		void find(int sku);
		void setEmpty();
	};






}
#endif // !SDDS_DEPARTMENT_H_