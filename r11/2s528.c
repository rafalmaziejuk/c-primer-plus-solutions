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
			if (ch != '\n' && ch != ' ' && ch != '	')
			{
				tab[i + 1] = '\0';
				tab[i] = ch;
			}
			else
			{
				tab[i + 1] = '\0';
				break;
			}
			

	while (getchar() != '\n')
		continue;
}