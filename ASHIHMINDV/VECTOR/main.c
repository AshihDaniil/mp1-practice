#include "vector.h"


int main(int argc, char** argv) {
	int n;
	double skpr;
	char* infilename, * outfilename;
	Tvector v1, v2, s, m;

	if (argc < 3) {
		printf("Incorrect argument\n");
		return 1;
	}

	infilename = argv[1];
	printf("IN File Name: %s\n", infilename);
	outfilename = argv[2];
	printf("OUT File Name: %s\n", outfilename);

	//read("Vectors_A.txt", &v1, &v2);
	read(infilename, &v1, &v2);

	printf("vector1\n");
	print(&v1);
	printf("\nvector2\n");
	print(&v2);
	printf("\n\n");

	s = sum(&v1, &v2);
	print(&s);
	m = razn(&v1, &v2);
	//print(&m);
	skpr = skalPROIZV(&v1, &v2);

	write(outfilename, &v1, &v2, skpr);

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