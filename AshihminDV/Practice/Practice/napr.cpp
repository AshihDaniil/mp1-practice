#include "napr.h"

Napr::Napr()
{
	this->nforms = 0;
	this->education_forms = nullptr;
}

Napr::Napr(int n)
{
	this->nforms = n;
	this->education_forms = new EdFormInfo [n];
}

Napr::Napr(const Napr& napr)
{
	this->nforms = napr.nforms;
	this->napr_name = napr.napr_name;
	this->education_forms = new EdFormInfo[this->nforms];
	for (int i = 0; i < this->nforms; i++)
	{
		this->education_forms[i] = napr.education_forms[i];
	}
}

Napr::~Napr()
{
	
	if (education_forms != nullptr)
	{
		delete [] this->education_forms;
	}
}

std::ifstream & operator>>(std::ifstream & in, Napr & napr)
{
	getline(in, napr.napr_name);
	in >> napr.nforms;
	napr.education_forms = new EdFormInfo[napr.nforms];

	//std::cout << napr;

	std::string trash;
	

	for(int i=0; i<napr.nforms;i++)
	{
		getline(in, trash);
		getline(in, trash);
		napr.education_forms[i].set_form_id(trash);
		
		in >> napr.education_forms[i];
		//std::cout << napr.education_forms[i];
	}
	getline(in, trash);

	return in;
}
const Napr& Napr::operator= (const Napr& n)
{
	if (this == &n) {
		return *this;
	}

	if(this->education_forms != nullptr)
	{
		delete[] education_forms;
	}

	napr_name = n.napr_name;
	nforms = n.nforms;
	if (nforms > 0) {
		education_forms = new EdFormInfo[nforms];
		for (int i = 0; i < nforms; i++) {
			education_forms[i] = n.education_forms[i];
		}
	}
	else {
		education_forms = nullptr;
	}

	return *this;
}