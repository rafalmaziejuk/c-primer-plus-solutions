#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROZMIAR_BUF 4096

void dopisz(FILE *zrodlo, FILE *cel);

int main(int argc, char *argv[])
{
    FILE *pd, *pz;    //pd - docelowy, pz - dopisywany
    int pliki = 0; 
    int ch;

    if ((pd = fopen(argv[1], "a")) == NULL)
    {
        fprintf(stderr, "Blad otwarcia %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(pd, NULL, _IOFBF, ROZMIAR_BUF) != 0)
    {
        fputs("Nie mozna utworzyc bufora wyjsciowego\n", stderr);
        exit(EXIT_FAILURE);
    }

    for (int i = 2; i < argc; i++)
    {
    	if (strcmp(argv[1], argv[i]) == 0)
            fputs("Nie mozna dopisac pliku do siebie\n",stderr);
        else if ((pz = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Blad otwarcia pliku %s\n", argv[i]);
        else
        {
            if (setvbuf(pz, NULL, _IOFBF, ROZMIAR_BUF) != 0)
            {
                fputs("Nie mozna utworzyc bufora wejsciowego\n",stderr);
                continue;
            }

            dopisz(pz, pd);

            if (ferror(pz) != 0)
                fprintf(stderr,"Blad odczytu pliku %s\n", argv[1]);

            if (ferror(pd) != 0)
                fprintf(stderr,"Blad zapisu pliku %s\n", argv[i]);

            fclose(pz);
            pliki++;

            printf("Plik %s dopisany.\n", argv[i]);
        }
    }

    printf("Koniec. Dopisano %d plikow.\n", pliki);

    fclose(pd);
    pd = fopen(argv[1], "r");

    printf("%s zawiera:\n", argv[1]);
    while ((ch = getc(pd)) != EOF)
        putchar(ch);

    puts("Koniec.");

    fclose(pd);

    return 0;
}

void dopisz(FILE *zrodlo, FILE *cel)
{
    size_t bajty;
    static char temp[ROZMIAR_BUF];

    while ((bajty = fread(temp, sizeof(char), ROZMIAR_BUF, zrodlo)) > 0)
        fwrite(temp, sizeof (char), bajty, cel);
}