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
		out << "�����: �. " << adr.town << " " << adr.street << " �." << 
			adr.house << " �������� ������: " << adr.postcode << std::endl;
		return out;
	}
};