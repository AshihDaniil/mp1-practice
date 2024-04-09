#include "address.h"

void allocate_adress(Address* adr) 
{
	adr->town = (char*)malloc(sizeof(char) * BUFFER);
	adr->street = (char*)malloc(sizeof(char) * BUFFER);
}

void get_address(const FILE* f, Address* adr)
{
	adr->town = (char*)malloc(sizeof(char) * BUFFER);
	adr->street = (char*)malloc(sizeof(char) * BUFFER);
	fgets(adr->town, BUFFER, f);
	fgets(adr->street, BUFFER, f);
	fscanf(f, "%d", &(adr->house));
	fscanf(f, "%d", &(adr->postcode));
}