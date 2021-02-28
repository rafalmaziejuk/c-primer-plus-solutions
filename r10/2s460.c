#include <stdio.h>

void kopiuj_tab(const double zr[], double cel[], int rozmiar);
void kopiuj_wsk(const double zr[], double cel[], int rozmiar);
void kopiuj_wsk2(const double *poczatek, double cel[], const double *koniec);
void wyswietl_tab(const double tab[], int rozmiar);

int main(void)
{
	double zrodlo[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double cel1[5];
	double cel2[5];
	
	printf("PIERWSZE KOPIOWANIE\n");
	kopiuj_tab(zrodlo, cel1, 5);
	wyswietl_tab(cel1, 5);

	printf("ZEROWANIE\n");
	for (int i = 0; i < 5; i++)
		cel1[i] = 0;

	wyswietl_tab(cel1, 5);

	printf("DRUGIE KOPIOWANIE\n");
	kopiuj_wsk(zrodlo, cel1, 5);
	wyswietl_tab(cel1, 5);

	printf("TRZECIE KOPIOWANIE\n");
	kopiuj_wsk2(zrodlo, cel2, zrodlo + 5);
	wyswietl_tab(cel2, 5);

	return 0;
}

void kopiuj_tab(const double zr[], double cel[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		cel[i] = zr[i];
}

void kopiuj_wsk(const double zr[], double cel[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		*(cel + i) = *(zr + i);
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

void wyswietl_tab(const double tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		printf("%.1f ", tab[i]);

	printf("\n\n");
}