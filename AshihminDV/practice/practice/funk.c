#include "funk.h"

void university_lib(UniversityLib* unLib, int k)
{
	int n_u = 0, n_u_p = 0;

	//setlocale(LC_ALL, "Rus");

	printf("Введите номер ВУЗа, чтобы узнать о нем больше информации\n\n");
	print_univers(unLib);
	do {
		printf("Введите номер ВУЗа(для выхода в меню введите 0): ");
		scanf("%d", &n_u);
		printf("\n");
		if (n_u > 0 && n_u < k + 1) {
			univer_info(&unLib->university[n_u - 1]);
		}
		else if (n_u != 0) {
			printf("Некорректный ввод\n");
		}
	} while (n_u != 0);
}

void more_about_napr(UniversityLib* unLib, int k)
{
	int n_u = 0, n_u_p = 0;

	printf("Подробнее о специальностях ВУЗа\n\n");
	do
	{
		print_univers(unLib);
		printf("Введите номер ВУЗа, чтобы узать о его специальностях(для выхода в меню введите 0):");
		scanf("%d", &n_u);
		printf("\n");
		if (n_u > 0 && n_u < k + 1)
		{

			univer_napr(&unLib->university[n_u - 1]);
			do {
				printf("Введите номер специальности(для возврата назад введите 0): ");
				scanf("%d", &n_u_p);
				printf("\n");
				if (n_u_p > 0 && n_u_p < unLib->university[n_u - 1].count_napr + 1)
				{
					univer_napr_info(&unLib->university[n_u - 1], n_u_p - 1);
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
}

UniversityLib find_napravl(UniversityLib* unLib)
{
	char* name[BUFFER];
	UniversityLib founded_univ;
	int i = 0;
	int j = 0;
	gets(name);
	do {
		printf("Поиск направления по названию(Введите название направления, для выхода в меню введите return)\n");
		gets(name);
		printf("\n");
		if (strcmp(name, "return") != 0) {
			founded_univ = find_napr(unLib, &founded_univ, name);
			if (founded_univ.university == NULL) {
				printf("Совпадений не найдено\n");
			}
			else {
				printf("Найденые направления:\n");
				for (i = 0; i < founded_univ.count; i++)
				{
					printf("ВУЗ: %s", founded_univ.university[i].univer_name);
					for (j = 0; j < founded_univ.university[i].count_napr; j++) {
						univer_napr_info(&founded_univ.university[i], j);
					}
					printf("\n");
				}
			}
		}
	} while (strcmp(name, "return") != 0);
	return founded_univ;
}
void min_vyz(UniversityLib* unLib, int k)
{
	int n_u = 0;
	printf("Поиск минимального конкурса по ВУЗу\n\n");
	do {
		print_univers(unLib);
		printf("Введите номер ВУЗа(для вызода в менб введите 0): ");
		scanf("%d", &n_u);
		printf("\n");
		if (n_u > 0 && n_u < k + 1) {
			min_conc_po_vyzy(&unLib->university[n_u - 1]);
		}
		else if (n_u != 0) {
			printf("Некорректный ввод\n");
		}
		printf("\n");
	} while (n_u != 0);
}