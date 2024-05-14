#include "funk.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	const int count = 2;
	std::string infilename[count];

	infilename[0] = "university_Alekseev.txt";
	infilename[1] = "university_Lobachevsky.txt";

	UnLib unLib(count, infilename);

	UnLib founded_univ;
	UnLib worked_univ;

	std::cout << std::endl;


	std::string button = "1";
	std::string button1;
	std::string button2;
	do
	{
		std::cout << "1 - ������ ������������� � �� ��������" << std::endl;
		std::cout << "2 - ����������� �������������" << std::endl;
		std::cout << "3 - ����� �����������" << std::endl;
		std::cout << "4 - ����������� ���� ������������" << std::endl;
		std::cout << "5 - ����������� ���� �� ���� �������������" << std::endl;
		std::cout << "0 - �����" << std::endl;
		std::cout << "�������� �����: ";
		std::cin >> button;
		std::cout << std::endl;

		if (button == "1")
		{
			unLib.university_lib();
		}
		else if (button == "2")
		{
			p_univ_napr(unLib);
		}
		else if (button == "3")
		{
			founded_univ = p_find_napr(unLib);
		}
		else if (button == "4")
		{
			std::cout << unLib;
			std::cin >> button1;
			unLib.get_univer(std::stoi(button1)-1).min_ball();
		}
		else if (button == "5")
		{
			unLib.min_ball();
		}
		else if (button == "0")
		{
			break;
		}
		else
		{
			std::cout << "������������ ����" << std::endl;
		}
	} while (button != "0");

	return 0;
}