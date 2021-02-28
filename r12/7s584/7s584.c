#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rzutkosc.h"

int main(void)
{
	int kolejki;
	int kosci, scianki;
	int wynik;

	srand((unsigned int) time(0));

	printf("Wprowadz liczbe kolejek; wybierz q, aby zakonczyc.\n");

	while (scanf("%d", &kolejki) == 1)
	{
		printf("Ile scian i ile kosci?\n");
		scanf("%d %d", &kosci, &scianki);

		printf("Oto %d kolejek rzutow %d %d-sciennymi kostkami.\n", kolejki, kosci, scianki);
		for (int i = 0; i < kolejki; i++)
		{
			wynik = rzucaj_n_razy(kosci, scianki);
			printf("%d ", wynik);
		}

		printf("\nWprowadz liczbe kolejek; wybierz q, aby zakonczyc.\n");
	}

	return 0;
}