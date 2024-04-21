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
		min_vech = unLib->university[0].napr[0].educational_forms[1].score,
		min_zaochn = unLib->university[0].napr[0].educational_forms[2].score;

	int i, j, nforms;
	int idx_ochn = 0, idx_zaochn = 0, idx_vech = 0;
	int idx_ochn_univ = 0, idx_zaochn_univ = 0, idx_vech_univ = 0;
	int idx_ocnh_nforms = 0, idx_zaocnh_nforms = 1, idx_vech_nforms = 2;

	for (i = 0; i < unLib->count; i++) 
	{
		for (j = 0; j < unLib->university[i].count_napr; j++)
		{
			for (nforms = 0; nforms < unLib->university[i].napr[j].nforms; nforms++)
			{
				idx_ochn = find_min(&unLib->university[i].napr[j].educational_forms[nforms], unLib->university[idx_ochn_univ].napr[idx_ochn].educational_forms[idx_ocnh_nforms].score,
					&idx_ochn_univ, idx_ochn, &i, j, 1, &nforms, &idx_ocnh_nforms);
				idx_zaochn = find_min(&unLib->university[i].napr[j].educational_forms[nforms], unLib->university[idx_zaochn_univ].napr[idx_zaochn].educational_forms[idx_zaocnh_nforms].score, 
					&idx_zaochn_univ, idx_zaochn, &i, j, 2, &nforms, &idx_zaocnh_nforms);
				idx_vech = find_min(&unLib->university[i].napr[j].educational_forms[nforms], unLib->university[idx_vech_univ].napr[idx_vech].educational_forms[idx_vech_nforms].score, 
					&idx_vech_univ, idx_vech, &i, j, 3, &nforms, &idx_vech_nforms);
			}
		}
	}
	printf("Минимальный балл очной формы обучения: %d\n", unLib->university[idx_ochn_univ].napr[idx_ochn].educational_forms[idx_ocnh_nforms].score);
	printf("Название направления: %s", unLib->university[idx_ochn_univ].napr[idx_ochn].name);
	printf("ВУЗ: %s", unLib->university[idx_ochn_univ].univer_name);
	printf("Минимальный балл заочной формы обучения: %d\n", unLib->university[idx_zaochn_univ].napr[idx_zaochn].educational_forms[idx_zaocnh_nforms].score);
	printf("Название направления: %s", unLib->university[idx_zaochn_univ].napr[idx_zaochn].name);
	printf("ВУЗ: %s", unLib->university[idx_zaochn_univ].univer_name);
	printf("Минимальный балл вечерней формы обучения: %d\n", unLib->university[idx_vech_univ].napr[idx_vech].educational_forms[idx_vech_nforms].score);
	printf("Название направления: %s", unLib->university[idx_vech_univ].napr[idx_vech].name);
	printf("ВУЗ: %s\n", unLib->university[idx_vech_univ].univer_name);
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

void free_univ(UniversityLib* unLib, int rez)
{
	int i, j, k = unLib->count;
	if (unLib->university != NULL)
	{
		for (i = 0; i < k; i++)
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
		}
		free(unLib->university);
	}
	
}