#include "univer_description.h"	

int main(int argc, char** argv)
{
	char* infilename[2];
	Univer u[2];
	int i = 0, k = argc - 1, button = 1, n_u = 0, n_u_p = 0;
	setlocale(LC_ALL, "Rus");

	if (argc < 3)
	{
		printf("Incorrect argument\n");
		return 999;
	}

	for (i = 0; i < k; i++) {
		infilename[i] = argv[i + 1];
	}

	for (i = 0; i < k; i++)
	{
		fill_univ(infilename[i], &u[i]);
	}

	do {
		printf("Выберите ... :\n");
		printf("1 - Список ВУЗов и их описание\n");
		printf("2 - Информация о специальностях ВУЗа\n");
		printf("3 - Поиск минимального конкурса по специальности\n");
		printf("4 - Поиск минимального конкурса по ВУЗу\n");
		printf("5 - Поиск минимального конкурса по ВУЗам\n");
		scanf("%d", &button);
		switch (button)
		{
		case 1:
			for (i = 0; i < k; i++) {
				print_univ(&u[i], i);
			}
			do {
				printf("Выберите ВУЗ(для выхода в меню введите 0): ");
				scanf("%d", &n_u);
				if (n_u > 0 && n_u < k + 1) {
					univer_info(&u[n_u - 1]);
				}
			} while (n_u != 0);
			break;
		case 2:
			printf("Узнать о специальностях ВУЗА\n");
			do {
				for (i = 0; i < k; i++) {
					print_univ(&u[i], i);
				}
				printf("Введите номер ВУЗа(для выхода в меню введите 0): ");
				scanf("%d", &n_u);
				
				if (n_u > 0 && n_u < k + 1)
				{
					univer_napr(&u[n_u - 1]);
					do {
						printf("Для получения подробностей по направлению введите номер(для выбора ВУЗа 0): ");
						scanf("%d", &n_u_p);
						if (n_u_p > 0 && n_u_p < u[n_u - 1].count_napr+1)
						{
							univer_napr_info(&u[n_u - 1], n_u_p - 1);
						}
					} while (n_u_p != 0);
				}
			} while (n_u != 0);
			break;
		//case 3:
		case 4:
			printf("Минимальный конкурс по ВУЗу\n");
			do {
				for (i = 0; i < k; i++) {
					print_univ(&u[i], i);
				}
				printf("Введите номер ВУЗа(для выхода в меню введите 0): ");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1) {
					min_conc_po_vyzy(&u[n_u - 1]);
				}
			} while (n_u != 0);

		case 5:
			printf("Минимальный конкурс по ВУЗам");
			//min_conc_po_vyzam(&u);
		}
	}while (button != 0);

	for (i = 0; i < k; i++) {
		free(u[i].univer_name);
		free(u[i].univer_info);
		free(u[i].univer_adres);
		free(u[i].napr);
	}
	return 0;

}