#pragma once
#include "napr.h"
#include "address.h"

typedef struct
{
	char* univer_name;
	char* univer_info;
	int count_napr;
	Address address;
	uNapr* napr;
} Univer;



void fill_univ(const char* infilename, Univer* u);
void print_univ(Univer* u, int i);
void univer_info(Univer* u);
void univer_napr(Univer* u);
void univer_napr_info(Univer* u, int numbNapr);
void min_conc_po_vyzy(Univer* u);
void min_conc_po_vyzam(Univer* u);