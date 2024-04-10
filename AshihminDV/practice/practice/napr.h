#pragma once
#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include"address.h"

#define BUFFER2 1024

typedef enum
{
	OCHNAY = 1,
	ZAOCHNAY = 2,
	VECHERNYA = 3,
} EducationalForm;

typedef struct
{
	EducationalForm form_id;
	int score;
	int cost;
} EducationalFormInfo;

void fill_EducationalFormInfo(const FILE* F, EducationalFormInfo* EdFInf, int count);

// form_id = OCHAYA;
// form_id == OCHAYA; -> form_id == 1;

typedef struct
{
	char* name;
	EducationalFormInfo* educational_forms;
	int nforms;
	/*int bally_norm;
	int bally_vech;
	int bally_zaochn;
	int cost;*/
} uNapr;

void fill_napr(const FILE* f, uNapr* napr);