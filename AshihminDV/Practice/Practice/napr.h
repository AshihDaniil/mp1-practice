#pragma once
#include "EdFormInfo.h"


class Napr
{
private:
	std::string napr_name;
	int nforms;
	EdFormInfo* education_forms;

public:

	Napr();
	Napr(int n);
	//~Napr();

	friend std::ifstream& operator>>(std::ifstream& in, Napr& napr);
	friend std::ostream& operator<<(std::ostream& out, const Napr& napr)
	{
		out << "Название - " << napr.napr_name << std::endl;
		out << "Количество форм обучения - " << napr.nforms << std::endl;
		for (int i = 0; i < napr.nforms; i++)
		{
			out << napr.education_forms[i] << std::endl;
			
		}
		out << std::endl;

		return out;
	}
	const Napr& operator= (const Napr& n);



	std::string get_napr_name()
	{
		return napr_name;
	}
};