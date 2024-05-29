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
	Napr(const Napr&);
	~Napr();

	friend std::ifstream& operator>>(std::ifstream& in, Napr& napr);
	friend std::ostream& operator<<(std::ostream& out, const Napr& napr)
	{
		out << "Название направления - " << napr.napr_name << std::endl;
		out << "Количество форм обучения - " << napr.nforms << std::endl;
		for (int i = 0; i < napr.nforms; i++)
		{
			out << napr.education_forms[i] << std::endl;
			
		}
		out << std::endl;

		return out;
	}
	const Napr& operator= (const Napr& n);

	int get_nforms() const { return nforms; }

	void set_napr_name(const std::string name) { napr_name = name; }

	EdFormInfo get_ed_form(int idx) const { return education_forms[idx]; }

	void copy_napr(int idx_ed_fo, int idx_ed_form_from, const Napr& napr);

	void copy_napr(int idx_ed_fo, int idx_ed_form_from, int nf, const Napr& napr);

	void set_ed_forms(int k)
	{
		education_forms = new EdFormInfo[k];
	}

	std::string get_napr_name()
	{
		return napr_name;
	}
};