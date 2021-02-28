#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	FILE *we, *wy;
	int ch;
	char nazwa_zrodlo[10];
	char nazwa_wyjscie[10];

	printf("Podaj nazwe pliku zrodlowego: ");
	scanf("%10s", nazwa_zrodlo);

	printf("Podaj nazwe pliku wyjsciowego: ");
	scanf("%10s", nazwa_wyjscie);
	
	if ((we = fopen(nazwa_zrodlo, "r")) == NULL)
	{
		fprintf(stderr, "Nie mozna otworzyc %s\n", nazwa_zrodlo);
		exit(EXIT_FAILURE);
	}

	if ((wy = fopen(nazwa_wyjscie, "w")) == NULL)
	{
		fprintf(stderr, "Nie mozna utworzyc %s\n", nazwa_wyjscie);
		exit(EXIT_FAILURE);
	}

	putchar('\n');
	while ((ch = getc(we)) != EOF)
	{	
		ch = toupper(ch);
		putc(ch, wy);
		putc(ch, stdout);
	}

	fclose(we);
	fclose(wy);

	return 0;
}