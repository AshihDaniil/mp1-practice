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

	read_univers(infilename, n);
}

UnLib::UnLib(const UnLib& unLib)
{
	this->count = unLib.count;
	if (this->count != 0 && unLib.univer != nullptr)
	{
		this->univer = new Univer[this->count];
		for (int i = 0; i < this->count; i++)
		{
			this->univer[i] = unLib.univer[i];
		}
	}
	else
	{
		this->univer = nullptr;
	}
}

UnLib::~UnLib()
{
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
		in.open(infilename[i]);
		in >> this->univer[i];
		in.close();
	}
}

void UnLib::university_lib()
{
	std::cout << "1 - Список университетов и их описание" << std::endl;
	std::string button1;
	do
	{
		std::cout << *this;
		std::cout << "Выберите номер ВУЗа(для выхода введите 0): ";
		std::cin >> button1;
		std::cout << std::endl;
		if (button1 > "0" && button1 <= std::to_string(this->get_count()) && 
			stoi(button1)>0 && stoi(button1)<=this->get_count())
		{
			std::cout << this->get_univer(stoi(button1) - 1);
		}
		else if (button1 != "0")
		{
			std::cout << "Некорректный ввод" << std::endl << std::endl;
		}
	} while (button1 != "0");
}

void UnLib::print_founded()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << "ВУЗ - " << this->univer[i].get_univer_name() << std::endl;
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
	std::cout << std::endl;

	int count_univ = 0, count_napr=0;

	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			if (name == this->univer[i].get_napr(j).get_napr_name())
			{
				count_univ++;
				break;
			}
		}
	}

	UnLib founded_univ(count_univ);

	count_univ = 0;

	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			if (name == this->univer[i].get_napr(j).get_napr_name())
			{
				count_napr++;
			}
		}
		if (count_napr != 0)
		{
			founded_univ.univer[count_univ].make_naprs(count_napr);
			count_napr = 0;
			count_univ++;
		}
	}

	count_univ = 0;

	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			if (name == this->univer[i].get_napr(j).get_napr_name())
			{
				if (name == this->univer[i].get_napr(j).get_napr_name())
				{

					founded_univ.univer[count_univ].set_naprs(count_napr,
						this->univer[i].get_napr(j));

					count_napr++;
				}
			}
			if (count_napr != 0)
			{
				count_napr = 0;

				founded_univ.univer[count_univ].set_name_univ(this->univer[i].get_univer_name());

				count_univ++;
			}
		}
	}

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

void UnLib::min_ball()
{
	Univer Ochn(1), Zaochn(1), Vech(1);
	Ochn.copy_univ(0, 0, 0, 0, this->univer[0]);
	Zaochn.copy_univ(0, 0, 0, 1, this->univer[0]);
	Vech.copy_univ(0, 0, 0, 2, this->univer[0]);
	for (int i = 0; i < this->count; i++)
	{
		for (int j = 0; j < this->univer[i].get_count_napr(); j++)
		{
			for (int g = 0; g < this->univer[i].get_napr(j).get_nforms(); g++)
			{
				if (this->univer[i].get_napr(j).get_ed_form(g).get_form_id() == 1
					&& this->univer[i].get_napr(j).get_ed_form(g).get_score() <
					Ochn.get_napr(0).get_ed_form(0).get_score())
				{
					Ochn.copy_univ(0, j, 0, g,
						this->univer[i]);
				}
				if (this->univer[i].get_napr(j).get_ed_form(g).get_form_id() == 2
					&& this->univer[i].get_napr(j).get_ed_form(g).get_score() <
					Zaochn.get_napr(0).get_ed_form(0).get_score())
				{
					Zaochn.copy_univ(0, j, 0, g,
						this->univer[i]);
				}
				if (this->univer[i].get_napr(j).get_ed_form(g).get_form_id() == 3
					&& this->univer[i].get_napr(j).get_ed_form(g).get_score() <
					Vech.get_napr(0).get_ed_form(0).get_score())
				{
					Vech.copy_univ(0, j, 0, g,
						this->univer[i]);
				}
			}
		}
	}

	std::cout << "----Минимальный балл очной формы обучения----" << std::endl;
	std::cout << "Название университета - " << Ochn.get_univer_name() << std::endl;
	std::cout << Ochn.get_napr(0);
	
	std::cout << "----Минимальный балл заочной формы обучения----" << std::endl;
	std::cout << "Название университета - " << Zaochn.get_univer_name() << std::endl;
	std::cout << Zaochn.get_napr(0);

	std::cout << "----Минимальный балл вечерней формы обучения----" << std::endl;
	std::cout << "Название университета - " << Vech.get_univer_name() << std::endl;
	std::cout << Vech.get_napr(0);

}