#include <stdio.h>

#define ROZMIAR 20

int znajduje_sie_w(char ch, char *tab);

int main(void)
{
	char tab[ROZMIAR];
	char *adres;

	puts("Wprowadz lancuch znakow: ");
	while (fgets(tab, ROZMIAR, stdin) != NULL && tab[0] != '\n')
	{
		puts("Wprowadz znak, ktory chcesz znalezc w lancuchu: ");
		char ch = getchar();

		if (znajduje_sie_w(ch, tab))
			printf("Znaleziono \'%c\' w podanym lancuchu pod adresem.\n", ch);
		else printf("Nie znaleziono \'%c\' w podanym lancuchu.\n", ch);
	}

	return 0;
}

int znajduje_sie_w(char ch, char *tab)
{
	while (*tab != '\0')
	{
		if (*tab == ch)
			return 1;

		tab++;
	}
		
	return 0;
}