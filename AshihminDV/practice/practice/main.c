#include "univer_description.h"	
#include "funk.h"

int main(int argc, char** argv)
{
	char* infilename[2];
	Univer u[2];
	int i = 0, k = argc - 1;

	setlocale(LC_ALL, "Rus");

	if (argc < 3)
	{
		printf("Incorrect argument\n");
		return 999;
	}

	for (i = 0; i < k; i++) {
		infilename[i] = argv[i+1];
	}

	for (i = 0; i < k; i++)
	{
		read(infilename[i], &u[i]);
		print_univ(&u[i]);
	}

	/*
	do{
		printf("Выберите ... :);
		listOfChoose();
		scanf("%d", &button);
		swich(button)
		{
			case 1:
			case 2:
			case 3:
			case 4:
		}
	}while( button!=0 )
	*/
}

