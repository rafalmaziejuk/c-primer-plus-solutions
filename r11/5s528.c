#include <stdio.h>

#define ROZMIAR 20

char * wyszukaj(char *tab, char ch);

int main(void)
{
	char tab[ROZMIAR];
	char *adres;

	puts("Wprowadz lancuch znakow: ");
	while (fgets(tab, ROZMIAR, stdin) != NULL && tab[0] != '\n')
	{
		puts("Wprowadz znak, ktory chcesz znalezc w lancuchu: ");
		char ch = getchar();

		adres = wyszukaj(tab, ch);

		if (adres != NULL)
			printf("Znaleziono \'%c\' w podanym lancuchu pod adresem %p.\n", ch, adres);
		else printf("Nie znaleziono \'%c\' w podanym lancuchu.\n", ch);
	}

	return 0;
}

char * wyszukaj(char *tab, char ch)
{
	while (*tab != '\0')
	{
		if (*tab == ch)
			return tab;

		tab++;
	}
		
	return NULL;
}