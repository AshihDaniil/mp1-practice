#include <stdio.h>
#include <math.h>

int main()
{
	int x1, y1, r1;
	int x2, y2, r2;
	printf("vvedite koordinatie i radius 1 okryzhnosti");
	scanf("%d %d %d", &x1 ,&y1 , &r1 );
	if (r1 <= 0) //�������� �� ������������ 
	{
		printf("neverniy radiys");
		return 0;
	}
	printf("vvedite koordinatie i radius 2 okryzhnosti");
	scanf("%d %d %d", &x2, &y2, &r2);
	if (r2 <= 0) //�������� �� ������������ 
	{
		printf("neverniy radiys");
		return 0;
	}
	double d;
	double kvrazn = sqrt((r1-r2)*(r1-r2)) ;
	if (x1 == x2 && y1 == y2 && r1 == r2) //��������� ����� 
	{
		printf("oni sovpadauyt");
		return 0;
	}
	else
	{
		d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));
		//printf("d= %lf", d); 
		if (r1 + r2 > d && r1 + d > r2 && r2 + d > r1) //2 ����� ������� 
		{
			printf("2 tochki kasania snaryzhi");
			//return 0;
		}
		if (r1 + r2 == d) //1 ����� ������� 
		{
			printf("1 tochka kasania snaryzhi");
		}
		if ( kvrazn == d) //1 ����� ������� ������
		{
			printf("1 tochka kasania vnytri");
		}
		if (r1 + r2 < d) //�� ��������  
		{
			printf("net kasaniya");
		}
		if (r1 > r2)
		{
			if (r2 + d < r1) //������ ����� � ������ 
			{
				printf("2ua lezhit v 1oi");
			}
		}
		else
		{
			if (r1 + d < r2) //������ ����� �� ������ 
			{
				printf("1ya lezhit v 2oi");
			}
		}

	}
	return 0;
}