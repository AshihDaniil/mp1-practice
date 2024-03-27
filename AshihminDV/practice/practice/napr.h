#pragma once
#include <stdlib.h>
#include <stdio.h>
#include<locale.h>

typedef struct
{
	char* name[2][100];
	int bally_norm[2];
	int bally_vech[2];
	int bally_zaochn[2];
	int cost[2];
} uNapr;
void fill(const FILE* f, uNapr* napr);

void print_univ(uNapr* napr);
void print_ListNapr(uNapr* napr);