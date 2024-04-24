#include"EduFormInfo.h"

void fill_EducationalFormInfo(const FILE* f, EducationalFormInfo* EdFoIn)
{
	char str[BUFFER];
	char trash[BUFFER];
	fscanf(f, "%s", str);
	if (strcmp(str, "OCHNAYA") == 0) {
		EdFoIn->form_id = 1;
	}
	if (strcmp(str, "ZAOCHNAY") == 0) {
		EdFoIn->form_id = 2;
	}
	if (strcmp(str, "VECHERNYA") == 0) {
		EdFoIn->form_id = 3;
	}
	fgets(trash, BUFFER, f);
	fscanf(f, "%d", &EdFoIn->score);
	fscanf(f, "%d", &EdFoIn->cost);
}

int find_min(EducationalFormInfo* EdFoIn, int min, int *idx_min_univ, int idx_min_napr, int *idx_univ, 
	int idx_napr, int ed_fo, int* nforms, int* idx_nforms)
{
	if (EdFoIn->form_id == ed_fo)
	{
		if (EdFoIn->score < min)
		{
			*idx_min_univ = *idx_univ;
			*idx_nforms = *nforms;
			return idx_napr;
		}
	}
	return idx_min_napr;
}