#include "univer_description.h"

void fill_univ(const char* infilename, Univer* u)
{
	int i = 0;
	char* trash[100];

	FILE* f = fopen(infilename, "r+");
	if (f == NULL) {
		printf("file not found");
		abort();
	}

	u->univer_name = (char*)malloc(sizeof(char) * BUFFER);
	u->univer_adres = (char*)malloc(sizeof(char) * BUFFER);
	u->univer_info = (char*)malloc(sizeof(char) * BUFFER2);

	fgets(u->univer_name, BUFFER, f);
	fgets(u->univer_adres, BUFFER, f);
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

void print_univ(Univer* u, int i)
{
	printf("%d - ВУЗ: %s", i+1, u->univer_name);
}

void univer_info(Univer* u)
{
	printf("Название: %s", u->univer_name);
	printf("Адрес: %s", u->univer_adres);
	printf("Описание: %s", u->univer_info);
}

void univer_napr(Univer* u)
{
	int i = 0;
	for (i; i < u->count_napr; i++)
	{
		printf("%d - направление: %s", i + 1, u->napr[i].name);
	}
}

void univer_napr_info(Univer* u, int numbNapr)
{
	printf("Напрваление: %s", u->napr[numbNapr].name);
	if(u->napr[numbNapr].bally_norm!=-1){
		printf("Балл очной формы обучения: %d\n", u->napr[numbNapr].bally_norm);
	}
	else { printf("Баллы очной формы обучения: Нет данной формы обучения\n"); }
	if (u->napr[numbNapr].bally_vech != -1) {
		printf("Балл вечерней формы обучения: %d\n", u->napr[numbNapr].bally_vech);
	}
	else { printf("Балл вечерней формы обучения: Нет данной формы обучения\n"); }
	if (u->napr[numbNapr].bally_zaochn != -1) {
		printf("Балл заочной формы обучения: %d\n", u->napr[numbNapr].bally_zaochn);
	}
	else { printf("Балл заочной формы обучения: Нет данной формы обучения\n"); }
	printf("Стоимость обучения: %d\n", u->napr[numbNapr].cost);
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
	printf("Минимальный балл очной формы обучения: %d\n", min_ochn);
	printf("Название направления: %s\n", *name_ochn);
	printf("Минимальный балл вечерней формы обучения: %d\n", min_vech);
	printf("Название направления: %s\n", *name_vech);
	printf("Минимальный балл заочной формы обучения: %d\n", min_zaochn);
	printf("Название направления: %s\n\n", *name_zaochn);

}

/*void min_conc_po_vyzam(Univer* u)
{
	int i = 0,j=0, min_ball = 999;
	char* univ_name[100], * napr_name[100];
	for (j; j < 2; j++) {

	}
}*/