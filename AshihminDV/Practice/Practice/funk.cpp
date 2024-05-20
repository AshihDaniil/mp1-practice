#include "funk.h"

void p_univ_napr(const UnLib& unLib)
{
	std::string button1;
	std::cout << "2 - Направления университетов" << std::endl;
	do
	{
		std::cout << unLib;
		std::cout << "Выберите номер университета(для выхода введите 0): ";
		std::cin >> button1;
		std::cout << std::endl;
		if (button1 > "0" && button1 <= std::to_string(unLib.get_count()) &&
			stoi(button1) > 0 && stoi(button1) <= unLib.get_count())
		{
			unLib.get_univer(stoi(button1) - 1).list_napr();

		}
		else if (button1 != "0")
		{
			std::cout << "Некорректный ввод" << std::endl << std::endl;
		}
	} while (button1 != "0");
}

UnLib p_find_napr(UnLib& unLib)
{
	std::cin.ignore(1);
	UnLib founded_univ, worked_univ;
	do
	{

		worked_univ = unLib.find_napr();
		if (worked_univ.get_count() == 0)
		{
			std::cout << "НЕКОРРЕКТНЫЙ ВВОД" << std::endl;
		}
		else if (worked_univ.get_count() > 0)
		{
			founded_univ = worked_univ;
			founded_univ.print_founded();
		}
		else
		{
			break;
		}

	} while (worked_univ.get_count() != -1);



	return founded_univ;
}

void p_min_po_vyzy(const UnLib& unLib)
{
	std::string button1;
	do {
		std::cout << unLib;
		std::cout << "Введите номер ВУЗа(для выхода введите 0): ";
		std::cin >> button1;
		std::cout << std::endl;
		if (button1 == "0")
		{
			break;
		}
		else if(button1 > "0" && button1 <= std::to_string(unLib.get_count()) &&
			stoi(button1) > 0 && stoi(button1) <= unLib.get_count())
		{
			unLib.get_univer(std::stoi(button1) - 1).min_ball();
			
		}
		else
		{
			std::cout << "Некорректный ввод" << std::endl << std::endl;
		}
	} while (button1 != "0");

}