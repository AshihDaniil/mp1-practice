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