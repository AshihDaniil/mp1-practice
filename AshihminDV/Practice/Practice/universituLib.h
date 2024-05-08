#pragma once
#include "univer_description.h"

class UnLib
{
private:
	int count;
	Univer* univer;

public:

	UnLib();
	UnLib(int n);
	UnLib(int n, const std::string* infilename);
	//~UnLib();


	friend std::ostream& operator<<(std::ostream& out, const UnLib& unLib)
	{
		for (int i = 0; i < unLib.count; i++)
		{
			out << i+1 << " ��� - " << unLib.univer[i].get_univer_name() << 
				std::endl;
		}
		return out;
	}

	friend std::ifstream& operator>>(std::ifstream& in, UnLib& unLib);

	const UnLib& operator= (const UnLib&);

	void read_univers(const std::string* infilename, const int k);

	Univer get_univer(int idx)
	{
		return univer[idx];
	}

	Univer get_univers()
	{
		return *univer;
	}

	int get_count()
	{
		return count;
	}

	void print_univer_info(int idx);

	void university_lib();

	void print_founded();

	UnLib find_napr();

};