#include <stdio.h>
#include <stdlib.h>

#define ROZMIAR 10

void generator(unsigned int ziarno);

int main(void)
{
	for (int i = 1; i <= ROZMIAR; i++)
		generator(i);

	return 0;
}

void generator(unsigned int ziarno)
{
	int ilosci[ROZMIAR];

	for (int i = 0; i < ROZMIAR; i++)
		ilosci[i] = 0;

	srand(ziarno);

	printf("%d ITERACJA\n", ziarno);

	for (int i = 0; i < 1000; i++)
	{
		int liczba = rand() % 10 + 1;
		ilosci[liczba - 1]++;
	}

	for (int i = 0; i < ROZMIAR; i++)
		printf("%d: %d\n", i + 1, ilosci[i]);

	putchar('\n');
}