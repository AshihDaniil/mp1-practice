#pragma once
#include <stdlib.h>
#include <stdio.h>
#define BUFFER 256

typedef struct
{
	char* town;
	char* street;
	int house;
	int postcode;
} Address;


void allocate_adress(Address* adr);
void get_address(const FILE* f ,Address* adr);