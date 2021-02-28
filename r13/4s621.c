#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *we;
	int ch;

	if (argc < 2)
	{
		fprintf(stderr, "Za malo argumentow.\n");
		exit(EXIT_FAILURE);
	}
	
	puts("ZAWARTOSC PODANYCH PLIKOW");
	for (int i = 1; i < argc; i++)
	{
		if ((we = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Nie mozna otworzyc %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}

		putchar('\n');
		printf("Plik numer %d\n", i);
		while ((ch = getc(we)) != EOF)
			putc(ch, stdout);

		fclose(we);
	}

	return 0;
}