#include <stdio.h>
#include "pe12-2a.h"

static int tryb;
static int dystans;
static float zuzyte_paliwo;

void wybierz_tryb(int t)
{
	if (t != 1 && t != 0)
	{
		puts("Podano nieprawidlowa wartosc. Wybrano system 1 (US).");
		tryb = 1;
	}
	else tryb = t;
}

void pobierz_dane(void)
{
	if (tryb == 0)
	{
		puts("Wprowadz przebyta odleglosc w kilometrach: ");
		scanf("%d", &dystans);

		puts("Wprowadz zuzyte paliwo w litrach: ");
		scanf("%f", &zuzyte_paliwo);
	}
	else if (tryb == 1)
	{
		puts("Wprowadz przebyta odleglosc w milach: ");
		scanf("%d", &dystans);

		puts("Wprowadz zuzyte paliwo w galonach: ");
		scanf("%f", &zuzyte_paliwo);
	}
}

void wyswietl_dane(void)
{
	if (tryb == 0)
		printf("Zuzycie paliwa wynioslo %.2f litrow na 100km.\n", (zuzyte_paliwo / dystans) * 100);
	else if (tryb == 1)
		printf("Zuzycie paliwa wynioslo %.2f mil na galon.\n", dystans / zuzyte_paliwo);
}
