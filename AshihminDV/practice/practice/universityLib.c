#include "universityLib.h"

void allocate(UniversityLib* unLib, int count)
{
	unLib->count = count;
	if (count <= 0) {
		unLib->university = NULL;
	}
	unLib->university = (Univer*)malloc(sizeof(Univer) * count);
}

void fill_univers(UniversityLib* unLib, const char** infilename)
{
	int i = 0;
	for (i = 0; i < unLib->count; i++)
	{	
		FILE* f = fopen(infilename[i], "r+");
		if (f == NULL) {
			printf("file not found");
			abort();
		}
		fill_univer(f, &unLib->university[i]);
		fclose(f);
	}
}

void print_univers(UniversityLib* unLib)
{
	int i;
	for (i = 0; i < unLib->count; i++) {
		printf("%d ВУЗ - %s", i + 1, unLib->university[i].univer_name);
	}
}

void min_conc_po_vyzam(UniversityLib* unLib)
{
	int min_ochn = unLib->university[0].napr[0].educational_forms[0].score,
		min_vech = unLib->university[0].napr[0].educational_forms[0].score,
		min_zaochn = unLib->university[0].napr[0].educational_forms[0].score;
	char* name_univ_ochn[100], * name_univ_vech[100], * name_univ_zaochn[100];
	char* name_ochn[100], * name_vech[100], * name_zaochn[100];
	*name_ochn = unLib->university[0].napr[0].name;
	*name_vech = unLib->university[0].napr[0].name;
	*name_zaochn = unLib->university[0].napr[0].name;
	*name_univ_ochn = unLib->university[0].univer_name;
	*name_univ_vech = unLib->university[0].univer_name;
	*name_univ_zaochn = unLib->university[0].univer_name;

	int i, j, nforms;
	int idx_ochn = 0, idx_zaocn = 0, idx_vech = 0;
	int idx_min_ochn_univ = 0, idx_min_zaochn_univ = 0, idx_min_vech_univ = 0;

	for (i = 0; i < unLib->count; i++) 
	{
		for (j = 0; j < unLib->university[i].count_napr; j++)
		{
			for (nforms = 0; nforms < unLib->university[i].napr[j].nforms; nforms++)
			{
				
				/*if (unLib->university[i].napr[j].educational_forms[nforms].form_id == 1) 
				{
					if (unLib->university[i].napr[j].educational_forms[nforms].score < min_ochn) {
						min_ochn = unLib->university[i].napr[j].educational_forms[nforms].score;
						*name_ochn = unLib->university[i].napr[j].name;
						*name_univ_ochn = unLib->university[i].univer_name;
					}
				}
				if (unLib->university[i].napr[j].educational_forms[nforms].form_id == 2)
				{
					if (unLib->university[i].napr[j].educational_forms[nforms].score < min_ochn) {
						min_zaochn = unLib->university[i].napr[j].educational_forms[nforms].score;
						*name_zaochn = unLib->university[i].napr[j].name;
						*name_univ_zaochn = unLib->university[i].univer_name;
					}
				}
				if (unLib->university[i].napr[j].educational_forms[nforms].form_id == 3)
				{
					if (unLib->university[i].napr[j].educational_forms[nforms].score < min_ochn) {
						min_vech = unLib->university[i].napr[j].educational_forms[nforms].score;
						*name_vech = unLib->university[i].napr[j].name;
						*name_univ_vech = unLib->university[i].univer_name;
					}
				}*/
			}
		}
	}
	printf("Минимальный балл очной формы обучения: %d\n", min_ochn);
	printf("Название направления: %s", *name_ochn);
	printf("ВУЗ: %s\n", *name_univ_ochn);
	printf("Минимальный балл вечерней формы обучения: %d\n", min_vech);
	printf("Название направления: %s", *name_vech);
	printf("ВУЗ: %s\n", *name_univ_vech);
	printf("Минимальный балл заочной формы обучения: %d\n", min_zaochn);
	printf("Название направления: %s", *name_zaochn);
	printf("ВУЗ: %s\n", *name_univ_zaochn);

}



