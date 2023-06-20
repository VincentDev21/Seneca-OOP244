#pragma once
namespace sdds {
	const double TAX = 0.13;  //ms2
	const int MAX_SKU_LEN = 7;
	const int MIN_YEAR = 2000;
	const int MAX_YEAR = 2030;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;
	const int MAX_STOCK_NUMBER = 99;
	const int MAX_NO_ITEMS = 2000;


	const int MAX_NAME_LEN = 40; //ms3
	const int POS_LIST = 1;
	const int POS_FORM = 2;

	const char ERROR_POS_SKU[MAX_NAME_LEN] = { "SKU too long" };
	const char ERROR_POS_NAME[MAX_NAME_LEN] = { "Item name too long" };
	const char ERROR_POS_PRICE[MAX_NAME_LEN] = { "Invalid price value" };
	const char ERROR_POS_TAX[MAX_NAME_LEN] = { "Invalid tax status" };
	const char ERROR_POS_QTY[MAX_NAME_LEN] = { "Invalid quantity value" };
	const char ERROR_POS_STOCK[MAX_NAME_LEN] = { "Item out of stock" };
	const char ERROR_POS_EMPTY[MAX_NAME_LEN] = { "Invalid Empty Item" };
}