#pragma once
#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#define BUFFER 256
#define BUFFER2 512

typedef struct
{

	char* name;
	char* info;
	int bally_norm;
	int bally_vech;
	int bally_zaochn;
	int cost;

} uNapr;

void fill_napr(const FILE* f, uNapr* napr);