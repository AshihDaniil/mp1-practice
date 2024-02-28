#include "vector.h"


int main(int argc, char** argv) {
	int n;
	double skpr;
	char* infilename, * outfilename;
	Tvector v1, v2, s, m;
	/*printf("Len of vector1 = ");
	scanf("%d", &n);
	allocete(&v1, n);
	printf("Len of vector2 = ");
	scanf("%d", &n);
	allocete(&v2, n);
	fill(&v1);
	fill(&v2);*/



	read(&v1, &v2);
	printf("vector1\n");
	print(&v1);
	printf("\nvector2\n");
	print(&v2);
	printf("\n\n");

	s = sum(&v1, &v2);
	m = razn(&v1, &v2);
	skpr = skalPROIZV(&v1, &v2);

	write(&s, &m, skpr);

	free(v1.x);
	free(v2.x);
	if (s.x != NULL) {
		free(s.x);
	}
	if (m.x != NULL) {
		free(m.x);
	}
	return 0;
}