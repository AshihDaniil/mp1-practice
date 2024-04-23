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

	UnLib unLib(count);

	for (int i = 0; i < count; i++) {
		unLib.read_univers(infilename[i], i);
	}

	//std::cout << unLib;
	
	

	//std::cout << unLib.get_univer(unLib, 0);
	//std::cout<<unLib.get_univer(unLib, 1);
	
	//unLib.print_univer_info(0);



	return 0;
}