UniversityLib find_napr(UniversityLib* unLib, UniversityLib* found_univ, char* name)
{
	int len, i, j, nf = 0, count_univ = 0, count_napr, n_univ=0;

	UniversityLib found;

	len = strlen(name);
	name[len] = '\n';
	name[len + 1] = '\0';
	for (j = 0; j < unLib->count; j++) {
		for (i = 0; i < unLib->university[j].count_napr; i++) {
			if (strcmp(name, unLib->university[j].napr[i].name) == 0)
			{
				count_univ++;
				break;
				
			}
		}
	}

	if (count_univ == 0)
	{
		found.count = 0;
		found.university = NULL;
		return found;
	}

	allocate(&found, count_univ);
	count_univ = 0;

	for (j = 0; j < unLib->count; j++) {
		count_napr = 0;
		for (i = 0; i < unLib->university[j].count_napr; i++) {
			if (strcmp(name, unLib->university[j].napr[i].name) == 0)
			{
				count_napr++;
			}
		}
		if (count_napr != 0)
		{
			found.university[count_univ].count_napr = count_napr;
			count_univ++;
		}
	}
	count_univ = 0;
	count_napr = 0;

	for (i = 0; i < found.count; i++)
	{
		for (j = 0; j < found.university[i].count_napr; j++)
		{
			found.university[i].napr = (uNapr*)malloc(sizeof(uNapr) * found.university[i].count_napr);
		}
	}
	
	for (j = 0; j < unLib->count; j++) {
		count_univ = 0;
		count_napr = 0;
		for (i = 0; i < unLib->university[j].count_napr; i++) {
			if (strcmp(name, unLib->university[j].napr[i].name) == 0)
			{
				
				found.university[n_univ].napr[count_napr].name = (char*)malloc(sizeof(char) * BUFFER);
				found.university[n_univ].napr[count_napr].name = unLib->university[j].napr[i].name;
				found.university[n_univ].napr[count_napr].nforms = unLib->university[j].napr[i].nforms;
				found.university[n_univ].napr[count_napr].educational_forms =
					(EducationalFormInfo*)malloc(sizeof(EducationalFormInfo) * found.university[n_univ].napr[count_napr].nforms);
				
				for (nf = 0; nf < found.university[n_univ].napr[count_napr].nforms; nf++)
				{
					found.university[n_univ].napr[count_napr].educational_forms[nf].cost =
						unLib->university[j].napr[i].educational_forms[nf].cost;
					found.university[n_univ].napr[count_napr].educational_forms[nf].score =
						unLib->university[j].napr[i].educational_forms[nf].score;
					found.university[n_univ].napr[count_napr].educational_forms[nf].form_id =
						unLib->university[j].napr[i].educational_forms[nf].form_id;
				}

				if (count_univ == 0)
				{
					found.university[n_univ].univer_name = (char*)malloc(sizeof(char) * BUFFER);
					found.university[n_univ].univer_name = unLib->university[j].univer_name;

					count_univ++;
					n_univ++;
				}
				count_napr++;
			}
		}
	}

	return found;
}

void free_univ(UniversityLib* unLib)
{
	int i, j, ij;
	if (unLib->university != NULL)
	{
		for (i = 0; i < unLib->count; i++)
		{
			free(unLib->university[i].univer_name);
			free(unLib->university[i].univer_info);
			free(unLib->university[i].address.town);
			free(unLib->university[i].address.street);
			for (j = 0; j < unLib->university[i].count_napr; j++)
			{
				free(unLib->university[i].napr[j].name);
				free(unLib->university[i].napr[j].educational_forms);
			}
			
			free(unLib->university[i].napr);
			free(unLib->university);

		}
	}
}