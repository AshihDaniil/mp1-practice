#include "funk.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	const int count = 2;
	std::string infilename[count];

	for(int i = 0; i<count; i++)
	{
		infilename[i] = argv[i + 1];
	}

	UnLib unLib(count, infilename);

	std::cout << std::endl;

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

		std::string button1;
		std::string button2;

		/*UnLib founded_univ;
		UnLib worked_univ;*/

		if (button == "1")
		{
			unLib.university_lib();
		}
		/*case '2':
			do
			{
				std::cout << unLib;
				std::cout << "Выберите номер: ";
				std::cin >> button1;
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
			break;
		case '3':
			getline(std::cin, button1);
			do
			{

				worked_univ = unLib.find_napr();
				if (worked_univ.get_count() == 0)
				{
					std::cout << "НЕКОРРЕКТНЫЙ ВВОД" << std::endl;
				}
				else if(worked_univ.get_count()>0)
				{
					founded_univ = worked_univ;
					founded_univ.print_founded();
				}
				else
				{
					break;
				}

			}while(worked_univ.get_count()!=-1);
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
		}*/
	} while (button != "0");

	return 0;
}