#include <stdio.h>

#define WIERSZ 3
#define KOLUMNA 5

float podpunkt_b(const double *tab, int rozmiar);
float podpunkt_c(const double tab[][KOLUMNA], int wiersz);
float podpunkt_d(const double tab[][KOLUMNA], int wiersz);

int main(void)
{
	double tab[WIERSZ][KOLUMNA];

	for (int i = 0; i < WIERSZ; i++)
		for (int j = 0; j < KOLUMNA; j++)
			tab[i][j] = i + j * 0.1;

	printf("TABLICA\n");
	for (int i = 0; i < WIERSZ; i++)
	{
		printf("%d: ", i + 1);

		for (int j = 0; j < KOLUMNA; j++)
			printf("%.1f ", tab[i][j]);

		putchar('\n');
	}
		
	putchar('\n');
		
	printf("PODPUNKT B\n");
	for (int i = 0; i < WIERSZ; i++)
		printf("Srednia z %d zbioru: %.1f\n", i + 1, podpunkt_b(*(tab + i), KOLUMNA));
	putchar('\n');

	printf("PODPUNKT C\n");
	printf("Srednia z calosci: %.1f\n", podpunkt_c(tab, WIERSZ));
	putchar('\n');

	printf("PODPUNKT D\n");
	printf("Najwieksz wartosc: %.1f\n", podpunkt_d(tab, WIERSZ));
	putchar('\n');

	return 0;
}

float podpunkt_b(const double *tab, int rozmiar)
{
	float suma = 0;

	for (int i = 0; i < rozmiar; i++)
		suma += tab[i];

	return suma / rozmiar;
}

float podpunkt_c(const double tab[][KOLUMNA], int wiersz)
{
	float suma = 0;

	for (int i = 0; i < wiersz; i++)
		for (int j = 0; j < KOLUMNA; j++)
			suma += tab[i][j];

	return suma / (wiersz * KOLUMNA);
}

float podpunkt_d(const double tab[][KOLUMNA], int wiersz)
{
	float max = tab[0][0];

	for (int i = 0; i < wiersz; i++)
		for (int j = 0; j < KOLUMNA; j++)
			if (max < tab[i][j])
				max = tab[i][j];
	
	return max;
}
