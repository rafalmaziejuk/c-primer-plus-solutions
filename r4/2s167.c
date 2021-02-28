#include <stdio.h>
#include <string.h>

int main(void)
{
	char imie[10];

	printf("Podaj imie: ");
	scanf("%10s", imie);

	printf("\"%s\".\n", imie);
	printf("\"%20s.\"\n", imie);
	printf("\"%-20s.\"\n", imie);

	int dlugosc = strlen(imie);
	printf("\"%-*s\".\n", dlugosc + 3, imie);

	return 0;
}
