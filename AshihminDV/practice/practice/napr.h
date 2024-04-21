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