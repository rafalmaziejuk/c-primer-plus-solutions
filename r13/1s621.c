#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *wp;

	int ch;
	unsigned long licznik = 0;
	char nazwa[10];

	printf("Podaj nazwe pliku: ");
	scanf("%10s", nazwa);

	if ((wp = fopen(nazwa, "r")) == NULL)
	{
		fprintf(stderr, "Nie mozna otworzyc %s\n", nazwa);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(wp)) != EOF)
	{
		putc(ch, stdout);
		licznik++;
	}

	fprintf(stdout, "Plik %s zawiera %lu znakow.\n", nazwa, licznik);	

	fclose(wp);

	return 0;
}