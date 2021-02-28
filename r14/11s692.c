#include <stdio.h>
#include <math.h>

#define ROZMIAR 10
#define ILOSC 4

void przeksztalc(const double zrodlo[], double cel[], int n, double (*funkcja)(double liczba));
double przeciwna(double liczba);
double odwrocona(double liczba);

int main(void)
{
	double (*funkcje[ILOSC])(double) = { sin, cos, przeciwna, odwrocona };
	double zrodlo[ROZMIAR] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
	double cel[ROZMIAR];

	for (int i = 0; i < ILOSC; i++)
		przeksztalc(zrodlo, cel, ROZMIAR, funkcje[i]);

    return 0;
}

void przeksztalc(const double zrodlo[], double cel[], int n, double (*funkcja)(double liczba))
{
	for (int i = 0; i < n; i++)
	{
		cel[i] = (*funkcja)(zrodlo[i]);
		printf("%.2f ", cel[i]);
	}

	putchar('\n');
}

double przeciwna(double liczba)
{
	return -liczba;
}

double odwrocona(double liczba)
{
	return 1 / liczba;
}