#include "napr.h"

void fill(const FILE* f, uNapr* napr)
{
	int i = 0;
	char trash[100];

	for (i = 0; i < 2; i++)
	{
		fgets(&napr->name[i], 100 , f);
		fscanf(f, "%d", &napr->bally_norm[i]);
		fscanf(f, "%d", &napr->bally_vech[i]);
		fscanf(f, "%d", &napr->bally_zaochn[i]);
		fscanf(f, "%d", &napr->cost[i]);
		fgets(trash, 100, f);
	}
	fclose(f);
}
void print_uNapr(uNapr* napr)
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("%s", napr->name[i]);
		printf("Баллы дневной формы обучения: %d\n",napr->bally_norm[i]);
		printf("Баллы вечерней формы обучения: %d\n", napr->bally_vech[i]);
		printf("Баллы заочной формы обучения: %d\n", napr->bally_zaochn[i]);
		printf("Стоимость Договорного обучения: %d\n\n", napr->cost[i]);
	}
}
void print_ListNapr(uNapr* napr)
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("%d - %s",i+1, napr->name[i]);
	}
}