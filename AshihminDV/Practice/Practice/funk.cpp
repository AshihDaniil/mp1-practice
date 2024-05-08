#include "funk.h"

void choose_univ(UnLib& unLib)
{
	std::string button1;
	do
	{
		
	} while (button1 != "0");
}

void main_menu(UnLib& unLib)
{
	std::string button = "1";
	do
	{
		std::cout << "1 - Список университетов и их описание" << std::endl;
		std::cout << "2 - Направления университетов" << std::endl;
		std::cout << "3 - Найти направление" << std::endl;
		std::cout << "4 - Минимальный балл университета" << std::endl;
		std::cout << "5 - Минимальный балл по всем университетам" << std::endl;
		std::cout << "0 - Выход" << std::endl;
		std::cout << "Выберите номер: ";
		std::cin >> button;
		std::cout << std::endl;

		const int length = button.length();
		char* button_char = new char[length + 1]; 
		strcpy_s(button_char, strlen(button_char), button.c_str());

		std::string button1;
		std::string button2;

		UnLib founded_univ;

		switch (*button_char)
		{
		case '1':
			unLib.university_lib();
			break;
		case '2':
			do
			{
				std::cout << unLib;
				std::cout << "Выберите номер: ";
				std::cin >> button1;
				if (button1 > "0" && button1 <= std::to_string(unLib.get_count()))
				{
					unLib.get_univer(stoi(button1)-1).list_napr();

				}
				else if (button1 != "0")
				{
					std::cout << "Некорректный ввод" << std::endl << std::endl;
				}
			} while (button1 != "0");
			break;
		case '3':
			founded_univ = unLib.find_napr();
			std::cout << founded_univ;
			break;
		case '4':
			break;
		case '5':
			break;
		case '0':
			break;
		default:
			std::cout << "Некорректный ввод" << std::endl;
			break;
		}
	} while (button != "0");
}