#pragma once
#include"EdForm.h"


typedef struct
{
	EducationalForm form_id;
	int score;
	int cost;
} EducationalFormInfo;

void fill_EducationalFormInfo(const FILE* F, EducationalFormInfo* EdFInf);
int find_min(EducationalFormInfo* EdFoIn, int min, int *idx_min_univ, int idx_min_napr, int *idx_univ, 
	int idx_napr, int ed_fo, int *nforms, int *idx_nforms);