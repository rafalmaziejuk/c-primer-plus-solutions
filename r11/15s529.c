#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ROZMIAR 10

int atoi(char *tab);

int main(void)
{
	char tab[ROZMIAR];

	fgets(tab, ROZMIAR, stdin);
	int dlugosc = strlen(tab) - 1;
	tab[dlugosc] = '\0';

	printf("Liczba wynosi: %d\n", atoi(tab));

	return 0;
}

int atoi(char *tab)
{
	int liczba = 0;
	int dziesiatki = 1;
	int dlugosc = strlen(tab) - 1;

	for (int i = 0; i < dlugosc; i++)
		dziesiatki *= 10;

	while (*tab != '\0')
	{
		int pom;

		if (!isdigit(*tab))
			return 0;
		else 
		{
			pom = *tab - '0';
			liczba += pom * dziesiatki;
			dziesiatki /= 10;
		}

		tab++;
	}

	return liczba;
}