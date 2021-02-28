#include <stdio.h>

#define WIERSZ 3
#define KOLUMNA 11

void kopiuj_wsk2(const double *poczatek, double cel[], const double *koniec);
void wyswietl_tab(const double *poczatek, const double *koniec);

int main(void)
{
	double tab[WIERSZ][KOLUMNA] = 
	{
		{ 1.1, 2.2, 5.5, 6.6, 4.4, 8.8, 10.1, 23.2, 50.5, 11.1, 80.8 },
		{ 81.1, 72.2, 35.5, 56.6, 44.4, 8.8, 910.1, 23.2, 50.5, 811.1, 180.8 },
		{ 3.1, 4.2, 55.5, 66.6, 45.4, 88.8, 10.1, 23.2, 50.5, 511.1, 480.8 }
	};
	double cel[WIERSZ][KOLUMNA];

	printf("TABLICA ZRODLOWA\n");
	for (int i = 0; i < WIERSZ; i++)
		wyswietl_tab(*(tab + i), *(tab + i) + KOLUMNA);

	for (int i = 0; i < WIERSZ; i++)
		kopiuj_wsk2(*(tab + i), *(cel + i), *(tab + i) + KOLUMNA);

	printf("\nTABLICA DOCELOWA\n");
	for (int i = 0; i < WIERSZ; i++)
		wyswietl_tab(*(cel + i), *(cel + i) + KOLUMNA);
		
	return 0;
}

void kopiuj_wsk2(const double *poczatek, double cel[], const double *koniec)
{
	int i = 0;

	while (poczatek < koniec)
	{
		cel[i] = *(poczatek);

		poczatek++;
		i++;
	}
}

void wyswietl_tab(const double *poczatek, const double *koniec)
{
	while (poczatek < koniec)
	{
		printf("%.1f ", *poczatek);
		poczatek++;
	}

	printf("\n");
}
