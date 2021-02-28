#include <stdio.h>

int main(void)
{
	const int bajt = 8;
	float predkosc, rozmiar;

	printf("Podaj predkosc pobierania i rozmiar pliku:\n");
	scanf("%f %f", &predkosc, &rozmiar);

	float czas_pobierania = predkosc / bajt;

	printf("Przy %.2f megabitow na sekunde plik o rozmiarze %.2f megabajta\n", predkosc, rozmiar);
	printf("zostanie pobrany w %.2f sekundy.\n", rozmiar / czas_pobierania); 

	return 0;
}
