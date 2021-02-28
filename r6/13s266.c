#include <stdio.h>

int main(void)
{
	int tablica[8];
	int pom;
	int i;

	for (i = 0, pom = 1; i < 8; i++, pom *= 2)
		tablica[i] = pom;

	i = 0;

	do
	{
		printf("%d: %d\n", i + 1, tablica[i]);
		i++;
	} while (i + 1 <= 8);

	return 0;
}
