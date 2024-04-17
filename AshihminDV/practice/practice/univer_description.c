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
	printf("Название: %s", u->univer_name);
	printf("Город: %sУлица: %sДом:%d\nПочтовый Индекс: %d\n", u->address.town, u->address.street, u->address.house, u->address.postcode);
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
	int i = 0;
	printf("Напрваление: %s", u->napr[numbNapr].name);
	for (i = 0; i < u->napr[numbNapr].nforms; i++)
	{
		if (u->napr[numbNapr].educational_forms[i].form_id == 1) 
		{
			printf("Балл очной формы обучения: %d\n", u->napr[numbNapr].educational_forms[i].score);
			printf("Стоимость очной формы обучения: %d\n", u->napr[numbNapr].educational_forms[i].cost);
		}
		if (u->napr[numbNapr].educational_forms[i].form_id == 2)
		{
			printf("Балл заочной формы обучения: %d\n", u->napr[numbNapr].educational_forms[i].score);
			printf("Стоимость заочной формы обучения: %d\n", u->napr[numbNapr].educational_forms[i].cost);
		}
		if (u->napr[numbNapr].educational_forms[i].form_id == 3)
		{
			printf("Балл вечерней формы обучения: %d\n", u->napr[numbNapr].educational_forms[i].score);
			printf("Стоимость вечерней формы обучения: %d\n", u->napr[numbNapr].educational_forms[i].cost);
		}
	}
}





void min_conc_po_vyzy(Univer* u)
{
	int min_ochn = u->napr[0].educational_forms[0].score, min_vech = u->napr[0].educational_forms[0].score,
		min_zaochn = u->napr[0].educational_forms[0].score, i;
	int j, idx_ochn, idx_zaochn;
	char* name_ochn[100], * name_vech[100], * name_zaochn[100];
	*name_ochn = u->napr[0].name;
	*name_vech = u->napr[0].name;
	*name_zaochn = u->napr[0].name;


	for (i = 1; i < u->count_napr; i++)
	{
		for (j = 0; j < u->napr[i].nforms; j++) {
			if (u->napr[i].educational_forms[j].form_id == 1) {
				if (u->napr[i].educational_forms[j].score < min_ochn) { 
					min_ochn = u->napr[i].educational_forms[j].score; 
					*name_ochn = u->napr[i].name;
				}
			}
			if (u->napr[i].educational_forms[j].form_id == 2) {
				if (u->napr[i].educational_forms[j].score < min_zaochn) { 
					min_zaochn = u->napr[i].educational_forms[j].score;
					*name_zaochn = u->napr[i].name;
				}
			}
			if (u->napr[i].educational_forms[j].form_id == 3) {
				if (u->napr[i].educational_forms[j].score < min_vech) { 
					min_vech = u->napr[i].educational_forms[j].score;
					*name_vech = u->napr[i].name;
				}
			}
		}
	}
	printf("Минимальный балл очной формы обучения: %d\n", min_ochn);
	printf("Название направления: %s\n", *name_ochn);
	printf("Минимальный балл заочной формы обучения: %d\n", min_zaochn);
	printf("Название направления: %s\n", *name_zaochn);
	printf("Минимальный балл вечерней формы обучения: %d\n", min_vech);
	printf("Название направления: %s\n", *name_vech);
	
}