#pragma once
#include "univer_description.h"
#include <string.h>

typedef struct
{
	Univer* university;
	int count;
} UniversityLib;

void allocate(UniversityLib* unLib, int count);
void fill_univers(UniversityLib* unLib, const char** infilename);
void print_univers(UniversityLib* unLib);
void min_conc_po_vyzam(UniversityLib* unLib);
UniversityLib find_napr(UniversityLib* unLib, UniversityLib* found_univ, char* name);
void free_univ(UniversityLib* unLib, int rez);