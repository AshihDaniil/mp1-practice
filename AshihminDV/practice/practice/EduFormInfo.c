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