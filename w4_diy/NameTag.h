#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_
namespace sdds {
	class NameTag {
		char* t_name;
		int t_ext;
	public:
		NameTag();
		NameTag(const char* name);
		NameTag(const char* name, int ext);
		~NameTag();
		void setEmpty();
		void fill(int length);
		void header_and_foot(int length);
		void setName(const char* name);
		void setExt(int ext);
		void print();
		void Extension(int length);
		bool Valid_Selection(char input);
		bool valid(int input);
		NameTag& read();
	};
}
#endif

