#include <stdio.h>

int main(void)
{
	int liczba;
	int ilosc_parzyste, ilosc_nieparzyste;
	int suma_parzyste, suma_nieparzyste;

	ilosc_parzyste = ilosc_nieparzyste = suma_parzyste = suma_nieparzyste = 0;

	while (scanf("%d", &liczba) == 1)
	{
		if (liczba == 0)
			break;

		if (liczba % 2 == 0)
		{
			ilosc_parzyste++;
			suma_parzyste += liczba;
		}
		else
		{
			ilosc_nieparzyste++;
			suma_nieparzyste += liczba;
		}
	}

	if (ilosc_parzyste != 0)
		printf("Ilosc parzystych: %d Wartosc srednia: %.2f\n", ilosc_parzyste, float(suma_parzyste / ilosc_parzyste));

	if (ilosc_nieparzyste != 0)
	printf("Ilosc nieparzystych: %d Wartosc srednia: %.2f\n", ilosc_nieparzyste, float(suma_nieparzyste / ilosc_nieparzyste));

	return 0;
}
