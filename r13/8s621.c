#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define DL 50

void odczyt(FILE *plik, char c, char *arg);

int main(int argc, char *argv[])
{
    FILE  *we;     
    char nazwa[DL];
    
    if (argc < 2)
    {
    	fprintf(stderr, "Za malo argumentow.\n");
    	exit(EXIT_FAILURE);
    }
   	else if (argc == 2)
   	{
   		fprintf(stdout, "Podaj nazwe pliku (enter konczy): ");

   		while (fgets(nazwa, DL, stdin) != NULL && nazwa[0] != '\n')
   		{
   			nazwa[strlen(nazwa) - 1] = '\0';

   			odczyt(we, argv[1][0], nazwa);

        	fprintf(stdout, "Podaj nazwe pliku (enter konczy): ");
   		}
   	}
   	else if (argc > 2)
   		for (int i = 2; i < argc; i++)
   			odczyt(we, argv[1][0], argv[i]);

   	fprintf(stdout, "Koniec!\n");

    return 0;
}

void odczyt(FILE *plik, char c, char *arg)
{
	int licznik = 0;
	int ch;

	if ((plik = fopen(arg, "r")) == NULL)
    {
        fprintf(stderr, "Nie moglem otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(plik)) != EOF)
    	if (ch == c)
    		licznik++;

    fprintf(stdout, "Znak '%c' wystapil w pliku %s %d razy.\n", c, arg, licznik);

    if (fclose(plik) != 0)
		fprintf(stderr,"Blad przy zamykaniu pliku.\n");
}