#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIERSZ 20
#define KOLUMNA 30

int main(int argc, char *argv[])
{
    FILE *we, *wy;
    int liczby[WIERSZ][KOLUMNA];
    char znaki[WIERSZ][KOLUMNA + 1];

    if (argc != 3)
    {
    	fprintf(stderr, "Zla ilosc argumentow.\n");
    	exit(EXIT_FAILURE);
    }

    if ((we = fopen(argv[1], "r")) == NULL || (wy = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stdin, "Nie moge otworzyc plikow.\n");
        exit(EXIT_FAILURE);
    }
    
   	for (int y = 0; y < WIERSZ; y++)
   		for (int x = 0; x < KOLUMNA; x++)
   			fscanf(we, "%d", &liczby[y][x]);

   	for (int y = 0; y < WIERSZ; y++)
   	{
   		char ch;

   		for (int x = 0; x < KOLUMNA; x++)
   		{
   			switch (liczby[y][x])
   			{
				case 0:
					ch = ' ';
					break;

				case 1:
					ch = '.';
					break;

				case 2:
					ch = '\'';
					break;

				case 3:
					ch = ':';
					break;

				case 4:
					ch = '~';
					break;

				case 5:
					ch = '*';
					break;

				case 6:
					ch = '=';
					break;

				case 7:
					ch = '}';
					break;

				case 8:
					ch = '&';
					break;

				case 9:
					ch = '#';
					break;

				default:
					fprintf(stderr, "Wystapil blad.\n");
					exit(EXIT_FAILURE);
			}

			znaki[y][x] = ch;
   		}
   			
   		znaki[y][KOLUMNA] = '\0';
   	}

   	for (int y = 0; y < WIERSZ; y++)
   	{
   		for (int x = 0; x < KOLUMNA; x++)
   		{
   			fprintf(stdout, "%c ", znaki[y][x]);
   			fprintf(wy, "%c ", znaki[y][x]);
   		}
   		
   		putchar('\n');
   		putc('\n', wy);
   	}
   		

    if (fclose(we) != 0 || fclose(wy) != 0)
        fprintf(stderr,"Blad przy zamykaniu plikow.\n");

    return 0;
}