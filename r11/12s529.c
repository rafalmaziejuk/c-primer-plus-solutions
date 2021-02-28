#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ROZMIAR 50

int main(void)
{
	char tab[ROZMIAR];

	while (fgets(tab, ROZMIAR, stdin) != NULL)
	{
		int dlugosc = strlen(tab);
		tab[dlugosc - 1] = '\0';

		int slowa, male, wielkie, znaki_przestankowe, cyfry;
		int flaga;

		slowa = male = wielkie = znaki_przestankowe = cyfry = flaga = 0;

		for (int i = 0; i < dlugosc; i++)
		{
			if (islower(tab[i]))
				male++;
			else if (isupper(tab[i]))
				wielkie++;
			else if (isdigit(tab[i]))
				cyfry++;
			else if (ispunct(tab[i]))
				znaki_przestankowe++;
			
			if (isalpha(tab[i]))
				if (isspace(tab[i + 1]) || ispunct(tab[i + 1]))
					slowa++;
		}
			
		printf("Slow: %d\nMalych liter: %d\nWielkich liter: %d\nZnakow przestanowych: %d\nCyfr: %d\n", slowa, male, wielkie, znaki_przestankowe, cyfry);
	}

	return 0;
}