#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTYT 40
#define MAXAUT 40
#define MAXKS 10    

struct ksiazka 
{                    
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
    int zapis;
};    

char * wczytaj(char *z, int ile);
void menu(void);

int main(void)
{
	FILE * pksiazki;
    struct ksiazka bibl[MAXKS];
    int licznik = 0;
    int rozmiar = sizeof(struct ksiazka);
    int opcja;

    if ((pksiazki = fopen("ksiazki.dat", "rb")) == NULL)
    {
        fputs("Nie moge otworzyc pliku ksiazki.dat\n",stderr);
        exit(1);
    }

    while (licznik < MAXKS && fread(&bibl[licznik], rozmiar, 1, pksiazki) == 1)
	{
	   	if (licznik == 0)
	       puts("Biezaca zawartosc pliku ksiazki.dat:");

	    printf("%d. %s by %s: %.2f zl\n", licznik + 1, bibl[licznik].tytul, bibl[licznik].autor, bibl[licznik].wartosc);

	    bibl[licznik].zapis = 1;

	    licznik++;
	}

	fclose(pksiazki);

    if (licznik == MAXKS)
    {
        fputs("Plik ksiazki.dat jest pelny.", stderr);
        exit(2);
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
    			if (licznik == MAXKS)
    			{
			    	puts("Plik ksiazki.dat jest pelny.");
			    	break;
    			}

    			puts("Podaj nowy tytul ksiazki.");
			    if (licznik < MAXKS && wczytaj(bibl[licznik].tytul, MAXTYT) != NULL && bibl[licznik].tytul[0] != '\0')
			    {
			        puts("Teraz podaj autora.");
			        wczytaj(bibl[licznik].autor, MAXAUT);
			        puts("Teraz podaj wartosc.");
			        scanf("%f", &bibl[licznik].wartosc);

			        bibl[licznik].zapis = 1;

			        licznik++;

			        while (getchar() != '\n')
			            continue;    
			    }

    			break;
    		}

    		case 2:
    		{
    			if (licznik > 0)
    			{
    				int index;

    				printf("Ktora ksiazke chcesz wymazac?\n");
	    			printf("Podaj numer ksiazki: ");
	    			scanf("%d", &index);
	    			index--;

	    			while (getchar() != '\n')
						continue;

					if (index != licznik)
					{
						for (int i = index; i < licznik - 1; i++)
							bibl[i] = bibl[i + 1];
					}
					else 
						bibl[index].zapis = 0;

					licznik--;
    			}	

    			break;
    		}

    		case 3:
    		{
    			if (licznik > 0)
    			{
    				int index;

    				printf("Ktora ksiazke chcesz zmodyfikowac?\n");
	    			printf("Podaj numer ksiazki: ");
	    			scanf("%d", &index);
	    			index--;

	    			while (getchar() != '\n')
						continue;

					puts("Podaj nowy tytul ksiazki.");
				    if (wczytaj(bibl[index].tytul, MAXTYT) != NULL)
				    {
				        puts("Teraz podaj autora.");
				        wczytaj(bibl[index].autor, MAXAUT);
				        puts("Teraz podaj wartosc.");
				        scanf("%f", &bibl[index].wartosc);

				        while (getchar() != '\n')
				            continue;    
				    }
				}

    			break;
    		}

    		default: break;
    	}

    	if (licznik > 0)
	    {
	    	putchar('\n');
	        puts("Oto lista Twoich ksiazek:");
	        for (int i = 0; i < licznik; i++)
	        	if (bibl[i].zapis)
	            	printf("%d. %s, autor: %s, cena: %.2f zl\n", i + 1, bibl[i].tytul, bibl[i].autor, bibl[i].wartosc);
	    }
	    else
	        puts("\nZadnych ksiazek? Szkoda");

    	menu();
    }

    if ((pksiazki = fopen("ksiazki.dat", "wb")) == NULL)
    {
    	fputs("Nie moge otworzyc pliku ksiazki.dat\n",stderr);
        exit(1);
    }

    for (int i = 0; i < licznik; i++)
    	if (bibl[i].zapis)
    		fwrite(&bibl[i], rozmiar, 1, pksiazki);

    puts("Koniec.\n");

    fclose(pksiazki);

    return 0;
}

char * wczytaj(char *z, int ile)
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

void menu(void)
{
	putchar('\n');
	puts("1. Dodaj nowa poyzcje.");
	puts("2. Usun wybrana pozycje.");
	puts("3. Zmodyfikuj wybrana pozycje");
	printf("Wybierz opcje (wprowadzenie znaku konczy): ");
}
