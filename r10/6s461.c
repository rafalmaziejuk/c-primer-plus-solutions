#include <stdio.h>

void odwracanie(double tab[], double pom[], int rozmiar);
void wyswietl_tab(const double tab[], int rozmiar);

int main(void)
{
	double tab[] = { 1.1, 2.2, 5.5, 6.6, 4.4, 8.8, 10.1, 23.2, 50.5, 11.1, 80.8 };
	double pom[sizeof(tab) / sizeof(double)];

	printf("PRZED ODWROCENIEM\n");
	wyswietl_tab(tab, sizeof(tab) / sizeof(double));

	odwracanie(tab, pom, sizeof(tab) / sizeof(double));

	printf("\nPO ODWROCENIU\n");
	wyswietl_tab(tab, sizeof(tab) / sizeof(double));
	
	return 0;
}

void odwracanie(double tab[], double pom[], int rozmiar)
{
	int indeks = rozmiar - 1;

	for (int i = 0; i < rozmiar; i++)
	{
		pom[i] = tab[indeks];
		indeks--;
	}

	for (int i = 0; i < rozmiar; i++)
		tab[i] = pom[i];
}

void wyswietl_tab(const double tab[], int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		printf("%.1f ", tab[i]);

	printf("\n");
}
