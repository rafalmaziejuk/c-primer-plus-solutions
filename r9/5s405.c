#include <stdio.h>

void wieksze_od(double *a, double *b);

int main(void)
{	
	double a = 5.5;
	double b = 7.7;

	printf("PRZED ZAMIANA\na = %.1f  b = %.1f\n", a, b);

	wieksze_od(&a, &b);
	putchar('\n');

	printf("PO ZAMIANIE\na = %.1f  b = %.1f\n", a, b);

	return 0;
}

void wieksze_od(double *a, double *b)
{
	*a > *b ? *b = *a : *a = *b;
}