#include "napr.h"

void fill_napr(const FILE* f, uNapr* napr) 
{
	int i = 0;
	char* trash[100];
	napr->name = (char*)malloc(sizeof(char) * BUFFER);

	fgets(napr->name, BUFFER, f);

	fscanf(f, "%d", &napr->nforms);

	napr->educational_forms = (EducationalFormInfo*)malloc(sizeof(EducationalFormInfo) * napr->nforms);
	for (i = 0; i < napr->nforms; i++) {
		fill_EducationalFormInfo(f, &napr->educational_forms[i]);
	}
}