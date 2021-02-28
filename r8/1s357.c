#include <stdio.h>

int main(void)
{
	int ch;
	int licznik = 0;

	while ((ch = getchar()) != EOF)
		if (ch != ' ' && ch != '\n')
			licznik++;

	printf("Ilosc znakow: %d\n", licznik);

	return 0;
}