#include <stdio.h>

int roznica_minmax(const int *poczatek, const int *koniec);

int main(void)
{
	int tab[] = { 1, 2, 5, 6, 4, 8, 10, 23, 50, 11, 80 };

	printf("Roznica: %d\n", roznica_minmax(tab, tab + (sizeof(tab) / sizeof(int))));

	return 0;
}

int roznica_minmax(const int *poczatek, const int *koniec)
{
	int maksimum, minimum;

	maksimum = minimum = *poczatek;

	while (poczatek < koniec)
	{
		if (maksimum < *poczatek)
			maksimum = *poczatek;
		else if (minimum > *poczatek)
			minimum = *poczatek;

		poczatek++;
	}

	return maksimum - minimum;
}