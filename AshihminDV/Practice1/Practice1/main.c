#include<stdio.h>
#include<math.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "Russian");
	double h = 0, w = 0, d = 0;
	float pld = 720, pldvp = 820, pldsp = 800;
	printf("������� �������� ������ ������ � ������� �����: ");
	//�������� �����
	do {
		scanf("%lf %lf %lf", &h, &w, &d);
		if (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90) {
			printf("������������ ������ \n");
			printf("������� �������� ������ ������ � ������� �����: ");
		}
	} while (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90);
	//������� � ��
	h = h / 100.0;
	w /= 100.0;
	d /= 100.0;
	double td = 1.0 / 100.0;
	double tdsp = 15.0 / 1000.0;
	double tdvp = 5.0 / 1000.0;

	//����������� ����� ��������� �����
	double bokov = h * d * tdsp * pldsp , nst= h * w * tdvp * pldvp , nvn = w * d * tdsp * pldsp , dveri = w * h * td * pld ; //2*�������� 2*���� ����� � ���� ����� ��� 2
	//printf("%lf %lf %lf %lf \n", bokov, nst, nvn, dveri);
	// ������� ���������� ����� � ����� ����� ����� �����
	int kp = h/(tdsp + 0.4);
	double mp = (w - 2 * tdsp) * d * tdsp * pldsp;
	//printf("%lf \n", mp);
	//����������� ����� �����
	double massa = bokov * 2 + nst + nvn * 2 + dveri + mp * kp ;
	
	printf("����� ����� = %lf ", massa);
	printf("��.");

	return 0;
}