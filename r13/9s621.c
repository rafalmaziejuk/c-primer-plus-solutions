#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE *wp;
    char slowa[MAX];
    int licznik = 1;
    long koniec;

    if ((wp = fopen("slowka", "a+")) == NULL)
    {
        fprintf(stdin, "Nie moge otworzyc pliku \"slowka\".\n");
        exit(EXIT_FAILURE);
    }

    fseek(wp, 0L, SEEK_END);
    koniec = ftell(wp);

    if (koniec > 0)
    {
    	fseek(wp, -2L, SEEK_END);
    	licznik = getc(wp) - '0';

    	printf("%d\n\n", licznik);

    	puts("Podaj slowa, ktore maja zostac dodane do pliku;");
	    puts("Aby zakonczyc, wpisz #.");
	    while ((fscanf(stdin, "%40s", slowa) == 1) && (slowa[0] != '#'))
	    {
	        fprintf(wp, "%s ", slowa);

	        licznik++;
	        fprintf(wp, "%d ", licznik);
	    }
    }
    else 
    {
    	puts("Podaj slowa, ktore maja zostac dodane do pliku;");
	    puts("Aby zakonczyc, wpisz #.");
	    while (fprintf(wp, "%d ", licznik) && (fscanf(stdin, "%40s", slowa) == 1) && (slowa[0] != '#'))
	    {
	        fprintf(wp, "%s ", slowa);
	        licznik++;
	    }
    }
   	
    rewind(wp); 

    puts("Zawartosc pliku:");
    while (fscanf(wp,"%d %s", &licznik, slowa) == 2)
    {
    	printf("%d ", licznik);
        puts(slowa);
    }

    if (fclose(wp) != 0)
        fprintf(stderr,"Blad przy zamykaniu pliku.\n");

    puts("Gotowe!\n");

    return 0;
}