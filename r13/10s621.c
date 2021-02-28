#include <stdio.h>
#include <stdlib.h>

#define DL 50

int main(void)
{
    FILE *wp;
    int ch;
    char nazwa[DL];
    long miejsce;
    long koniec;

    printf("Podaj nazwe pliku, ktory chcesz otworzyc: ");
    scanf("%50s", nazwa);

    if ((wp = fopen(nazwa, "r")) == NULL)
    {
        fprintf(stdin, "Nie moge otworzyc pliku.\n");
        exit(EXIT_FAILURE);
    }

    fseek(wp, 0L, SEEK_END);
    koniec = ftell(wp);
    
    if (koniec > 0)
    {
    	printf("Podaj miejsce w pliku: ");
	    while (fscanf(stdin, "%lu", &miejsce) && miejsce >= 0)
	    {
	    	if (miejsce > koniec)
	    	{
	    		printf("Za daleko!\n");
	    		printf("Podaj miejsce w pliku: ");
	    		continue;
	    	}

	        fseek(wp, miejsce, SEEK_SET);

	        while ((ch = getc(wp)) != '\n')
	        	putc(ch, stdout);

	        printf("\nPodaj miejsce w pliku: ");
	    }
    }
    else 
    {
    	fprintf(stderr, "Plik pusty!\n");
    	exit(EXIT_FAILURE);
    }

    if (fclose(wp) != 0)
        fprintf(stderr,"Blad przy zamykaniu pliku.\n");

    puts("Gotowe!");

    return 0;
}