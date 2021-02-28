#include <stdio.h>
#include "plik.h"

#define ROZMIAR 4

void pokaz(const struct student s[], int n);

int main(void)
{
	float suma = 0;
    	struct student tab[ROZMIAR] = 
	{
		{ { "imie1", "nazwisko1"} },
		{ { "imie2", "nazwisko2"} },
		{ { "imie3", "nazwisko3"} },
		{ { "imie4", "nazwisko4"} }
	};
	
	for (int i = 0; i < ROZMIAR; i++)
	{
		printf("Wprowadz oceny %s: ", tab[i].dane.imie);
		for (int j = 0; j < 5; j++)
			scanf("%f", &tab[i].oceny[j]);

		for (int j = 0; j < 5; j++)
			suma += tab[i].oceny[j];

		tab[i].srednia_ocen = suma / 5;

		suma = 0;
	}

	pokaz(tab, ROZMIAR);

	for (int i = 0; i < ROZMIAR; i++)
		suma += tab[i].srednia_ocen;
	
	printf("Srednia ocen wszystkich studentow: %.2f\n", suma / ROZMIAR);

	return 0;
}

void pokaz(const struct student s[], int n)
{
	for (int i = 0; i < ROZMIAR; i++)
	{
		printf("%s %s\n", s[i].dane.imie, s[i].dane.nazwisko);

		printf("Oceny: ");
		for (int j = 0; j < 5; j++)
			printf("%.1f ", s[i].oceny[j]);

		printf("\nSrednia ocen: %.2f\n\n", s[i].srednia_ocen);
	}
}