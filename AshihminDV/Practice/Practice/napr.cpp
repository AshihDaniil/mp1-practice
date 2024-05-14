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

/*Napr::~Napr()
{
	std::cout << "Napr::~Napr()" << std::endl;
	if (education_forms != nullptr)
	{
		delete [] this->education_forms;
	}
}*/

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