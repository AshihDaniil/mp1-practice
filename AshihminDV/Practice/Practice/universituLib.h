#pragma once
#include "univer_description.h"

class UnLib
{
private:
	int count;
	Univer* univer;
	void read_univers(const std::string* infilename, const int k);
public:

	UnLib();
	UnLib(int n);
	UnLib(int n, const std::string* infilename);
	UnLib(const UnLib&);
	~UnLib();


	friend std::ostream& operator<<(std::ostream& out, const UnLib& unLib)
	{
		for (int i = 0; i < unLib.count; i++)
		{
			std::string name = unLib.univer[i].get_univer_name();
			out << i+1 << " ÂÓÇ - " << name << std::endl;
		}
		return out;
	}

	friend std::ifstream& operator>>(std::ifstream& in, UnLib& unLib);

	const UnLib& operator= (const UnLib&);

	Univer get_univer(int idx) const{return univer[idx];}

	Univer get_univers() const {return *univer;}

	int get_count() const {return count;}

	void print_univer_info(int idx);

	void university_lib();

	void print_founded();

	UnLib find_napr();

	void min_ball();



};