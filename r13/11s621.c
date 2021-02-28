#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DL 255

int main(int argc, char *argv[])
{
    FILE *wp;
    char wiersz[DL];

    if ((wp = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stdin, "Nie moge otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }
    
    while (fgets(wiersz, DL, wp) && wiersz[0] != '\n')
    	if (strstr(wiersz, argv[1]) != NULL)
    		printf("%s", wiersz);

    if (fclose(wp) != 0)
        fprintf(stderr,"Blad przy zamykaniu pliku.\n");

    puts("Gotowe!");

    return 0;
}