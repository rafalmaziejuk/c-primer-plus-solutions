#include <stdio.h>

int main(void)
{
	char ch;
	int odstepy, nowe_linie, inne_znaki;

	odstepy = nowe_linie = inne_znaki = 0;

	while (scanf("%c", &ch) == 1)
	{
		if (ch == '#')
			break;

		if (ch == ' ')
			odstepy++;
		else if (ch == '\n')
			nowe_linie++;
		else 
			inne_znaki++;
	}

	printf("Odstepow: %d\nNowych linii: %d\nInnych_znakow: %d\n", odstepy, nowe_linie, inne_znaki);

	return 0;
}
