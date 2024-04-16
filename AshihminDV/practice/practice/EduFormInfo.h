#pragma once
#include"EdForm.h"


typedef struct
{
	EducationalForm form_id;
	int score;
	int cost;
} EducationalFormInfo;

void fill_EducationalFormInfo(const FILE* F, EducationalFormInfo* EdFInf);