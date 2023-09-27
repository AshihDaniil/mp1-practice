#include <stdio.h>
#include <math.h>

int main()
{
	int x1, y1, r1;
	int x2, y2, r2;
	printf("vvedite koordinatie i radius 1 okryzhnosti");
	scanf("%d %d %d", &x1 ,&y1 , &r1 );
	if (r1 <= 0) //проверка на корректность 
	{
		printf("neverniy radiys");
		return 0;
	}
	printf("vvedite koordinatie i radius 2 okryzhnosti");
	scanf("%d %d %d", &x2, &y2, &r2);
	if (r2 <= 0) //проверка на корректность 
	{
		printf("neverniy radiys");
		return 0;
	}
	double d;
	double kvrazn = sqrt((r1-r2)*(r1-r2)) ;
	if (x1 == x2 && y1 == y2 && r1 == r2) //окружноси равны 
	{
		printf("oni sovpadauyt");
		return 0;
	}
	else
	{
		d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));
		//printf("d= %lf", d); 
		if (r1 + r2 > d && r1 + d > r2 && r2 + d > r1) //2 точки снаружи 
		{
			printf("2 tochki kasania snaryzhi");
			//return 0;
		}
		if (r1 + r2 == d) //1 точка снаружи 
		{
			printf("1 tochka kasania snaryzhi");
		}
		if ( kvrazn == d) //1 точка касания внутри
		{
			printf("1 tochka kasania vnytri");
		}
		if (r1 + r2 < d) //не касаются  
		{
			printf("net kasaniya");
		}
		if (r1 > r2)
		{
			if (r2 + d < r1) //вторая лежит в первой 
			{
				printf("2ua lezhit v 1oi");
			}
		}
		else
		{
			if (r1 + d < r2) //первая лежит во второй 
			{
				printf("1ya lezhit v 2oi");
			}
		}

	}
	return 0;
}