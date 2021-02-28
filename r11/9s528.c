#include <stdio.h>
#include <string.h>

#define ROZMIAR 20

void odwroc(char tab[]);

int main(void)
{
	char tab[ROZMIAR];

	puts("Podaj lancuch do odwrocenia: ");
	while (fgets(tab, ROZMIAR, stdin) != NULL && *tab != '\n')
	{
		odwroc(tab);

		printf("Odwrocony lancuch: %s\n", tab);

		puts("Podaj lancuch do odwrocenia: ");
	}

	return 0;
}

void odwroc(char tab[])
{
	int dlugosc = strlen(tab);
	char pom[dlugosc];

	for (int i = 0, j = dlugosc - 1; i < dlugosc; i++, j--)
		pom[i] = tab[j];

	for (int i = 0; i < dlugosc; i++)
		tab[i] = pom[i];

	tab[dlugosc] = '\0';
}