#pragma once
/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.h
Version 1.0
Author	Vincent Le
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include "POS.h"
#include"Item.h"
#include "Bill.h"
namespace sdds {
	class PosApp {
		char filename[128];
		Item* Iptr[MAX_NO_ITEMS]={};
		int nptr=0;
		void ActionTitle(const char* title);
	public:
		PosApp(const char* name);
		PosApp(const PosApp& src) = delete;
		PosApp& operator=(const PosApp& src) = delete;
		int menu();
		void run();
		void listItems(bool boolean);
		void addItem();
		void removeItem();
		void stockItem();
		void pointOfSale();
		void loadRecs();
		void saveRecs();
		void sortItems();
		int selectItem();
	};
}
#endif 