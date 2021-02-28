#include <stdio.h>
#include <stdlib.h>
#include "rzutkosc.h"

int liczba_rzutow = 0;

static int rzucaj(int scianki)
{
	int oczka = rand() % scianki + 1;

	++liczba_rzutow;

	return oczka;
}

int rzucaj_n_razy(int rzuty, int scianki)
{
	int k;
	int suma = 0;

	if (scianki < 2)
	{
		printf("Wymagane sa co najmniej 2 scianki.\n");
		return -2;
	}

	if (rzuty < 1)
	{
		printf("Wymagany jest co najmniej 1 rzut.\n");
		return -1;
	}

	for (k = 0; k < rzuty; k++)
		suma += rzucaj(scianki);

	return suma;
}