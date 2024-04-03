#include "napr.h"

void fill_napr(const FILE* f, uNapr* napr) 
{
	napr->name = (char*)malloc(sizeof(char) * BUFFER);

	fgets(napr->name, BUFFER, f);
	fscanf(f, "%d", &(napr->bally_norm));
	fscanf(f, "%d", &(napr->bally_vech));
	fscanf(f, "%d", &(napr->bally_zaochn));
	fscanf(f, "%d", &(napr->cost));
}