#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	char* town;
	char* street;
	int house;
	char* postcode;
} Address;

void get_address(const FILE* f ,Address* adr);