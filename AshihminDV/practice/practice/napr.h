#pragma once
#include"address.h"
#include"EduFormInfo.h"


typedef struct
{
	char* name;
	EducationalFormInfo* educational_forms;
	int nforms;
} uNapr;

void fill_napr(const FILE* f, uNapr* napr);
int find_min(uNapr* napr, int min_score, int idx_min, int idx, int ed_fo, int* idx_min_univ, int idx_univ);