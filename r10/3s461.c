#include <stdio.h>

int max(const int *poczatek, const int *koniec);

int main(void)
{
	int tab[] = {1 , 2, 5, 6, 4, 8, 10, 23, 50, 11, 80};

	printf("Max: %d\n", max(tab, tab + (sizeof(tab) / sizeof(int))));
	
	return 0;
}

int max(const int *poczatek, const int *koniec)
{
	int maksimum = *poczatek;

	while (poczatek < koniec)
	{
		if (maksimum < *poczatek)
			maksimum = *poczatek;

		poczatek++;
	}
	
	return maksimum;
}