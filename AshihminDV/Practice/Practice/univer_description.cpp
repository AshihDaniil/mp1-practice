#include "univer_description.h"

Univer::Univer()
{
	this->count_napr = 0;
	this->napr = nullptr;
}

Univer::Univer(int n)
{
	this->count_napr = n;
	this->napr = new Napr[n];
}

Univer::Univer(const Univer& un)
{
	this->count_napr = un.count_napr;
	this->univer_name = un.univer_name;
	this->adres = un.adres;
	this->info = un.info;
	this->napr = new Napr[this->count_napr];
	for (int i = 0; i < this->count_napr; i++)
	{
		this->napr[i] = un.napr[i];
	}

}

Univer::~Univer()
{
	
	if (napr != nullptr)
	{
		delete[] this->napr;
	}
}


std::ifstream& operator>>(std::ifstream& in, Univer& u)
{

	getline(in, u.univer_name);
	in >> u.adres;

	in.ignore(1);

	getline(in, u.info);
	in >> u.count_napr;

	in.ignore(1);

	u.napr = new Napr[u.count_napr];

	for (int i = 0; i<u.count_napr;i++){
		in >> u.napr[i];
	}

	return in;
}

const Univer& Univer::operator= (const Univer& u)
{
	univer_name = u.univer_name;
	adres = u.adres;
	info = u.info;
	count_napr = u.count_napr;
	napr = new Napr[count_napr];
	for (int i = 0; i < count_napr; i++)
	{
		napr[i] = u.napr[i];
	}
	return *this;
}

void Univer::list_napr()
{
	for (int i = 0; i < this->count_napr; i++)
	{
		std::cout << this->napr[i];
	}
}

void Univer::copy_univ(const int idx_napr_to_copy, const int idx_napr_from_copy,
	const int idx_edform_to_copy, const int idx_edform_from_copy, const Univer& univer)
{
	univer_name = univer.univer_name;
	adres = univer.adres;
	info = univer.info;
	napr->set_ed_forms(1);
	
	this->napr[idx_napr_to_copy].copy_napr(idx_edform_to_copy, idx_edform_from_copy, 1,
		univer.napr[idx_napr_from_copy]);
}

void Univer::min_ball()
{
	Napr ochn(1), zaochn(1), vech(1);
	ochn.copy_napr(0, 0, this->napr[0]);
	zaochn.copy_napr(0, 1, this->napr[0]);
	vech.copy_napr(0, 2, this->napr[0]);

	for (int i = 1; i < this->count_napr; i++)
	{
		for(int j=0; j<this->napr[i].get_nforms(); j++)
		{ 
			if (this->napr[i].get_ed_form(j).get_form_id() == 1 && this->napr[i].get_ed_form(j).get_score() < ochn.get_ed_form(0).get_score())
			{
				ochn.copy_napr(0, j, this->napr[i]);
			}
			if (this->napr[i].get_ed_form(j).get_form_id() == 2 && this->napr[i].get_ed_form(j).get_score() < zaochn.get_ed_form(0).get_score())
			{
				zaochn.copy_napr(0, j, this->napr[i]);
			}
			if (this->napr[i].get_ed_form(j).get_form_id() == 3 && this->napr[i].get_ed_form(j).get_score() < vech.get_ed_form(0).get_score())
			{
				vech.copy_napr(0, j, this->napr[i]);
			}
		}
	}
	std::cout << "----Минимальный балл очной формы обучения----" << std::endl;
	std::cout << ochn;
	std::cout << "----Минимальный балл заочной формы обучения----" << std::endl;
	std::cout << zaochn;
	std::cout << "----Минимальный балл вечерней формы обучения----" << std::endl;
	std::cout << vech;
}