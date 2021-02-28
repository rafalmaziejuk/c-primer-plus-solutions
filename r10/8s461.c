#include <stdio.h>

void kopiuj_wsk2(const double *poczatek, double cel[], const double *koniec);
void wyswietl_tab(const double *poczatek, const double *koniec);

int main(void)
{
	double tab[7] = { 1.1, 2.2, 5.5, 6.6, 4.4, 8.8, 10.1};
	double cel[3];

	printf("TABLICA ZRODLOWA\n");
	wyswietl_tab(tab, tab + 7);

	kopiuj_wsk2(tab + 2, cel, tab + 5);

	printf("\nTABLICA DOCELOWA\n");
	wyswietl_tab(cel, cel + 3);
		
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