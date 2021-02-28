#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drzewo.h"

void menu(void);
void wyswietl(Pozycja pozycja);

int main(void)
{
	FILE *plik;
	
	if ((plik = fopen("slowa.txt", "r")) == NULL)
	{
		fprintf(stderr, "Nie udalo sie otworzyc pliku!\n");
		exit(EXIT_FAILURE);
	}

	Drzewo drzewo;
	Pozycja tymcz;
	int opcja;
	char slowo[MAXSLOWO];

	InicjujDrzewo(&drzewo);

	while (fgets(slowo, MAXSLOWO, plik))
	{
		slowo[strlen(slowo) - 1] = '\0';
		strcpy(tymcz.slowo, slowo);

		tymcz.liczba_wystapien = 1;

		DodajPozycje(&tymcz, &drzewo);
	}
		
	menu();
	while (scanf("%d", &opcja))
	{
		while (getchar() != '\n')
			continue;

		switch(opcja)
		{
			case 1:
			{
				Przejdz(&drzewo, wyswietl);
				break;
			}

			case 2:
			{
				printf("Podaj slowo: ");
				scanf("%s", slowo);

				while (getchar() != '\n')
					continue;

				strcpy(tymcz.slowo, slowo);

				if (WDrzewie(&tymcz, &drzewo))
					printf("\n%s wystepuje w pliku %d razy!\n\n", slowo, LiczbaWystapien(&tymcz, &drzewo));
				else 
					printf("\n%s nie wystepuje w pliku ani razu!\n\n", slowo);

				break;
			}

			case 3:
			{
				exit(EXIT_SUCCESS);
				break;
			}

			default: continue;
		}

		menu();
	}
	
	UsunWszystko(&drzewo);
   	fclose(plik);

	return 0;
}

void menu(void)
{
	puts("1. Wyswietl liste wszystkich slow i liczbe ich wystapien.");
	puts("2. Wyswietl liczbe wystapien wybranego slowa.");
	puts("3. Zakoncz.");
	printf("Wybierz opcje: ");
}

void wyswietl(Pozycja pozycja)
{
	printf("\nSlowo: %s\n", pozycja.slowo);
	printf("Liczba wystapien: %d\n\n", pozycja.liczba_wystapien);
}
