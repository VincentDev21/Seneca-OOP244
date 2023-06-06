#ifndef SDDS_TOYS_H_
#define SDDS_TOYS_H_
#define MAX_TNAME 31

namespace sdds {
	class Toys {
		char m_tname[MAX_TNAME];// toy name, up to MAX_TNAME size
		int m_sku; //SKU number, maximum 8 digits long
		double m_price;//toy price
		int m_age;//toy according to age group
		bool m_onSale;// keep track, if toys are on sale or not
	public:
		Toys();
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;
		int sku();





	};






}
#endif // !SDDS_DEPARTMENT_H_