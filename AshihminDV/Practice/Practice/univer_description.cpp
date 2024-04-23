#include "univer_description.h"

std::ifstream& operator>>(std::ifstream& in, Univer& u)
{

	getline(in, u.univer_name);
	in >> u.adres;

	std::string trash;
	getline(in, trash);

	getline(in, u.info);
	in >> u.count_napr;

	std::cout << u;

	getline(in, trash);

	u.napr = new Napr[u.count_napr];

	for (int i = 0; i<u.count_napr;i++){
		in >> u.napr[i];
	}

	return in;
}

//void Univer::print_univer_info()
//{
	
//}