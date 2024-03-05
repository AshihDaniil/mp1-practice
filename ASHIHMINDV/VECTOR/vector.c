#include "vector.h"

void allocete(Tvector* V, int n) {
	V->n = n;
	V->x = (double*)malloc(sizeof(double) * n);
}

void fill(Tvector* V) {
	int i = 0;
	printf("Fill vector = ");
	for (; i < V->n; i++) {
		scanf("%lf", &(V->x[i]));
	}

}

void print(Tvector* V) {
	int i = 0;
	if (V->x != NULL) {
		printf("Vector: ");
		for (; i < V->n; i++) {
			printf("%.2lf ", V->x[i]);

		}
		printf("\n");
	}
}

Tvector sum(Tvector* V1, Tvector* V2) {
	Tvector res;
	int i = 0;
	if (V1->n != V2->n) {
		printf("V1->n != V2->n \n");
		res.x = NULL;
		res.n = 0;
		return res;
	}
	allocete(&res, V1->n);
	for (; i < res.n; i++) {
		res.x[i] = V1->x[i] + V2->x[i];
	}
	return res;
}

Tvector razn(Tvector* V1, Tvector* V2) {
	Tvector res;
	int i = 0;
	if (V1->n != V2->n) {
		printf("V1->n != V2->n \n");
		res.x = NULL;
		res.n = 0;
		return res;
	}
	allocete(&res, V1->n);
	for (; i < res.n; i++) {
		res.x[i] = V1->x[i] - V2->x[i];
	}
	return res;
}

double skalPROIZV(Tvector* V1, Tvector* V2) {
	int i = 0;
	double skproiz = 0.0;
	if (V1->n != V2->n) {
		return 0;
	}
	for (; i < V1->n; i++) {
		skproiz += V1->x[i] * V2->x[i];
	}
	return skproiz;
}

void read(const char* infilename, Tvector* V1, Tvector* V2) {
	int i = 0;
	FILE* f = fopen(infilename, "r+");
	if (f == NULL) {
		printf("file not found");
		abort();
	}
	fscanf(f, "%d", &V1->n);
	V1->x = (double*)malloc(sizeof(double) * V1->n);
	for (; i < V1->n; i++) {
		fscanf(f, "%lf", &V1->x[i]);
	}
	fscanf(f, "%d", &V2->n);
	V2->x = (double*)malloc(sizeof(double) * V2->n);
	for (i=0; i < V2->n; i++) {
		fscanf(f, "%lf", &V2->x[i]);
	}
	fclose(f);
}
void write(const char* outfilename, Tvector* s, Tvector* m, double skalpr) {
	int i = 0;
	FILE* f = fopen(outfilename, "w+");
	if (f == NULL) {
		printf("file not found");
		abort();
	}
	fprintf(f, "SUMMA = ");
	for (; i < s->n; i++) {
		fprintf(f, "%.2lf ", s->x[i]);
	}
	fprintf(f, "\n");
	fprintf(f, "RAZN = ");
	for (i=0; i < m->n; i++) {
		fprintf(f, "%.2lf ", m->x[i]);
	}
	fprintf(f, "\n");
	fprintf(f, "skalyarnoe proizvedenie = %lf", skalpr);
	fclose(f);
}