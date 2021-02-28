#include <stdio.h>
#include <string.h>
#include "plik.h"

#define MIESIACE 12

struct Miesiac miesiace[MIESIACE] = 
    {
    	{ "Styczen", "Sty", 31, 1 },
    	{ "Luty", "Lut", 28, 2 },
    	{ "Marzec", "Mar", 31, 3 },
    	{ "Kwiecien", "Kwi", 30, 4 },
    	{ "Maj", "Maj", 31, 5 },
    	{ "Czerwiec", "Cze", 30, 6 },
    	{ "Lipiec", "Lip", 31, 7 },
    	{ "Sierpien", "Sie", 31, 8 },
    	{ "Wrzesien", "Wrz", 30, 9 },
    	{ "Pazdziernik", "Paz", 31, 10 },
    	{ "Listopad", "Lis", 30, 11 },
    	{ "Grudzien", "Gru", 31, 12 }
    };

int dni_od_poczatku(const char nazwa[]);

int main(void)
{
	char nazwa_miesiaca[15];

	printf("Podaj nazwe miesiaca: ");
	scanf("%15s", nazwa_miesiaca);

    printf("Ilosc dni od poczatku roku do miesiaca %s to %d.\n", nazwa_miesiaca, dni_od_poczatku(nazwa_miesiaca));

    return 0;
}

int dni_od_poczatku(const char nazwa[])
{
	unsigned int suma = 0;
	unsigned int licznik = 0;

	for (int i = 0; i < MIESIACE; i++)
	{
		licznik++;

		if (strcmp(miesiace[i].nazwa, nazwa) == 0)
			break;
	}

	for (int i = 0; i < licznik; i++)
		suma += miesiace[i].liczba_dni;

	return suma;
}