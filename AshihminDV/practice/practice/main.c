#include "universityLib.h"	


int main(int argc, char** argv)
{
	char* infilename[1], *name[BUFFER];
	UniversityLib unLib;
	UniversityLib founded_univ;

	int i = 0, k = argc - 1, button = 1, n_u = 0, n_u_p = 0, j;

	setlocale(LC_ALL, "Rus");

	if (argc < 2)
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
		printf("1 - ������ ����� � �� ��������\n");
		printf("2 - ���������� � �������������� ����\n");
		printf("3 - ����� ������������ �������� �� �������������\n");
		printf("4 - ����� ������������ �������� �� ����\n");
		printf("5 - ����� ������������ �������� �� �����\n");
		printf("0 - ����� �� ���������\n");
		printf("�������� ... : ");
		scanf("%d", &button);
		switch (button)
		{
		case 1: //work
			printf("������� ����� ����, ����� ������ � ��� ������ ����������\n\n");
			print_univers(&unLib);
			do {
				printf("������� ����� ����(��� ������ � ���� ������� 0): ");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1) {
					univer_info(&unLib.university[n_u-1]);
				}
				else if (n_u != 0) {
					printf("������������ ����\n");
				}
			} while (n_u != 0);
			break;
		case 2: //work
			printf("��������� � �������������� ����\n\n");
			do 
			{
				print_univers(&unLib);
				printf("������� ����� ����, ����� ����� � ��� ��������������(��� ������ � ���� ������� 0):");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1)
				{
					
					univer_napr(&unLib.university[n_u - 1]);
					do {
						printf("������� ����� �������������(��� �������� ����� ������� 0): ");
						scanf("%d", &n_u_p);
						printf("\n");
						if (n_u_p > 0 && n_u_p < unLib.university[n_u-1].count_napr + 1)
						{
							univer_napr_info(&unLib.university[n_u - 1], n_u_p - 1);
						}
						else if (n_u_p != 0) {
							printf("������������ ����\n");
						}
					} while (n_u_p != 0);
				}
				else if (n_u != 0) {
					printf("������������ ����\n");
				}
			} while (n_u != 0);
			break;
		case 3: //work but need to up
			gets(name);
			do {
				printf("����� ����������� �� ��������(������� �������� �����������, ��� ������ � ���� ������� return)\n");
				gets(name);
				printf("\n");
				if(strcmp(name, "return") != 0){
					//find_napr(&unLib, &founded_univ, name);
					founded_univ = find_napr(&unLib, &founded_univ, name);
					if (founded_univ.university == NULL) {
						printf("���������� �� �������\n");
					}
					else {
						printf("�������� �����������:\n");
						for (i = 0; i < founded_univ.count; i++)
						{
							printf("���: %s", founded_univ.university[i].univer_name);
							for (j = 0; j < founded_univ.university[i].count_napr; j++) {
								univer_napr_info(&founded_univ.university[i], j);
							}
							printf("\n");
						}
					}
				}
			} while (strcmp(name, "return") != 0);
			break;
		case 4:
			printf("����� ������������ �������� �� ����\n\n");
			do {
				print_univers(&unLib);
				printf("������� ����� ����(��� ������ � ���� ������� 0): ");
				scanf("%d", &n_u);
				printf("\n");
				if (n_u > 0 && n_u < k + 1) {
					min_conc_po_vyzy(&unLib.university[n_u - 1]);
				}
				else if (n_u != 0) {
					printf("������������ ����\n");
				}
				printf("\n");
			} while (n_u != 0);
			break;
		case 5:
			printf("����������� ���� �� �����: \n\n");
			min_conc_po_vyzam(&unLib);
			break;
		case 0:
			break;
		default:
			printf("������������ ����(\n");
			break;
		}
	}while (button != 0);

	free_univ(&unLib);
	free_univ(&founded_univ);
	return 0;

}