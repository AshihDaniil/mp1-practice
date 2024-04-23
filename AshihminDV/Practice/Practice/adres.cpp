#include "adres.h"

std::ifstream& operator>>(std::ifstream& in, Adres& adr)
{

	getline(in, adr.town);
	getline(in, adr.street);
	in >> adr.house;
	in >> adr.postcode;
	return in;
}