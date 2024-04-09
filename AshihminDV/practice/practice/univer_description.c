#include "univer_description.h"

void fill_univer(const FILE* f, Univer* u)
{
	int i = 0;
	char* trash[100];

	u->univer_name = (char*)malloc(sizeof(char) * BUFFER);
	u->univer_info = (char*)malloc(sizeof(char) * BUFFER2);

	fgets(u->univer_name, BUFFER, f);

	allocate_adress(&u->address);
	
	fgets(u->address.town, BUFFER, f);
	fgets(u->address.street, BUFFER, f);
	fscanf(f, "%d", &u->address.house);
	fscanf(f, "%d", &u->address.postcode);
	fgets(trash, 100, f);
	fgets(u->univer_info, BUFFER2, f);
	fscanf(f, "%d", &(u->count_napr));

	fgets(trash, 100, f);
	u->napr = (uNapr*)malloc(sizeof(uNapr) * u->count_napr);

	for (i = 0; i < u->count_napr; i++)
	{
		fill_napr(f, &u->napr[i]);
		fgets(trash, 100, f);
	}
	fclose(f);
}

void univer_info(Univer* u)
{
	printf("��������: %s", u->univer_name);
	printf("�����: %s�����: %s���:%d\n�������� ������: %d\n", u->address.town, u->address.street, u->address.house, u->address.postcode);
	printf("��������: %s", u->univer_info);
}

void univer_napr(Univer* u)
{
	int i = 0;
	for (i; i < u->count_napr; i++)
	{
		printf("%d - �����������: %s", i + 1, u->napr[i].name);
	}
}

void univer_napr_info(Univer* u, int numbNapr)
{
	printf("�����������: %s", u->napr[numbNapr].name);
	if(u->napr[numbNapr].bally_norm!=-1){
		printf("���� ����� ����� ��������: %d\n", u->napr[numbNapr].bally_norm);
	}
	else { printf("����� ����� ����� ��������: ��� ������ ����� ��������\n"); }
	if (u->napr[numbNapr].bally_vech != -1) {
		printf("���� �������� ����� ��������: %d\n", u->napr[numbNapr].bally_vech);
	}
	else { printf("���� �������� ����� ��������: ��� ������ ����� ��������\n"); }
	if (u->napr[numbNapr].bally_zaochn != -1) {
		printf("���� ������� ����� ��������: %d\n", u->napr[numbNapr].bally_zaochn);
	}
	else { printf("���� ������� ����� ��������: ��� ������ ����� ��������\n"); }
	printf("��������� ��������: %d\n", u->napr[numbNapr].cost);
}

void min_conc_po_vyzy(Univer* u)
{
	int min_ochn = 999, min_vech = 999, min_zaochn = 999, i;
	char* name_ochn[100], * name_vech[100], * name_zaochn[100];
	for (i = 0; i < u->count_napr; i++)
	{
		if (u->napr[i].bally_norm != -1 && u->napr[i].bally_norm < min_ochn)
		{
			min_ochn = u->napr[i].bally_norm;
			* name_ochn = u->napr[i].name;
		}
		if (u->napr[i].bally_vech != -1 && u->napr[i].bally_vech < min_vech)
		{
			min_vech = u->napr[i].bally_vech;
			*name_vech = u->napr[i].name;
		}
		if (u->napr[i].bally_zaochn != -1 && u->napr[i].bally_zaochn < min_zaochn)
		{
			min_zaochn = u->napr[i].bally_zaochn;
			*name_zaochn = u->napr[i].name;
		}
	}
	printf("����������� ���� ����� ����� ��������: %d\n", min_ochn);
	printf("�������� �����������: %s\n", *name_ochn);
	if (min_vech == 999) {
		printf("����������� ���� �������� ����� ��������: ��� ������ ����� ��������\n\n");
	}
	else {
		printf("����������� ���� �������� ����� ��������: %d\n", min_vech);
		printf("�������� �����������: %s", *name_vech);
	}
	if (min_zaochn != 999) {
		printf("����������� ���� ������� ����� ��������: %d\n", min_zaochn);
		printf("�������� �����������: %s", *name_zaochn);
	}
	else { printf("����������� ���� ������� ����� ��������: ��� ������ ����� ��������\n\n"); }
}