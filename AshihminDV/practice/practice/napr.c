#include "napr.h"

void fill_napr(const FILE* f, uNapr* napr) 
{
	int i = 0;
	napr->name = (char*)malloc(sizeof(char) * BUFFER);

	fgets(napr->name, BUFFER, f);
	fscanf(f, "%d", napr->nforms);
	napr->educational_forms = (EducationalFormInfo*)malloc(sizeof(EducationalFormInfo) * napr->nforms);
	for (i = 0; i < napr->nforms; i++) {
		fill_EducationalFormInfo(f, &napr->educational_forms[i], napr->nforms);
	}
}
void fill_EducationalFormInfo(const FILE* f, EducationalFormInfo* EdFoIn, int count)
{
	int i;
	char* str;
	for (i = 0; i < count; i++)
	{
		fscanf(f, "%s", str);
		if (strcmp(str, "OCNAYA") == 0) {
			EdFoIn->form_id = 1;
		}
		if (strcmp(str, "ZAOCNAYA") == 0) {
			EdFoIn->form_id = 2;
		}
		if (strcmp(str, "VECHERNYA") == 0) {
			EdFoIn->form_id = 3;
		}
		fscanf(f, "%d", EdFoIn->score);
		printf("%d", EdFoIn->score);
		fscanf(f, "%d", EdFoIn->cost);
		printf("%d", EdFoIn->cost);
	}
}