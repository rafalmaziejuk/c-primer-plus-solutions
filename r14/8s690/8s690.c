#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define MAXMSC 12

struct Miejsce 
{                    
    int nr_id;
    int znacznik;
    char imie[MAX];
    char nazwisko[MAX];
};

char * wczytaj(char *z, int ile);
void menu(void);

int main(void)
{
	FILE * prezerwacje;
    struct Miejsce miejsca[MAXMSC];
    int koniec = 0;
    int licznik = 0;
    int rozmiar = sizeof(struct Miejsce);
    char opcja;

    if ((prezerwacje = fopen("rezerwacje.dat", "rb")) == NULL)
    {
    	fputs("Nie moge otworzyc pliku rezerwacje.dat\n",stderr);
        exit(1);
    }

    while (licznik < MAXMSC && fread(&miejsca[licznik], rozmiar, 1, prezerwacje) == 1)
	{
	   	if (licznik == 0)
	       puts("\nBiezaca zawartosc pliku rezerwacje.dat:");

	    if (miejsca[licznik].znacznik)
			printf("Miejsce numer %2d. jest zajete przez %-6s %-10s\n", miejsca[licznik].nr_id, miejsca[licznik].imie, miejsca[licznik].nazwisko);
		else printf("Miejsce numer %2d. jest wolne\n", miejsca[licznik].nr_id);

	    licznik++;
	}

	fclose(prezerwacje);

    menu();
    while (!koniec && scanf("%c", &opcja))
	{
		while (getchar() != '\n')
			continue;

    	switch(opcja)
    	{
    		case 'A':
    		case 'a':
    		{
    			int ilosc_pustych = 0;

    			for (int i = 0; i < licznik; i++)
    				if (!miejsca[i].znacznik)
    					ilosc_pustych++;

    			printf("\nIlosc pustych miejsc wynosci %d.\n", ilosc_pustych);

    			break;
    		}

    		case 'B':
    		case 'b':
    		{
    			putchar('\n');

    			for (int i = 0; i < licznik; i++)
    				if (!miejsca[i].znacznik)
    					printf("Miejsce numer %2d. jest wolne\n", miejsca[i].nr_id);		

    			break;
    		}

    		case 'C':
    		case 'c':
    		{
    			for (int i = 0; i < licznik; i++)
					if (miejsca[i].znacznik)
						printf("%s %s zajmuje miejsce numer %d.\n", miejsca[i].imie, miejsca[i].nazwisko, miejsca[i].nr_id);

    			break;
    		}

    		case 'D':
    		case 'd':
    		{
    			int index; 

    			printf("Podaj numer miejsca, ktore chcesz zarezerwowac: ");
    			scanf("%d", &index);

    			while (getchar() != '\n')
						continue;

				if (!miejsca[index].znacznik)
				{
					puts("Podaj imie: ");
				    if (wczytaj(miejsca[index].imie, MAX) != NULL && miejsca[index].imie[0] != '\0')
				    {
				        puts("Podaj nazwisko: ");
				        wczytaj(miejsca[index].nazwisko, MAX);

				        miejsca[index].znacznik = 1;  
				    }
				}
				else 
					printf("To miejsce jest juz zajete!\n");
    		
    			break;
    		}

    		case 'E':
    		case 'e':
    		{
    			int index; 

    			printf("Podaj numer miejsca, z ktorego chcesz usunac rezerwacje: ");
    			scanf("%d", &index);

    			while (getchar() != '\n')
						continue;

				if (miejsca[index].znacznik)
				{						   
					strcpy(miejsca[index].imie, "");
					strcpy(miejsca[index].nazwisko, "");
				    miejsca[index].znacznik = 0;
				}
				else 
					printf("To miejsce jest juz wolne!\n");

    			break;
    		}

    		case 'F':
    		case 'f':
    		{
    			koniec = 1;
    			break;
    		}

    		default: break;
    	}

    	if (!koniec)
    		menu();
    }

    if ((prezerwacje = fopen("rezerwacje.dat", "wb")) == NULL)
    {
    	fputs("Nie moge otworzyc pliku rezerwacje.dat\n", stderr);
        exit(1);
    }

    for (int i = 0; i < MAXMSC; i++)
    	fwrite(&miejsca[i], rozmiar, 1, prezerwacje);

    fclose(prezerwacje);

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
	puts("Aby wybrac opcje, wpisz jej oznaczenie literowe:");
	puts("a) Pokaz liczbe pustych miejsc");
	puts("b) Pokaz liste pustych miejsc");
	puts("c) Pokaz alfabetyczna liste miejsc");
	puts("d) Zarezerwuj miejsce dla klienta");
	puts("e) Usun rezerwacje miejsca");
	puts("f) Koniec");
}
