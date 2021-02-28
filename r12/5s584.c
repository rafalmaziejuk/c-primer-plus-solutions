#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 100

void generator(int tab[], unsigned int rozmiar);
void sortuj(int tab[], unsigned int rozmiar);
void wyswietl(const int tab[], unsigned int rozmiar);

int main(void)
{
	int tab[ROZMIAR];

	generator(tab, ROZMIAR);
	sortuj(tab, ROZMIAR);
	wyswietl(tab, ROZMIAR);

	return 0;
}

void generator(int tab[], unsigned int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		int liczba = rand() % 10 + 1;
		tab[i] = liczba;
	}
}

void sortuj(int tab[], unsigned int rozmiar)
{
	int pom;

	for (int i = 0; i < rozmiar; i++)
		for (int j = 1; j < rozmiar - i; j++)
			if(tab[j - 1] < tab[j])
			{
				pom = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = pom;
			}
}

void wyswietl(const int tab[], unsigned int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
		if (i % 10 != 0)
			printf("%2d ", tab[i]);
		else printf("\n");

	printf("\n\n");
}