#pragma once
#include "napr.h"

typedef struct
{
	char* univer_name[100];
	char* univer_adres[100];
	char* univer_info[1000];
	uNapr napr;

} Univer;

void read(const char* infilename, Univer* u);
void print_univ(Univer* u);
void list_of_univer(Univer* u, int i);
void univer_info(Univer* u);
void univer_napr(Univer* u);