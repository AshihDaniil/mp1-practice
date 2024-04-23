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

	friend std::ostream& operator<<(std::ostream& out, const UnLib& unLib)
	{
		for (int i = 0; i < unLib.count; i++)
		{
			out << i+1 << " ÂÓÇ - " << unLib.univer[i].get_univer_name(unLib.univer[i]) << std::endl;
		}
		return out;
	}

	void read_univers(const std::string& infilename, const int idx);

	Univer get_univer(const UnLib& unLib, int idx)
	{
		return unLib.univer[idx];
	}

	void print_univer_info(int idx);

};