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



/*Univer::~Univer()
{
	std::cout << "Univer::~Univer()" << std::endl;
	if (napr != nullptr)
	{
		delete[] this->napr;
	}
}*/


std::ifstream& operator>>(std::ifstream& in, Univer& u)
{

	getline(in, u.univer_name);
	in >> u.adres;

	std::string trash;
	getline(in, trash);

	getline(in, u.info);
	in >> u.count_napr;

	getline(in, trash);

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