#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	int re = 0, chis = rand() % 1000 + 1 , zn = -1, kp=1;
	char znak = '>';
	do {
		printf("�������� ������ ���� 1(�� ���������� �����) ��� 2(��������� ��������� �����)");
		scanf(" %d", &re);
	} while (re != 1 && re != 2);

	if (re == 1) {
		printf("������� ��������:");
		scanf(" %d", &zn);
		while (zn != chis) {
			if (zn > chis) {
				printf("���������� ����� < \n");
			}
			if (zn < chis) {
				printf("���������� ����� > \n");
			}
			printf("������� ��������:");
			scanf("%d", &zn);
			kp++ ;
		}
		printf("�� �������!");
		printf("����������� ������� %d", kp);
		return 0;
	}
	if (re == 2) {
		printf("��������� ����� �� 1 �� 1000 \n");
		scanf(" %d", &chis);
		int v_gran = 1000, n_gran = 1;
		zn = 500;
		printf("�� �������� ����� ������ ��� ������ %d \n", zn);
		scanf("%*c%c", &znak);
		while (znak != '=') {
			switch (znak) {
			case '>':
				n_gran = zn;
				zn = (v_gran - n_gran) / 2 + zn;
				break;
			case '<' :
				v_gran = zn;
				zn = (v_gran - n_gran) / 2 + n_gran;
				break;
			default: break;
			}
			printf("�� �������� ����� ������ ��� ������ %d \n", zn);
			scanf("%*c%c", &znak);
			kp++;
		}
		printf("�� �������� ����� %d \n", zn);
		printf("���������� �������� ���������� %d", kp);
	}
}