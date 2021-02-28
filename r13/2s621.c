#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *we, *wy;
	int ch;
	
	if (argc < 2)
	{
		fprintf(stderr, "Za malo argumentow.\n");
		exit(EXIT_FAILURE);
	}

	if ((we = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Nie mozna otworzyc %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((wy = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Nie mozna utworzyc %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(we)) != EOF)
		putc(ch, wy);

	fclose(we);
	fclose(wy);
	
	return 0;
}