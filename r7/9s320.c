#include <stdio.h>

int main(void)
{
	int liczba;
	int licznik = 0;

	printf("Podaj dodatnia liczbe calkowita: ");
	scanf("%d", &liczba);

	for (int i = 2; i <= liczba; i++)
	{
		for (int j = 1; j <= i; j++)
			if (i % j == 0)
				licznik++;
				
		if (licznik < 3)
			printf("%d ", i);

		licznik = 0;
	}

	return 0;
}