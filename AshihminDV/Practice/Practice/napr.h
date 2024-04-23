#pragma once
#include "EdFormInfo.h"


class Napr
{
private:
	std::string napr_name;
	int nforms;
	EdFormInfo* education_forms;

public:
	friend std::ifstream& operator>>(std::ifstream& in, Napr& napr);
	friend std::ostream& operator<<(std::ostream& out, const Napr& napr)
	{
		out << napr.napr_name << std::endl;
		out << napr.nforms << std::endl;

		//out << napr.education_forms << std::endl;
		return out;
	}


};