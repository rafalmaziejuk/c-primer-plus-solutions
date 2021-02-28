#include <stdio.h>
#include "pe12-2a.h"

void wybierz_tryb(int *t)
{
	if (*t != 1 && *t != 0)
	{
		puts("Podano nieprawidlowa wartosc. Wybrano system 1 (US).");
		*t = 1;
	}
}

void pobierz_dane(int *d, float *zp, int t)
{
	if (t == 0)
	{
		puts("Wprowadz przebyta odleglosc w kilometrach: ");
		scanf("%d", d);

		puts("Wprowadz zuzyte paliwo w litrach: ");
		scanf("%f", zp);
	}
	else if (t == 1)
	{
		puts("Wprowadz przebyta odleglosc w milach: ");
		scanf("%d", d);

		puts("Wprowadz zuzyte paliwo w galonach: ");
		scanf("%f", zp);
	}
}

void wyswietl_dane(int d, float zp, int t)
{
	if (t == 0)
		printf("Zuzycie paliwa wynioslo %.2f litrow na 100km.\n", (zp / d) * 100);
	else if (t == 1)
		printf("Zuzycie paliwa wynioslo %.2f mil na galon.\n", d / zp);
}