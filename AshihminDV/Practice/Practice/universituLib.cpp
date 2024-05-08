#include "universituLib.h"

UnLib::UnLib()
{
	this->count = 0;
	this->univer = nullptr;
}

UnLib::UnLib(int n)
{
	this->count = n;
	if(n>0)
	{
		this->univer = new Univer[this->count];
	}
	else 
	{
		this->univer = nullptr;
	}
	
}	

UnLib::UnLib(int n, const std::string* infilename)
{
	this->count = n;

	if (n > 0)
	{
		this->univer = new Univer[this->count];
	}
	else
	{
		this->univer = nullptr;
	}

	for (int i = 0; i < n; i++)
	{
		std::ifstream in;
		std::cout << infilename[i] << std::endl;
		in.open(infilename[i]);
		in >> this->univer[i];
		in.close();
	}
}

UnLib::~UnLib()
{
	std::cout << "UnLib::~UnLib()" << std::endl;
	if (univer != nullptr)
	{
		delete[] this->univer;
	}

}

std::ifstream& operator>>(std::ifstream& in, UnLib& unLib)
{
	if (unLib.count != 0)
	{
		for (int i = 0; i < unLib.count; i++)
		{
			in >> unLib.univer[i];
		}
	}
	return in;
}

const UnLib& UnLib::operator= (const UnLib& unLib)
{
	count = unLib.count;
	if (count != 0 && unLib.univer!=nullptr)
	{
		this->univer = new Univer[count];
		for (int i = 0; i < count; i++)
		{
			univer[i] = unLib.univer[i];
		}
	}
	else
	{
		this->univer = nullptr;
	}
	return *this;
}

void UnLib::read_univers(const std::string* infilename, const int k)
{
	for (int i = 0; i < k; i++)
	{
		std::ifstream in;

		std::cout << infilename[i] << std::endl;

		in.open(infilename[i]);
		in >> this->univer[i];
		in.close();
	}
}

void UnLib::print_univer_info(int idx)
{
	std::cout << this->univer[idx];
	
	//ÂÎÏÐÎÑ!
	//Adres adr = this->univer[idx].get_adr(this->univer[idx]);
	//std::cout << adr;
	//std::cout << "-------------" <<this->univer[idx].get_adr(this->univer[idx]);

}

void UnLib::university_lib()
{
	std::string button1;
	do
	{
		std::cout << *this;
		std::cout << "Âûáåðèòå ÂÓÇ: ";
		std::cin >> button1;
		if (button1 > "0" && button1 <= std::to_string(this->get_count()) && 
			stoi(button1)>0 && stoi(button1)<=this->get_count())
		{
			std::cout << this->get_univer(stoi(button1) - 1);
		}
		else if (button1 != "0")
		{
			std::cout << "Íåêîððåêòíûé ââîä" << std::endl << std::endl;
		}
	} while (button1 != "0");
}

void UnLib::print_founded()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "ÂÓÇ - " << this->univer[i].get_univer_name() << std::endl;
		for (int j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			std::cout << this->univer[i].get_napr(j);
		}
	}
}

UnLib UnLib::find_napr()
{
	std::string name;

	getline(std::cin, name);

	int i = 0, j = 0, count_univ=0;
	for (i = 0; i < this->count; i++)
	{
		for (j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			if (name == this->univer[i].get_napr(j).get_napr_name())
			{
				count_univ++;
				break;
			}
		}
	}

	UnLib founded_univ(count_univ);

	int count_sovp = 0;

	for (i = 0; i < this->count; i++)
	{
		for (j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			if (name == this->univer[i].get_napr(j).get_napr_name())
			{
				count_sovp++;
			}
		}
		if (count_sovp != 0)
		{
			founded_univ.univer[i].make_naprs(count_sovp);
			count_sovp = 0;
		}
	}

	//work

	count_sovp = 0;
	int idx_univ = 0;

	

	for (i = 0; i < this->count; i++)
	{
		for(j = 0; j<this->univer[i].get_count_napr(); j++)
		{
			
			if (name == this->univer[i].get_napr(j).get_napr_name())
			{

				founded_univ.univer[idx_univ].set_naprs(count_sovp,
					this->univer[i].get_napr(j));

				count_sovp++;
			}
		}
		if (count_sovp != 0)
		{
			count_sovp = 0;

			founded_univ.univer[idx_univ].set_name_univ(this->univer[i].get_univer_name());

			idx_univ++;
		}
	}

	//founded_univ.print_founded();

	if (founded_univ.univer == nullptr)
	{
		if (name == "return")
		{
			founded_univ.count = -1;
		}
		else
		{
			founded_univ.count = 0;
		}
	}	

	return founded_univ;

}