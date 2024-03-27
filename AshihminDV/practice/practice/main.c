#include "univer_description.h"	
#include "funk.h"

int main(int argc, char** argv)
{
	char* infilename[2];
	Univer u[2];
	int i = 0, k = argc - 1, button = 1 , n_u=0, n=0;

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
	}

	
	do{
		printf("Выберите ... :\n");
		listOfChoose();
		scanf("%d", &button);
		switch(button)
		{
			case 1:
				for (i = 0; i < k; i++) {
					list_of_univer(&u[i], i);
				}
				do{
					printf("Информация о ВУЗе (Введите номер ВУЗа или 0 для выхода)\n");
					scanf("%d", &n_u);
					if(n_u>0 && n_u<k+1){
						univer_info(&u[n_u-1]);
					}
				} while (n_u != 0);
			case 2:
				printf("Выберите ВУЗ, чтобы увидеть все специальности данного ВУЗа\n");
				for (i = 0; i < k; i++) {
					list_of_univer(&u[i], i);
				}
				do {
					scanf("%d", &n_u);
					univer_napr(&u[n_u-1]);
				} while (n_u != 0);
			/*case 3:
			case 4:*/
		}
	} while (button != 0);
	
}

