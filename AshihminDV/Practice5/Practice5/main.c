#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define N 6

char* baza[N] = { "1111", "1201","1301", "1401", "2402","1503" };
//int baza[N][4] = { {1, 1, 1, 1}, {1,2,0,1},{1,3,0,1},{1,4,0,1},{2,4,0,2},{1,5,0,3} };
char* names[N] = { "Хлеб", "Вода","Молоко", "Пельмени", "Макароны", "Шоколад" };
int price[N] = { 30, 40, 70, 150, 95, 80 };
double sale[N];

void make_sale(int n);
void tovar_info(int i, int k);
int chek_shtrih(int n, int shtrih);

int main() {
	setlocale(LC_ALL, "Rus");
	int shtih, i, sum=0;
	char shtrih = 0;
	double r_skidka = 0.0;
	int kt[N] = { 0, 0, 0, 0, 0, 0 };
	printf("Введите штрихкод товара, для завешения покупки введите 0\n");
	make_sale(N);
	do {
		scanf(" %d", &shtih);

		if (shtih != 0) {
			i = chek_shtrih(N, shtih);
			while (i == -1) {
				printf("Неверный штрихкод\n");
				scanf(" %d", &shtih);
				i = chek_shtrih(N, shtih);
			}
			tovar_info(i, 0);
			kt[i]++;
		}
	} while (shtih != 0);
	printf("\n");
	printf("\nВаш чек\n");
	for (i = 0; i < N; i++) {
		sum += kt[i] * price[i];
		r_skidka += price[i] * sale[i] * kt[i];
		if (kt[i] != 0) {
			tovar_info(i, kt[i]);
		}
	}
	printf("\nЦена без скидки составляет %d\n", sum);
	printf("Скидка составляет %.2lf\n", r_skidka);
	printf("К оплате: %.2lf\n", (double)sum - r_skidka);
}
void make_sale(int n) {
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++) {
		sale[i] = (1+rand() %50)*0.01;
	}
}
void tovar_info(int i, int k) {
	printf("Наименование товара %s\n", names[i]);
	printf("Цена %d\n", price[i]);
	printf("Скидка %.0lf процентов\n", sale[i]*100);
	if (k != 0) {
		printf("Количество: %d\n", k);
	}
}

int chek_shtrih(int n, int shtrih) {
	int i = 0, trash = shtrih;
	char str_shtrih[5];
	_itoa(trash, str_shtrih, 10);

	//printf("0");
	//for (i = 0; i < 5; i++) {
	//	printf("%c", str_shtrih[i]);
	//	printf("\n");
	//}

	for (i = 0; i < n; i++) {
		if (strcmp(str_shtrih, baza[i]) == 0){
			return i;
		}
	}
	return -1;
}