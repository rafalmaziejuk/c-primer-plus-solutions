#include <stdio.h>
#include <stdlib.h>

int * stworz_tablice(int elem, int wart);
void pokaz_tablice(const int tab[], int n);

int main(void)
{
	int *wt;
	int rozmiar;
	int wartosc;

	printf("Podaj liczbe elementow: ");
	while (scanf("%d", &rozmiar) == 1 && rozmiar > 0)
	{
		printf("Podaj wartosc poczatkowa: ");
		scanf("%d", &wartosc);

		wt = stworz_tablice(rozmiar, wartosc);

		if (wt)
		{
			pokaz_tablice(wt, rozmiar);
			free(wt);
		}

		printf("Podaj liczbe elementow (< 1 - koniec): ");
	}

	printf("Koniec.\n");

	return 0;
}

int * stworz_tablice(int elem, int wart)
{
	int *tab = (int *)malloc(elem * sizeof(int));

	for (int i = 0; i < elem; i++)
		tab[i] = wart;

	return tab;
}

void pokaz_tablice(const int tab[], int n)
{
	int licznik = 0;

	while (licznik++ < n)
	{
		printf("%d ", tab[licznik - 1]);

		if (licznik % 8 == 0)
			printf("\n");
	}			

	printf("\n");
}