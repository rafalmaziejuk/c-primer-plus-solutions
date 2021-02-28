#include <stdio.h>

int main(void)
{
	char imie[10];
	char nazwisko[10];

	printf("Podaj imie: ");
	scanf("%10s", imie);
	printf("Podaj nazwisko: ");
	scanf("%10s", nazwisko);

	printf("%s, %s\n", nazwisko, imie);

	return 0;
}
