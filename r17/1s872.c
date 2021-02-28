#include <stdio.h>
#include <stdlib.h>    
#include <string.h>      

#define ROZT 45      

struct film 
{
	char tytul[ROZT];
	int ocena;
	struct film *nast;   
	struct film *poprz;
};

char *wczytaj(char *z, int ile);

int main(void)
{
	struct film *glowny = NULL;
	struct film *poprz = NULL, *biezacy;
	char wejscie[ROZT];

	puts("Podaj pierwszy tytul filmu:");
	while (wczytaj(wejscie, ROZT) != NULL && wejscie[0] != '\0')
	{
		biezacy = (struct film *)malloc(sizeof(struct film));

		if (glowny == NULL)   
		{
			glowny = biezacy;
			glowny->poprz = NULL;
		}    
		else                        
			poprz->nast = biezacy;

		biezacy->nast = NULL;
		biezacy->poprz = poprz;

		strcpy(biezacy->tytul, wejscie);

		puts("Podaj Twoja ocene <0-10>:");
		scanf("%d", &biezacy->ocena);

		while (getchar() != '\n')
			continue;

		poprz = biezacy;

		puts("Podaj nastepny tytul filmu (pusty wiersz konczy program):");
	}

	if (glowny == NULL)
		printf("Nie wpisano zadnych danych. ");
	else
		printf ("Oto lista filmow rosnaco:\n");

	biezacy = glowny;

	while (biezacy != NULL)
	{
		printf("Film: %s  Ocena: %d\n", biezacy->tytul, biezacy->ocena);
		
		if (biezacy->nast == NULL)
			break;
		
		biezacy = biezacy->nast;
	}

	printf ("Oto lista filmow malejaco:\n");
	while (biezacy != NULL)
	{
		printf("Film: %s  Ocena: %d\n", biezacy->tytul, biezacy->ocena);
		biezacy = biezacy->poprz;
	}

	biezacy = glowny;

	while (biezacy != NULL)
	{
		poprz = biezacy; 
		biezacy = poprz->nast;
		free(poprz);
	}

	printf("Do widzenia!\n");

	return 0;
}

char *wczytaj(char *z, int ile)
{
	char * wynik;
	char * tutaj;

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