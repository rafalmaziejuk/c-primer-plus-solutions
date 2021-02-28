#include <stdio.h>

int main(void)
{
	int licznik, suma;
	int zakres;

	printf("Podaj zakres: ");
	scanf("%d", &zakres);
	printf("\n");

	licznik = 0;
	suma = 0;

	while (licznik++ < zakres)
		suma = suma + licznik * licznik;

	printf("suma = %d\n", suma);

	return 0;
}
