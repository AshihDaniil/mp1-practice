#pragma once
#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include"address.h"

#define BUFFER2 1024

typedef struct
{

	char* name;
	int bally_norm;
	int bally_vech;
	int bally_zaochn;
	int cost;
} uNapr;

void fill_napr(const FILE* f, uNapr* napr);