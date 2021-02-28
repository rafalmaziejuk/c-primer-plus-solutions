#include <stdio.h>

#define GODZINA 60

int main(void)
{
	int liczba;
	int	godziny, minuty;

	printf("Podaj ilosc minut:\n");
	scanf("%d", &liczba);

	while (liczba > 0)
	{
		godziny = liczba / GODZINA;
		liczba -= godziny * GODZINA;
		minuty = liczba;

		printf("Godzin: %d\nMinut: %d\n", godziny, minuty);

		printf("Podaj ilosc minut: \n");
		scanf("%d", &liczba);
	}

	return 0;
}
