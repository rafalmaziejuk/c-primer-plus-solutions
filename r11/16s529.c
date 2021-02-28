#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ROZMIAR 50

int main(int argc, char *argv[])
{
	char tab[ROZMIAR];

	while (fgets(tab, ROZMIAR, stdin) != NULL)
	{
		int dlugosc = strlen(tab) - 1;
		tab[dlugosc] = '\0';

		if (argc == 1)
			puts(tab);
		else
		{
			if (!strcmp(argv[1], "-p"))
				puts(tab);
			else if (!strcmp(argv[1], "-u"))
			{
				for (int i = 0; i < dlugosc; i++)
					tab[i] = toupper(tab[i]);

				puts(tab);
			}
			else if (!strcmp(argv[1], "-l"))
			{
				for (int i = 0; i < dlugosc; i++)
					tab[i] = tolower(tab[i]);

				puts(tab);
			}
		}
	}

	return 0;
}