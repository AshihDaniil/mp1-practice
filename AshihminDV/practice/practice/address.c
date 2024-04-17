#include "address.h"

void allocate_adress(Address* adr) 
{
	adr->town = (char*)malloc(sizeof(char) * BUFFER);
	adr->street = (char*)malloc(sizeof(char) * BUFFER);
}

