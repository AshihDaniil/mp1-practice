#include "funk.h"


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
		case 1:
			university_lib(&unLib, k);
			break;
		case 2: 
			more_about_napr(&unLib, k);
			break;
		case 3:
			find_napravl(&unLib);
			break;
		case 4:
			min_vyz(&unLib, k);
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