#include <stdio.h>

int main(void) 
{
	int liczba, licznik;

	printf("Podaj liczbe calkowita: ");
	scanf("%d", &liczba);

	licznik = liczba + 10;

	while (liczba <= licznik)
		printf("%d ", liczba++);

	return 0;
}