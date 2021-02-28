#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define DL 50

int main(int argc, char *argv[])
{
    FILE  *plik1, *plik2;     
    int ch;
    char wiersz[DL];
    long koniec_plik1, koniec_plik2;

    if ((plik1 = fopen(argv[1], "r")) == NULL || (plik2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Nie moglem otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }

    fseek(plik1, 0L, SEEK_END);
    koniec_plik1 = ftell(plik1);

    fseek(plik2, 0L, SEEK_END);
    koniec_plik2 = ftell(plik2);

    fseek(plik1, 0L, SEEK_SET);
    fseek(plik2, 0L, SEEK_SET);

    if (koniec_plik1 > koniec_plik2)
    {
    	while (fgets(wiersz, DL, plik1))
	    {
	    	fputs(wiersz, stdout);

	        if (fgets(wiersz, DL, plik2))
	        	fputs(wiersz, stdout);
	    }
    }
    else 
    {
    	while (fgets(wiersz, DL, plik2))
	    {
	    	fputs(wiersz, stdout);

	        if (fgets(wiersz, DL, plik1))
	        	fputs(wiersz, stdout);
	    }
    }

    if (fclose(plik1) != 0 || fclose(plik2) != 0)
        fprintf(stderr,"Blad przy zamykaniu plikow.\n");

    return 0;
}