#include <stdio.h>
#include <string.h>

int main(void)
{
	char imie[10];
	char nazwisko[20];

	printf("Podaj imie i nazwisko:\n");
	scanf("%10s %20s", imie, nazwisko);
	printf("\n");

	int dlugosc_imie = strlen(imie);
	int dlugosc_nazwisko = strlen(nazwisko);

	printf("%s %s\n", imie, nazwisko);
	printf("%*d %*d\n", dlugosc_imie, dlugosc_imie, dlugosc_nazwisko, dlugosc_nazwisko);
	printf("\n");

	printf("%s %s\n", imie, nazwisko);
	printf("%-*d %-*d\n", dlugosc_imie, dlugosc_imie, dlugosc_nazwisko, dlugosc_nazwisko);

	return 0;
}
