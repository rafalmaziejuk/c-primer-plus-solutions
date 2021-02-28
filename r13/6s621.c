#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define DL 40 

int main(void)
{
    FILE  *we, *wy;     
    int ch;
    char nazwa[DL];     
    char nazwa_zrodlo[DL];
    int licznik = 0;

    printf("Podaj nazwe pliku do zredukowania: ");
    scanf("%40s", nazwa_zrodlo);

    if ((we = fopen(nazwa_zrodlo, "r")) == NULL)
    {
        fprintf(stderr, "Nie moglem otworzyc pliku \"%s\".\n", nazwa_zrodlo);
        exit(EXIT_FAILURE);
    }

    strncpy(nazwa, nazwa_zrodlo, DL - 5); 
    nazwa[DL - 5] = '\0';
    strcat(nazwa, ".red");    

    if ((wy = fopen(nazwa, "w")) == NULL)
    {                        
        fprintf(stderr,"Nie mozna utworzyc pliku wyjsciowego.\n");
        exit(EXIT_FAILURE);
    }
    
    while ((ch = getc(we)) != EOF)
        if (licznik++ % 3 == 0)
            putc(ch, wy);    

    if (fclose(we) != 0 || fclose(wy) != 0)
        fprintf(stderr, "Blad przy zamykaniu plikow.\n");

    return 0;
}