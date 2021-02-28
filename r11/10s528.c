#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ROZMIAR 20

void usun_odstepy(char tab[]);

int main(void)
{
	char tab[ROZMIAR];

	puts("Podaj lancuch: ");
	while (fgets(tab, ROZMIAR, stdin) != NULL && *tab != '\n')
	{
		usun_odstepy(tab);

		printf("Lancuch po usunieciu spacji: %s\n", tab);

		puts("Podaj lancuch: ");
	}

	return 0;
}

void usun_odstepy(char tab[])
{
	int dlugosc = strlen(tab);
	int licznik = 0;

	for (int i = 0; i < dlugosc; i++)
		if (!isspace(tab[i]))
			licznik++;

	char pom[licznik];

	for (int i = 0, j = 0; i < dlugosc; i++)
		if (!isspace(tab[i]))
		{
			if (j == licznik)
				break;

			pom[j] = tab[i];
			j++;
		}

	for (int i = 0; i < licznik; i++)
		tab[i] = pom[i];

	tab[licznik] = '\0';
}