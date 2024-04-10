#include "universityLib.h"

void allocate(UniversityLib* unLib, int count)
{
	unLib->count = count;
	if (count <= 0) {
		unLib->university = NULL;
	}
	unLib->university = (Univer*)malloc(sizeof(Univer) * count);
}

void fill_univers(UniversityLib* unLib, const char** infilename)
{
	int i = 0;
	char* trash[100];
	for (i=0; i < unLib->count; i++)
	{	
		FILE* f = fopen(infilename[i], "r+");
		if (f == NULL) {
			printf("file not found");
			abort();
		}
		fill_univer(f, &unLib->university[i]);
		fclose(f);
	}
}

void print_univers(UniversityLib* unLib)
{
	int i;
	for (i = 0; i < unLib->count; i++) {
		printf("%d ��� - %s", i + 1, unLib->university[i].univer_name);
	}
}

void min_conc_po_vyzam(UniversityLib* unLib)
{
	int min_ochn = 999, min_vech = 999, min_zaochn = 999, i, j;
	char* name_ochn[100], * name_vech[100], * name_zaochn[100];
	char* name_univ_ochn[100], * name_univ_vech[100], * name_univ_zaochn[100];
	for (i = 0; i < unLib->count; i++)
	{
		for (j = 0; j < unLib->university[i].count_napr; j++)
		{
			if (unLib->university[i].napr[j].bally_norm != -1 && unLib->university[i].napr[j].bally_norm < min_ochn)
			{
				min_ochn = unLib->university[i].napr[j].bally_norm;
				*name_ochn = unLib->university[i].napr[j].name;
				*name_univ_ochn = unLib->university[i].univer_name;
			}
			if (unLib->university[i].napr[j].bally_vech != -1 && unLib->university[i].napr[j].bally_vech < min_vech)
			{
				min_vech = unLib->university[i].napr[j].bally_vech;
				*name_vech = unLib->university[i].napr[j].name;
				*name_univ_vech = unLib->university[i].univer_name;
			}
			if (unLib->university[i].napr[j].bally_zaochn != -1 && unLib->university[i].napr[j].bally_zaochn < min_zaochn)
			{
				min_zaochn = unLib->university[i].napr[j].bally_zaochn;
				*name_zaochn = unLib->university[i].napr[j].name;
				*name_univ_zaochn = unLib->university[i].univer_name;
			}

		}
	}
	printf("����������� ���� ����� ����� ��������: %d\n", min_ochn);
	printf("�������� �����������: %s", *name_ochn);
	printf("���: %s\n", *name_univ_ochn);
	if(min_vech == 999){
		printf("����������� ���� �������� ����� ��������: ��� ������ ����� ��������\n\n");
	}
	else {
		printf("����������� ���� �������� ����� ��������: %d\n", min_vech);
		printf("�������� �����������: %s", *name_vech);
		printf("���: %s\n", *name_univ_vech);
	}
	if (min_zaochn != 999) {
		printf("����������� ���� ������� ����� ��������: %d\n", min_zaochn);
		printf("�������� �����������: %s", *name_zaochn);
		printf("���: %s\n", *name_univ_zaochn);
	}
	else{ printf("����������� ���� ������� ����� ��������: ��� ������ ����� ��������\n\n"); }
}


// string.h
// strlen
// strcmp

void find_napr(UniversityLib* unLib, char* name)
{
	int cout_in_name = 0, count_sovp=0, i, j, flag=0;
	while (name[cout_in_name] != '\0') {
		cout_in_name++;
	}
	name[cout_in_name] = '\n';
	for (j = 0; j<unLib->count; j++) {
		
		for(i=0; i<unLib->university[j].count_napr;i++ ){
			while (unLib->university[j].napr[i].name[count_sovp] == name[count_sovp])
			{
				count_sovp++;
			}
			if (count_sovp - 1 == cout_in_name) {
				printf("���: %s", unLib->university[j].univer_name);
				univer_napr_info(&unLib->university[j], i);
				printf("\n");
				flag++;
			}
			count_sovp = 0;
		}
	}
	if (flag == 0)
	{
		printf("���������� �� �������(\n");
	}

	
}