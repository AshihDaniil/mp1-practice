#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#define BUFFER 2048
//1 ������� 2 ��������� 3 �������

int Fill_the_List(char *adres, wchar_t** FileNames, ULONGLONG* FileSize, unsigned long* Index);
void bubble_sort(int dl, ULONGLONG* FileSize,unsigned long* Index);
void choose_sort(ULONGLONG* FileSize, int dl, unsigned long* Index);
void fast_sort(ULONGLONG* FileSize, int dl, unsigned long* Index);
void print_massiv(wchar_t** FileNames, ULONGLONG* FileSize, int k, unsigned long* Index);
void choose_the_sort();

int main() {
	int k=0, i=0, rezhim;
	char *adres[BUFFER];

	unsigned long* Index = (unsigned long*)malloc(sizeof(unsigned long)* BUFFER);
	unsigned long* copy_Index = (unsigned long*)malloc(sizeof(unsigned long) * BUFFER);

	ULONGLONG* FileSize = (ULONGLONG*)malloc(BUFFER * sizeof(ULONGLONG));
	ULONGLONG* copy_FileSize = (ULONGLONG*)malloc(BUFFER * sizeof(ULONGLONG));

	wchar_t** FileNames = (wchar_t**)malloc(BUFFER * sizeof(wchar_t*));

	clock_t start, finish;
	double finaltime = 0.0 ;

	setlocale(LC_ALL, "Rus");
	printf("_ _ _ _ _ _ _ _ �������� �������� _ _ _ _ _ _ _ _\n");
	printf("������� �������� ������: ");
	k = Fill_the_List(adres, FileNames, FileSize, Index);
	while (k == -1) {
		printf("ERROR: �������� ����\n");
		k = Fill_the_List(adres, FileNames, FileSize, Index);
	}

	printf("_ _ _ _ _ _ _ _ ������ ������ _ _ _ _ _ _ _ _\n");
	printf("���������� ������: %d\n", k);
	print_massiv(FileNames, FileSize, k, Index);
	printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \n");
	choose_the_sort();
	do {
		scanf("%d", &rezhim);
		memcpy(copy_FileSize, FileSize, BUFFER);
		memcpy(copy_Index, Index, BUFFER);
		switch (rezhim)
		{
		case 1:
			start = clock(0);
			printf("���������� �������\n");
			choose_sort(copy_FileSize, k, copy_Index);
			finish = clock(0);
			break;
		case 2:
			start = clock(0);
			printf("���������� ���������\n");
			bubble_sort(k, copy_FileSize, copy_Index);
			finish = clock(0);
			break;
		case 3:
			start = clock(0);
			printf("������� ����������\n");
			fast_sort(copy_FileSize, k, copy_Index);
			finish = clock(0);
			break;
		case 4:
			continue;
			break;
		default:
			printf("�������� ����. ���������� ������\n");
			continue;
		}
		finaltime = difftime(finish, start);
		printf("_ _ _ _ _ _ _ _ ������������� _ _ _ _ _ _ _ _ \n");
		printf("����� ����������: %lf ������� \n", finaltime);
		print_massiv(FileNames, copy_FileSize, k, Index);
		printf("������ ������� ������ ����������) ");

	} while (rezhim != 4);
	free(FileSize);
	free(FileNames);
	free(copy_FileSize);
	free(Index);
	free(copy_Index);
	return 0;
}

int Fill_the_List(char* adres, wchar_t** FileNames, ULONGLONG* FileSize, unsigned long* Index) {
	int i = 0;
	WIN32_FIND_DATA fd;
	wchar_t* itog_adres;
	_getws(adres);
	itog_adres = (wchar_t*)malloc(BUFFER * sizeof(wchar_t));
	wsprintf(itog_adres, L"%s\\*", adres);

	HANDLE hFind = FindFirstFile(itog_adres, &fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		FindClose(hFind);
		free(itog_adres);
		return -1;
	}

	if (hFind != INVALID_HANDLE_VALUE); {
		do {
			if (strcmp(fd.cFileName, ".") != 0 && strcmp(fd.cFileName, "..") != 0) {
				//SIZE
				FileSize[i] = fd.nFileSizeLow + (fd.nFileSizeHigh * (MAXDWORD + 1));
				//NAME
				FileNames[i] = (wchar_t*)malloc(sizeof(wchar_t) * BUFFER);
				wsprintf(itog_adres, L"%s\\%s", adres, fd.cFileName);
				wsprintf(FileNames[i], L"%s", itog_adres);
				Index[i] = i;
				i++;
			}
		} while (FindNextFile(hFind, &fd));
		FindClose(hFind);
		free(itog_adres);
		return i;
	}
}

void choose_the_sort() {
	printf("�������� ����� ����������\n");
	printf("1 - ���������� �������\n");
	printf("2 - ���������� ���������\n");
	printf("3 - ���������� �������\n");
	printf("4 - ����� �� ���������\n");
}

void print_massiv(wchar_t** FileNames, ULONGLONG* FileSize, int k, unsigned long* Index) {
	int i = 0; 
	for (i = 0; i < k; i++) {
		printf("%5d: %S ������ (%d ����)\n", i + 1, FileNames[Index[i]], FileSize[i]);
	}
}

void bubble_sort(int dl, ULONGLONG* FileSize, unsigned long* Index) {
	int i, j, copy_index;
	unsigned long copy_size;
	for (i = 0; i < dl; i++) {
		for (j = 0; j < dl - 1; j++) {
			if(FileSize[j]>FileSize[j+1]){
				copy_size = FileSize[j];
				FileSize[j] = FileSize[j + 1];
				FileSize[j + 1] = copy_size;
				copy_index = Index[j];
				Index[j] = Index[j + 1];
				Index[j + 1] = copy_index;
			}
		}
	}
}

void choose_sort(ULONGLONG* FileSize, int dl, unsigned long* Index) {
	int i = 0, j=0, minind;
	unsigned long min, copy_size;
	for (i = 0; i < dl; i++) {
		minind = i;
		for (j = i + 1; j < dl; j++) {
			if (FileSize[j]<FileSize[minind]) {
				minind = j;
			}
		}
		copy_size = FileSize[i];
		FileSize[i] = FileSize[minind];
		FileSize[minind] = copy_size;
	}
}

void fast_sort(ULONGLONG* FileSize, int dl, unsigned long* Index) {
	int i = 0, j = dl - 1, mid = FileSize[dl / 2], copy_ind;
	unsigned long copy_size;
	do {
		while (FileSize[i] < mid) {
			i++;
		}
		while (FileSize[i] > mid) {
			j--;
		}
		if (i <= j) {
			copy_size = FileSize[i];
			FileSize[i] = FileSize[j];
			FileSize[j] = copy_size;
			copy_ind = Index[i];
			Index[i] = Index[j];
			Index[j] = copy_ind;

			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		fast_sort(FileSize, j + 1, Index);
	}
	if (i < dl) {
		fast_sort(&FileSize[i], dl-i, Index);
	}
}