#include <stdio.h>

#define ROZMIAR 20

void wczytaj(char tab[], unsigned int n);

int main(void)
{
	char tab[ROZMIAR];

	wczytaj(tab, ROZMIAR);

	fputs(tab, stdout);

	return 0;
}

void wczytaj(char tab[], unsigned int n)
{
	char ch;

	for (int i = 0; i < n - 1; i++)
		if ((ch = getchar()) != EOF)
			tab[i] = ch;

	tab[n - 1] = '\0';		

	while (getchar() != '\n')
		continue;
}