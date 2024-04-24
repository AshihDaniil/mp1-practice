#pragma once

#include <string>
#include <iostream>
#include <fstream>

class Adres
{
private:
	std::string town;
	std::string street;
	int house;
	int postcode;
public:
	friend std::ifstream& operator>>(std::ifstream& in, Adres& adr);
	friend std::ostream& operator<<(std::ostream& out, const Adres& adr)
	{
		out << "Адрес: г. " << adr.town << " " << adr.street << " д." << 
			adr.house << " почтовый индекс: " << adr.postcode << std::endl;
		return out;
	}
};