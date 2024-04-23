#include "napr.h"


std::ifstream & operator>>(std::ifstream & in, Napr & napr)
{
	getline(in, napr.napr_name);
	in >> napr.nforms;
	napr.education_forms = new EdFormInfo[napr.nforms];

	std::cout << napr;

	std::string trash;
	

	for(int i=0; i<napr.nforms;i++)
	{
		getline(in, trash);
		getline(in, trash);
		napr.education_forms[i].set_form_id(trash);
		
		in >> napr.education_forms[i];
		std::cout << napr.education_forms[i];
	}
	getline(in, trash);

	return in;
}