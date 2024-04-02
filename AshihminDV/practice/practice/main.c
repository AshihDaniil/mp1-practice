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
		printf("�������� ... :\n");
		printf("1 - ������ ����� � �� ��������\n");
		printf("2 - ���������� � �������������� ����\n");
		printf("3 - ����� ������������ �������� �� �������������\n");
		printf("4 - ����� ������������ �������� �� ����\n");
		printf("5 - ����� ������������ �������� �� �����\n");
		scanf("%d", &button);
		switch (button)
		{
		case 1:
			for (i = 0; i < k; i++) {
				print_univ(&u[i], i);
			}
			do {
				printf("�������� ���(��� ������ � ���� ������� 0): ");
				scanf("%d", &n_u);
				if (n_u > 0 && n_u < k + 1) {
					univer_info(&u[n_u - 1]);
				}
			} while (n_u != 0);
			break;
		case 2:
			printf("������ � �������������� ����\n");
			do {
				for (i = 0; i < k; i++) {
					print_univ(&u[i], i);
				}
				printf("������� ����� ����(��� ������ � ���� ������� 0): ");
				scanf("%d", &n_u);
				
				if (n_u > 0 && n_u < k + 1)
				{
					univer_napr(&u[n_u - 1]);
					do {
						printf("��� ��������� ������������ �� ����������� ������� �����(��� ������ ���� 0): ");
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
			printf("����������� ������� �� ����\n");
			do {
				for (i = 0; i < k; i++) {
					print_univ(&u[i], i);
				}
				printf("������� ����� ����(��� ������ � ���� ������� 0): ");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1) {
					min_conc_po_vyzy(&u[n_u - 1]);
				}
			} while (n_u != 0);

		case 5:
			printf("����������� ������� �� �����");
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