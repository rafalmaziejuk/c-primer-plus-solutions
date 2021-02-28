#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXREJS 4
#define MAXMSC 12
#define MAX 20

struct Miejsce 
{                    
    int nr_id;
    int znacznik;
    int potwierdzenie;
    char imie[MAX];
    char nazwisko[MAX];
};

struct Rejs
{
	int numer;
	struct Miejsce miejsca[MAXMSC];
};

char * wczytaj(char *z, int ile);
void menu_nadrzedne(void);
void menu_podrzedne(void);

int main(void)
{
	FILE * prezerwacje;
	struct Rejs rejsy[4];
    int koniec_p = 0, koniec_n = 0;
    int licznik = 0;
    int rozmiar = sizeof(struct Rejs);
    char opcja;

    if ((prezerwacje = fopen("rezerwacje.dat", "rb")) == NULL)
    {
    	fputs("Nie moge otworzyc pliku rezerwacje.dat\n",stderr);
        exit(1);
    }

    while (licznik < MAXREJS && fread(&rejsy[licznik], rozmiar, 1, prezerwacje) == 1)
	{
	   	if (licznik == 0)
	       puts("\nBiezaca zawartosc pliku rezerwacje.dat:");

	   	printf("Rejs numer %d\n", rejsy[licznik].numer);

	   	for (int i = 0; i < MAXMSC; i++)
	   		if (rejsy[licznik].miejsca[i].znacznik)
	   			if (rejsy[licznik].miejsca[i].potwierdzenie)
					printf("Miejsce numer %2d. jest zarezerwowane i potwierdzone przez %-6s %-10s\n", rejsy[licznik].miejsca[i].nr_id, rejsy[licznik].miejsca[i].imie, rejsy[licznik].miejsca[i].nazwisko);
				else 
					printf("Miejsce numer %2d. jest zarezerwowane i niepotwierdzone przez %-6s %-10s\n", rejsy[licznik].miejsca[i].nr_id, rejsy[licznik].miejsca[i].imie, rejsy[licznik].miejsca[i].nazwisko);
			else printf("Miejsce numer %2d. jest wolne\n", rejsy[licznik].miejsca[i].nr_id);

		putchar('\n');

	    licznik++;
	}

	fclose(prezerwacje);

	menu_nadrzedne();
	while (scanf("%c", &opcja))
	{
		while (getchar() != '\n')
				continue;

		if (opcja == 'e')
			break;

		int index_rejsu;

		if (opcja == 'a') index_rejsu = 0;
		else if (opcja == 'b') index_rejsu = 1;
		else if (opcja == 'c') index_rejsu = 2;
		else if (opcja == 'd') index_rejsu = 3;

		menu_podrzedne();
	    while (!koniec_p && scanf("%c", &opcja))
		{
			while (getchar() != '\n')
				continue;

			system("clear");

			printf("Lot numer %d\n", rejsy[index_rejsu].numer);

	    	switch(opcja)
	    	{
	    		case 'A':
	    		case 'a':
	    		{
	    			int ilosc_pustych = 0;

	    			for (int i = 0; i < MAXMSC; i++)
	    				if (!rejsy[index_rejsu].miejsca[i].znacznik)
	    					ilosc_pustych++;

	    			printf("\nIlosc pustych miejsc wynosci %d.\n", ilosc_pustych);

	    			break;
	    		}

	    		case 'B':
	    		case 'b':
	    		{
	    			putchar('\n');

	    			for (int i = 0; i < MAXMSC; i++)
	    				if (!rejsy[index_rejsu].miejsca[i].znacznik)
	    					printf("Miejsce numer %2d. jest wolne\n", rejsy[index_rejsu].miejsca[i].nr_id);		

	    			break;
	    		}

	    		case 'C':
	    		case 'c':
	    		{
	    			for (int i = 0; i < MAXMSC; i++)
						if (rejsy[index_rejsu].miejsca[i].znacznik)
							if (rejsy[index_rejsu].miejsca[i].potwierdzenie)
								printf("%s %s zajmuje miejsce numer %d.\n", rejsy[index_rejsu].miejsca[i].imie, rejsy[index_rejsu].miejsca[i].nazwisko, rejsy[index_rejsu].miejsca[i].nr_id);
							else 
								printf("%s %s zarezerwowal miejsce %d lecz jeszcze nie potwierdzil.\n", rejsy[index_rejsu].miejsca[i].imie, rejsy[index_rejsu].miejsca[i].nazwisko, rejsy[index_rejsu].miejsca[i].nr_id);
						else 
							printf("Miejsce numer %d nie jest przez nikogo zarezerwowane.\n", rejsy[index_rejsu].miejsca[i].nr_id);

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

					if (!rejsy[index_rejsu].miejsca[index].znacznik)
					{
						puts("Podaj imie: ");
					    if (wczytaj(rejsy[index_rejsu].miejsca[index].imie, MAX) != NULL && rejsy[index_rejsu].miejsca[index].imie[0] != '\0')
					    {
					        puts("Podaj nazwisko: ");
					        wczytaj(rejsy[index_rejsu].miejsca[index].nazwisko, MAX);

					        rejsy[index_rejsu].miejsca[index].znacznik = 1;  
					        rejsy[index_rejsu].miejsca[index].potwierdzenie = 0;
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

					if (rejsy[index_rejsu].miejsca[index].znacznik)
					{						   
						strcpy(rejsy[index_rejsu].miejsca[index].imie, "");
						strcpy(rejsy[index_rejsu].miejsca[index].nazwisko, "");
					    rejsy[index_rejsu].miejsca[index].znacznik = 0;
					}
					else 
						printf("To miejsce jest juz wolne!\n");

	    			break;
	    		}

	    		case 'F':
	    		case 'f':
	    		{
	    			int index; 

	    			printf("Podaj numer miejsca, ktorego chcesz potwierdzic rezerwacje: ");
	    			scanf("%d", &index);

	    			while (getchar() != '\n')
							continue;

					if (!rejsy[index_rejsu].miejsca[index].znacznik)
					{
						printf("To miejsce nie jest zarezerwowane!\n");
						break;
					}

					rejsy[index_rejsu].miejsca[index].potwierdzenie = 1;

	    			break;
	    		}

	    		case 'G':
	    		case 'g':
	    		{
	    			koniec_p = 1;
	    			break;
	    		}

	    		default: break;
	    	}

	    	if (!koniec_p)
	    		menu_podrzedne();
	    }

	    koniec_p = 0;
	    system("clear");

	    menu_nadrzedne();
	}

    if ((prezerwacje = fopen("rezerwacje.dat", "wb")) == NULL)
    {
    	fputs("Nie moge otworzyc pliku rezerwacje.dat\n", stderr);
        exit(1);
    }

    for (int i = 0; i < MAXREJS; i++)
    	fwrite(&rejsy[i], rozmiar, 1, prezerwacje);

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

void menu_nadrzedne(void)
{
	putchar('\n');
	puts("Wybierz rejs lub zakoncz:");
	puts("a. Rejs 102");
	puts("b. Rejs 311");
	puts("c. Rejs 444");
	puts("d. Rejs 519");
	puts("e. Koniec");
}

void menu_podrzedne(void)
{
	putchar('\n');
	puts("Aby wybrac opcje, wpisz jej oznaczenie literowe:");
	puts("a) Pokaz liczbe pustych miejsc");
	puts("b) Pokaz liste pustych miejsc");
	puts("c) Pokaz alfabetyczna liste miejsc");
	puts("d) Zarezerwuj miejsce dla klienta");
	puts("e) Usun rezerwacje miejsca");
	puts("f) Potwierdz rezerwacje");
	puts("g) Powrot do menu glownego");
}
