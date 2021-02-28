#include <stdio.h>

void zamiana(double *a, double *b, double *c);

int main(void)
{
	double a = 7.7;
	double b = 5.5;
	double c = 6.6;

	printf("PRZED ZAMIANA\na = %.1f  b = %.1f c = %.1f\n", a, b, c);

	zamiana(&a, &b, &c);
	putchar('\n');

	printf("PO ZAMIANIE\na = %.1f  b = %.1f c = %.1f\n", a, b, c);

	return 0;
}

void zamiana(double *a, double *b, double *c)
{
	double najmniejsza;
	double srodkowa;
	double najwieksza;

	if (*a < *b && *a < *c)
		najmniejsza = *a;
	else if (*b < *a && *b < *c)
		najmniejsza = *b;
	else if (*c < *a && *c < *b)
		najmniejsza = *c;

	if (*a > *b && *a > *c)
		najwieksza = *a;
	else if (*b > *a && *b > *c)
		najwieksza = *b;
	else if (*c > *a && *c > *b)
		najwieksza = *c; 

	if (*a > najmniejsza && *a < najwieksza)
		srodkowa = *a;
	else if (*b > najmniejsza && *b < najwieksza)
		srodkowa = *b;
	else if (*c > najmniejsza && *c < najwieksza)
		srodkowa = *c;

	*a = najmniejsza;
	*b = srodkowa;
	*c = najwieksza;
}