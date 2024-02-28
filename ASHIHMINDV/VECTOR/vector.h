#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int n;
	double* x;
} Tvector;

void allocete(Tvector* V, int n);
void fill(Tvector* V);
void print(Tvector* V);
Tvector sum(Tvector* V1, Tvector* V2);
Tvector razn(Tvector* V1, Tvector* V2);
double skalPROIZV(Tvector* V1, Tvector* V2);
void read(Tvector* V1, Tvector* V2);
void write(Tvector* s, Tvector* m, double skalpr);

#endif // !VECTOR_H