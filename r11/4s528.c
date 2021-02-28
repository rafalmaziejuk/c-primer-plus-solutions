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
	int i, flaga;

	flaga = i = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch == ' ' || ch == '	' || ch == '\n')
		{
			if (flaga)
				flaga = 0;
			else continue;
		}
		else 
		{	
			flaga = 1;

			tab[i] = ch;
			tab[i + 1] = '\0';

			i++;

			if (i == n - 1)
				break;
		}

		if (!flaga)
			break;
	}

	while (getchar() != '\n')
		continue;
}