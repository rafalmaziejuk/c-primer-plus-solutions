#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include "lista.h"     

void pokazfilm(Pozycja pozycja);
char * wczytaj(char *z, int ile);

int main(void)
{
	Lista filmy;
	Pozycja tymcz;
   
	InicjujListe(&filmy);

	if (PelnaLista(&filmy))
	{
		fprintf(stderr,"Brak pamieci! Do widzenia!\n");
		exit(1);
	}
   
	puts("Podaj pierwszy tytul filmu:");
	while (wczytaj(tymcz.tytul, ROZT) != NULL && tymcz.tytul[0] != '\0')
	{
		puts("Podaj Twoja ocene <0-10>:");
		scanf("%d", &tymcz.ocena);

		while(getchar() != '\n')
			continue;

		if (DodajPozycje(tymcz, &filmy)== false)
		{
			fprintf(stderr,"Blad alokacji pamieci.\n");
			break;
		}

		if (PelnaLista(&filmy))
		{
			puts("Lista jest juz pelna.");
			break;
		}

		puts("Podaj nastepny tytul filmu (pusty wiersz konczy wpisywanie):");
	}
   
	if (PustaLista(&filmy))
		printf("Nie wpisano zadnych danych.\n");
	else
	{
		printf ("Oto lista filmow:\n");
		Przejdz(&filmy, pokazfilm);
	}

	printf("Wpisales %d filmow.\n", LiczbaPozycji(&filmy));

	CzyscListe(&filmy);

	printf("Do widzenia!\n");

	return 0;
}

void pokazfilm(Pozycja pozycja)
{
	printf("Film: %s  Ocena: %d\n", pozycja.tytul, pozycja.ocena);
}

char * wczytaj(char *z, int ile)
{
	char *wynik;
	char *tutaj;

	wynik = fgets(z, ile, stdin);

	if (wynik)
	{
        tutaj = strchr(z, '\n'); 
        if (tutaj) 
            *tutaj = '\0'; 
        else
        	while (getchar() != '\n')
        		continue;
    }

        return wynik;
}