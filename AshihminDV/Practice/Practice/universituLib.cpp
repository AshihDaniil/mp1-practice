#include "universituLib.h"

UnLib::UnLib()
{
	this->count = 0;
	this->univer = nullptr;
}

UnLib::UnLib(int n)
{
	this->count = n;
	this->univer = new Univer[this->count];
}	

void UnLib::read_univers(const std::string& infilename, const int idx)
{

	std::ifstream in;
	std::cout << infilename << std::endl;
	in.open(infilename);
	in >> this->univer[idx];
	in.close();

}

void UnLib::print_univer_info(int idx)
{
	std::cout << this->univer[idx];
	
	
	//Adres adr = this->univer[idx].get_adr(this->univer[idx]);
	//std::cout << adr;
	//std::cout << this->univer[idx].get_adr(this->univer[idx]);

}