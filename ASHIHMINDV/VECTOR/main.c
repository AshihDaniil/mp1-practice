#include <stdio.h>
#include "vector.h"


int main() {
	int n;
	double skpr;
	Tvector v1, v2, s;
	printf("Len of vector1 = ");
	scanf("%d", &n);
	allocete(&v1, n);
	printf("Len of vector2 = ");
	scanf("%d", &n);
	allocete(&v2, n);
	fill(&v1);
	fill(&v2);
	printf("sum ");
	s = sum(&v1, &v2);
	print(&s);
	printf("razn ");
	s = razn(&v1, &v2);
	print(&s);
	skpr = skalPROIZV(&v1, &v2);
	printf("SKALYARNOE PROIZVEDENIE = %lf", skpr);

	free(v1.x);
	free(v2.x);
	if (s.x != NULL) {
		free(s.x);
	}
	return 0;
}