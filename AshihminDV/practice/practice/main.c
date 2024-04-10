#include "universityLib.h"	


int main(int argc, char** argv)
{
	char* infilename[4], *name[BUFFER];
	UniversityLib unLib;

	int i = 0, /*k = argc - 1,*/ button = 1, n_u = 0, n_u_p = 0, j;
	int k = 1;

	setlocale(LC_ALL, "Rus");

	if (argc < 5)
	{
		printf("Incorrect argument\n");
		return 999;
	}

	allocate(&unLib, k);

	for (i = 0; i < k; i++) {
		infilename[i] = argv[i + 1];
	}

	fill_univers(&unLib, infilename);

	do {
		printf("1 - Список ВУЗов и их описание\n");
		printf("2 - Информация о специальностях ВУЗа\n");
		printf("3 - Поиск минимального конкурса по специальности\n");
		printf("4 - Поиск минимального конкурса по ВУЗу\n");
		printf("5 - Поиск минимального конкурса по ВУЗам\n");
		printf("0 - Выход из программы\n");
		printf("Выберите ... : ");
		scanf("%d", &button);
		switch (button)
		{
		case 1:
			printf("Введите номер ВУЗа, чтобы узнать о нем больше информации\n\n");
			print_univers(&unLib);
			do {
				printf("Введите номер ВУЗа(для выхода в меню введите 0): ");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1) {
					univer_info(&unLib.university[n_u-1]);
				}
				else if (n_u != 0) {
					printf("Некорректный ввод\n");
				}
			} while (n_u != 0);
			break;
		case 2:
			printf("Подробнее о специальностях ВУЗа\n\n");
			do 
			{
				print_univers(&unLib);
				printf("Введите номер ВУЗа, чтобы узать о его специальностях(для выхода в меню введите 0):");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1)
				{
					
					univer_napr(&unLib.university[n_u - 1]);
					do {
						printf("Введите номер специальности(для возврата назад введите 0): ");
						scanf("%d", &n_u_p);
						printf("\n");
						if (n_u_p > 0 && n_u_p < unLib.university[n_u-1].count_napr + 1)
						{
							univer_napr_info(&unLib.university[n_u - 1], n_u_p - 1);
						}
						else if (n_u_p != 0) {
							printf("Некорректный ввод\n");
						}
					} while (n_u_p != 0);
				}
				else if (n_u != 0) {
					printf("Некорректный ввод\n");
				}
			} while (n_u != 0);
			break;
		case 3:
			gets(name);
			do {
				printf("Поиск направления по названию(Введите название направления, для выхода в меню введите return)\n");
				gets(name);
				printf("\n");
				if(strcmp(name, "return") != 0){
					find_napr(&unLib, name);
				}
			} while (strcmp(name, "return") != 0);
			break;
		case 4:
			printf("Поиск минимального конкурса по ВУЗу\n\n");
			do {
				print_univers(&unLib);
				printf("Введите номер ВУЗа(для вызода в менб введите 0): ");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1) {
					min_conc_po_vyzy(&unLib.university[n_u - 1]);
				}
				else if (n_u != 0) {
					printf("Некорректный ввод\n");
				}
				printf("\n");
			} while (n_u != 0);
			break;
		case 5:
			printf("Минимальный балл по ВУЗам: \n\n");
			min_conc_po_vyzam(&unLib);
			break;
		case 0:
			break;
		default:
			printf("Некорректный ввод(\n");
			break;
		}
	}while (button != 0);

	if (unLib.university != NULL)
	{
		for (i = 0; i < k; i++)
		{
			free(unLib.university[i].univer_name);
			free(unLib.university[i].univer_info);
			free(unLib.university[i].univer_name);
			free(unLib.university[i].address.town);
			free(unLib.university[i].address.street);
			for (j = 0; j < unLib.university[i].count_napr; j++)
			{
				free(unLib.university[i].napr[j].name);
			}
			free(unLib.university[i].napr);
			free(unLib.university);
		}
	}
	return 0;

}