#include "univer_description.h"

void read(const char* infilename, Univer* u)
{
	int i = 0;

	FILE* f = fopen(infilename, "r+");
	if (f == NULL) {
		printf("file not found");
		abort();
	}
	fgets(&u->univer_name, 100, f);
	fgets(&u->univer_adres, 100, f);
	fgets(&u->univer_info, 1000, f);
	fill(f, &u->napr);
	
	fclose(f);
}

void print_univ(Univer* u)
{
	printf("%s", u->univer_name);
	printf("%s\n", u->univer_adres);
	printf("%s\n", u->univer_info);
	printf("Направления:\n\n");
	print_uNapr(&u->napr);

}

void list_of_univer(Univer* u, int i)
{
	printf("%d - Университет: %s", i+1, u->univer_name);
}

void univer_info(Univer* u)
{
	printf("%s", u->univer_name);
	printf("%s\n", u->univer_adres);
	printf("%s\n", u->univer_info);
}

void univer_napr(Univer* u)
{
	print_ListNapr(&u->napr);
}